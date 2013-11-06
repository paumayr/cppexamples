#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(CustomDeleter)
	{
		struct CloseFileHandler
		{
			void operator()(FILE *fp)
			{
				if (fp != 0)
				{
					fclose(fp);
				}
			}
		};

		template<typename T, typename Deleter>
		struct ResourceHandle
		{
		protected:
			shared_ptr<void> sp;
		public:
			explicit ResourceHandle()
			{
			}

			explicit ResourceHandle(T handle)
			{
				sp = shared_ptr<void>(handle, Deleter());
			}

			 operator T() { return (T)sp.get(); }
			 operator bool() { return sp.operator bool(); }
		};

		ResourceHandle<FILE*, CloseFileHandler> OpenFile()
		{
			FILE *f;
			if (fopen_s(&f, "c:\\temp\\Somefile.txt", "r") == 0)
			{
				return ResourceHandle<FILE*, CloseFileHandler>(f);
			}

			return ResourceHandle<FILE*, CloseFileHandler>();
		}
		
		TEST_METHOD(TestSharedPointerWithCustomDeleter)
		{
			{
				auto someFile = OpenFile();

				if (someFile)
				{
					Logger::WriteMessage("somefile is valid.");
				}

				// closes automatically, even in case of exception
			}
		}
	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
		std::shared_ptr<FILE> OpenFile()
		{
			FILE *f = fopen("c:\\temp\\Somefile.txt", "r");
			if (f != 0)
			{
				return std::unique_ptr<FILE, CloseFileHandler>(f);
			}

			return std::shared_ptr<FILE>();
		}
		
		TEST_METHOD(TestSharedPointerWithCustomDeleter)
		{
			{
				auto shellLink = OpenFile();

				// closes automatically, even in case of exception
			}
		}
	};
}
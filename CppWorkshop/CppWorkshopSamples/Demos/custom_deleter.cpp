#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(CustomDeleter)
	{
		static void CloseFileHandler(FILE *fp)
		{
			if (fp != 0)
			{
				fclose(fp);
			}
		};

		std::shared_ptr<FILE*> OpenFile()
		{
			FILE *f;
			if (fopen_s(&f, "c:\\temp\\Somefile.txt", "r") == 0)
			{
				return std::shared_ptr<FILE*>(f, CloseFileHandler);
			}

			return std::shared_ptr<FILE*>(nullptr, CloseFileHandler);
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
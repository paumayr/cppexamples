#include "stdafx.h"
#include "CppUnitTest.h"

#include "boost/filesystem.hpp"
#include <iostream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Demo_Boost
{
	TEST_CLASS(FileSystem)
	{
	public:

		TEST_METHOD(TestFileSystemAPI)
		{
			using namespace std;
			using namespace boost;

			// create a directory
			auto dir =  filesystem::current_path() / "folder" / "to" / "create";
			filesystem::create_directories(dir);

			// path to a file
			filesystem::path file = dir / "file.txt";
		
			Assert::IsFalse(filesystem::exists(file));

			// create a file
			ofstream f(file.string());
			f << "some lines from my filesystem test";
			f.close();

			Assert::IsTrue(filesystem::exists(file));

			// copy the file somewhere else
			filesystem::copy_file(file, dir / "file2.txt");

			// check the file size
			Assert::IsTrue(34ul == filesystem::file_size(file));

			vector<filesystem::path> paths;
			copy(filesystem::directory_iterator(dir), 
				filesystem::directory_iterator(), 
				back_inserter(paths));
			
			Assert::IsTrue(2 == paths.size());

			// remove the directory, even if not empty.
			filesystem::remove_all(filesystem::current_path() / "folder");
		}
	};
}
#include "stdafx.h"
#include "CppUnitTest.h"

#include <fstream>
#include <future>
#include <filesystem>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


TEST_CLASS(TestAsync)
{
	/*
	Async file reading on worker thread.
	*/
	static string ReadContent(string filename)
	{
		ifstream in(filename);

		string content((istreambuf_iterator<char>(in)),
			(istreambuf_iterator<char>()));

		return content;
	}

	static void WriteContent(string fileName, string content)
	{
		ofstream out(fileName);
		out << content;
	}

	TEST_METHOD(TestAsyncFileRead)
	{
		WriteContent("file1.txt", "File 1 Content");
		WriteContent("file2.txt", "File 2 Content");

		auto file1 = async(ReadContent, "file1.txt");
		auto file2 = async(ReadContent, "file2.txt");

		// do something else...

		// block until result is done
		auto file1Content = file1.get();
		auto file2Content = file2.get();

		Assert::AreEqual(string("File 1 Content"), file1Content);
		Assert::AreEqual(string("File 2 Content"), file2Content);
	}

	static void someoperation(string msg)
	{
		using namespace std::chrono;
		this_thread::sleep_for(seconds(10));
		Logger::WriteMessage(msg.c_str());
	}

	TEST_METHOD(TestSomeOperationAsync)
	{
		auto f1 = async(someoperation, "1");
		auto f2 = async(someoperation, "2");
	}

	/*
	Exception in async operation is launched.
	*/
	static void throwsException()
	{
		//..... do something
		// at some point an exception is thrown
		throw std::exception("something bad happened.");
	}

	TEST_METHOD(TestAsyncThrowException)
	{
		auto future = async(throwsException);

		using namespace std::chrono;
		this_thread::sleep_for(seconds(5));

		try
		{
			future.wait();
			Assert::Fail();
		}
		catch (std::exception ex)
		{
			Assert::AreEqual("something bad happened.", ex.what());
		}
	}

	/*
	future from a promise
	*/
	TEST_METHOD(TestPromise)
	{
		promise<int> my_promise;

		auto future_of_promise = my_promise.get_future();

		// at later pointer (e.g. event handled, etc.), set result of promise
		my_promise.set_value(42);

		// somewhere else, read the result of the future
		Assert::AreEqual(42, future_of_promise.get());
	}

	TEST_METHOD(TestPromiseException)
	{
		promise<int> my_promise;

		auto future_of_promise = my_promise.get_future();

		my_promise.set_exception(make_exception_ptr(exception("something bad happened.")));

		try
		{
			future_of_promise.get();
			Assert::Fail();
		}
		catch (exception ex)
		{
			Assert::AreEqual("something bad happened.", ex.what());
		}
	}

	TEST_METHOD(TestPromiseExceptionTryCatch)
	{
		promise<int> my_promise;

		auto future_of_promise = my_promise.get_future();

		// at some point, set the exception
		try
		{
			// at some point, an exception is raised.
			throw exception("something bad happened.");
		}
		catch (...)
		{
			my_promise.set_exception(current_exception());
		}


		// ... at the point, where the future is handled... catch the exception
		try
		{
			future_of_promise.get();
			Assert::Fail();
		}
		catch (exception ex)
		{
			Assert::AreEqual("something bad happened.", ex.what());
		}
	}

	/*
	promise with custom worker thread
	*/
	TEST_METHOD(TestPromiseWorkerThread)
	{
		promise<int> prom;

		thread t([&]() {
			int result = 0;
			for (int i = 1; i <= 100; i++) result += i;

			prom.set_value(result);
		});

	
		auto future = prom.get_future();

		// wait for value
		Assert::AreEqual(5050, future.get());

		// join thread for correctness.
		t.join();
	}

	/*
	shared future
	*/
	TEST_METHOD(TestSharedFutureMotivation)
	{
		auto my_future = async([]() { return 42; });

		// get() may only be called exactly once
		Assert::AreEqual(42, my_future.get());

		Assert::IsFalse(my_future.valid());

		try
		{
			my_future.get();
			Assert::Fail();
		}
		catch (exception e)
		{
		}

		Assert::IsFalse(my_future.valid());
	}

	TEST_METHOD(TestSharedFuture)
	{
		auto my_future = async([]() { return 42; });

		auto my_shared_future = my_future.share();

		Assert::IsFalse(my_future.valid());

		Assert::AreEqual(42, my_shared_future.get());

		// can be called multiple times
		Assert::AreEqual(42, my_shared_future.get());
		Assert::AreEqual(42, my_shared_future.get());
	}

	/*
	packaged_tasks
	*/
	TEST_METHOD(TestPackagedTask)
	{
		// note template parameter: int()
		packaged_task<int()> task{ []() { return 42; } };

		// get the future from the task
		auto future_of_task = task.get_future();

		// run the task, note task does not return a valu!e
		// packaged_task always fowards to future
		task();

		Assert::AreEqual(42, future_of_task.get());
	}
};
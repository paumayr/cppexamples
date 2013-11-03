#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(Threading)
	{
		static void worker_thread() {
			// do something.
		}

		TEST_METHOD(TestCreatingAndJoiningThreads)
		{
			thread t0(worker_thread);
			thread t1(worker_thread);

			// do something else.


			// join worker threads
			t0.join();
			t1.join();
		}

		static void worker_thread_2(int number, mutex &m, vector<int>& results)
		{
			for (int i = 0; i < number; i++)
			{
				lock_guard<mutex> l(m);
				results.push_back(i);
			}
		}

		TEST_METHOD(TestLockGuard)
		{
			mutex m;

			vector<int> results;

			thread t0(worker_thread_2, 100, ref(m), ref(results));
			thread t1(worker_thread_2, 100, ref(m), ref(results));

			t0.join();
			t1.join();

			Assert::AreEqual(200u, results.size());
		}

		/*
		test condition variable
		*/
		static void worker_thread_3(mutex &m, std::queue<int> input, std::queue<int> output)
		{
			{

			}
		}

		TEST_METHOD(TestConditionVariable)
		{

		}
	};
}
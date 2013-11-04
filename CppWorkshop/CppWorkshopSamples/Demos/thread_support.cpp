#include "stdafx.h"
#include "CppUnitTest.h"
#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>
#include <future>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(ThreadSupport)
	{

		static void worker_count_to_100_manual(mutex &m, int &variable)
		{
			for (int i = 0; i < 100; i++)
			{
				m.lock();
				variable++;
				m.unlock();
			}
		}

		static void worker_count_to_100_unique_lock(mutex &m, int &variable)
		{
			for (int i = 0; i < 100; i++)
			{
				unique_lock<mutex> lock(m);
				variable++;
			}
		}

		TEST_METHOD(TestMutexAndLocks)
		{
			vector<future<void>> v;

			int variable = 0;
			mutex m;

			for (int t = 0; t < 1000; t++)
			{
				//v.emplace_back(async(worker_count_to_100_manual, ref(m), ref(variable)));
				v.emplace_back(async(worker_count_to_100_unique_lock, ref(m), ref(variable)));
			}

			// wait until all futures have computed
			for (auto &t : v)
			{
				t.wait();
			}

			Assert::AreEqual(1000 * 100, variable);
		}

		/*
		Show use of condition variable for inter-thread communication
		*/
		// poor-man's thread-safe queue.
		static void square_root_worker(mutex& input_mutex, condition_variable &input_cv, queue<double> &input, 
										mutex& output_mutex, condition_variable &output_cv, queue<double> &output)
		{
			double toProcess = 0.0;
			
			do
			{
				// wait for next input
				{
					unique_lock<mutex> l(input_mutex);
					if (input.size() == 0)
					{
						input_cv.wait(l, [&] { return input.size() > 0; });
					}

					toProcess = input.front();
					input.pop();
				}

				// process the item
				double result = toProcess >= 0.0 ? sqrt(toProcess) : -1;

				// write back the result
				{
					unique_lock<mutex> l(output_mutex);
					output.push(result);
					output_cv.notify_one();
				}

			} while (toProcess >= 0.0);
		}

		TEST_METHOD(TestConditionVariable)
		{
			mutex input_mutex;
			mutex output_mutex;
			condition_variable input_cv;
			condition_variable output_cv;
			queue<double> inputQueue;
			queue<double> outputQueue;

			vector<double> results;

			thread worker_thread(square_root_worker, 
									ref(input_mutex), ref(input_cv), ref(inputQueue), 
									ref(output_mutex), ref(output_cv), ref(outputQueue));

			{
				for (auto x : { 9.0, 16.0, 25.0, 36.0, 49.0, 64.0, 81.0, -1.0 })
				{
					unique_lock<mutex> l(input_mutex);
					inputQueue.push(x);
					input_cv.notify_one();
				}

				double result = 0.0;
				while (result >= 0.0)
				{
					unique_lock<mutex> l(output_mutex);
					if (outputQueue.size() == 0)
					{
						output_cv.wait(l, [&]() { return outputQueue.size() > 0; });
					}

					result = outputQueue.front();
					outputQueue.pop();

					if (result >= 0)
					{
						results.push_back(result);
					}
				}
			}

			// wait for the worker thread to join -> exception otherwise
			worker_thread.join();

			vector<double> expected = { 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
			Assert::IsTrue(expected == results);
		}
	};
}
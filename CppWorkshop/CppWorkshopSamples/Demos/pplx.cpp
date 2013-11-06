
#include "stdafx.h"
#include "CppUnitTest.h"

#include <ppl.h>
#include <ppltasks.h>
#include <algorithm>
#include <fstream>
#include <thread>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace concurrency;


namespace detail
{
	class Line : public std::string
	{
		friend std::istream & operator>>(std::istream & is, Line & line)
		{
			return std::getline(is, line);
		}
	};
}

TEST_CLASS(TestPPL)
{
	TEST_METHOD(TestParallelTransform)
	{
		vector<double> a(1000);
		fill(begin(a), end(a), 10.0);
		
		parallel_transform(begin(a), end(a), begin(a), [](double &x) { return x * 2.0; });
		Assert::IsTrue(all_of(begin(a), end(a), [](double &x) { return x == 20.0; }));
	}

	TEST_METHOD(TestParallelReduce)
	{
		vector<double> a(1000);
		fill(begin(a), end(a), 10.0);

		auto reduced = parallel_reduce(begin(a), end(a), 0.0, [](double & last, double &cur) { return last + cur; });
		Assert::AreEqual(1000.0 * 10.0, reduced);
	}

	TEST_METHOD(TestCreateTask)
	{
		auto t1 = create_task([]{ return string("Hello From Task"); });
		auto t2 = create_task([]{ return string("Hello From Task"); });
		auto t3 = create_task([]{ return string("Hello From Task"); });

		auto allTasks = { t1, t2, t3 };
		auto join_task = when_all(begin(allTasks), end(allTasks));

		Assert::IsTrue(all_of(begin(allTasks), end(allTasks),
			[](const task<string>& x) { return x.get() == string("Hello From Task"); }));
	}

	static string ReadContent(string filename)
	{
		ifstream in(filename);

		string content((istreambuf_iterator<char>(in)),
			(istreambuf_iterator<char>()));

		return content;
	}

	TEST_METHOD(TestContinuation)
	{
		auto task = create_task([] { return ReadContent("c:\\temp\\somefile.txt"); })
			.then([] (string prev) {
			stringstream ss(prev);
			
			static string prefix = "REM";

			vector<string> goodLines;
			typedef std::istream_iterator<detail::Line> InIt;
			copy_if(InIt(ss), InIt(), back_inserter(goodLines), 
				[](const string &line){ return line.substr(0, prefix.size()) != prefix; });

			return goodLines;
		}).then([](vector<string> pref) {
			//.....
		});


		task.get();
	}

	TEST_METHOD(TestCancellation)
	{
		cancellation_token_source cancellationTokenSource;
		auto token = cancellationTokenSource.get_token();

		auto t1 = create_task([&token] {

			token.register_callback([]() { Logger::WriteMessage("Cancelling...\n"); });

			while (!token.is_canceled()) {
				Logger::WriteMessage("Sleeping...\n");
				this_thread::sleep_for(chrono::seconds(1));
			}

			Logger::WriteMessage("Finishing Task\n");
		});

		this_thread::sleep_for(chrono::seconds(10));

		cancellationTokenSource.cancel();

		t1.get();
	}
};
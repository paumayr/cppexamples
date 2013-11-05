#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <varargs.h>
#include <future>
#include <thread>
#include <chrono>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void old_style()
{
	vector<pair<string, string> > phone_book;
	phone_book.push_back(pair<string, string>("Scott", "Meyers"));
	phone_book.push_back(pair<string, string>("Andrei", "Alexandrescu"));
	phone_book.push_back(pair<string, string>("Herb", "Sutter"));
	phone_book.push_back(pair<string, string>("Bjarne", "Stroustrup"));
	phone_book.push_back(pair<string, string>("Sean", "Parent"));

	// find a specific element
	vector<pair<string, string> >::const_iterator pos;
	for (pos = phone_book.cbegin();
		pos != phone_book.cend();
		pos++)
	{
		if (pos->first == "Scott")
			break;
	}

	// create another instance of the iterator.
	vector<pair<string, string> >::const_iterator other;
}

struct matches_first_name
{
	string name;
	matches_first_name(string n) : name(n) {};
	bool operator()(const pair<string, string> &x) const {
		return x.first == name;
	}
};

void newer_style()
{
	vector<pair<string, string> > phone_book;
	phone_book.push_back(pair<string, string>("Scott", "Meyers"));
	/**/
	phone_book.push_back(pair<string, string>("Sean", "Parent"));

	// find a specific element
	vector<pair<string, string> >::const_iterator pos;
	pos = find_if(phone_book.cbegin(), phone_book.cend(), matches_first_name("Scott"));

	// create another instance of the iterator.
	vector<pair<string, string> >::const_iterator other;
}

void more_newer_style()
{
	vector<pair<string, string>> phone_book
	{
		{ "Scott", "Meyers" }, { "Andrei", "Alexandrescu" },
		{ "Herb", "Sutter" }, { "Bjarne", "Stroustrup" },
		{ "Sean", "Parent" },
	};

	// find a specific element
	auto pos = find_if(phone_book.cbegin(), phone_book.cend(),
		[](const pair<string, string> &x) { return x.first == "Scott"; });

	// create another instance of the iterator.
	decltype(pos) other;
}

void foreach_old()
{
	vector<int> v;
	for (int i = 0; i < 10; i++) v.push_back(i);

	int sum = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		sum += *it;
	}
}

void foreach_new()
{
	vector<int> v;
	for (int i = 0; i < 10; i++) v.push_back(i);

	int sum = 0;
	for (auto x : v)
	{
		sum += x;
	}
}

class widget
{
	int width, height;
public:
	widget(int w, int h) :width(w), height(h) { }
	/*...*/
};

void smartpointer_old()
{
	shared_ptr<widget> widgetptr = shared_ptr<widget>(new widget(10, 20));
	unique_ptr<widget> widget2ptr = unique_ptr<widget>(new widget(10, 20));
}

void smartpointer_new()
{
	auto widgetptr = make_shared<widget>(10, 20);
	auto widget2ptr = make_unique<widget>(10, 20);
}

static vector<pair<string, string>> read_phonebook_new()
{
	decltype(read_phonebook_new()) result;

	while (!cin.eof())
	{
		string first, last;
		cin >> first >> last;
		result.emplace_back(make_pair(first, last));
	}

	return result;
}

void use_read_phonebook_new()
{
	const auto result = read_phonebook_new();
	auto contains = result[0] == pair<string, string>("Scott", "Meyers");
	// ...
}

static void read_phonebook_old(vector<pair<string, string> >& target)
{
	while (!cin.eof())
	{
		string first, last;
		cin >> first >> last;

		target.emplace_back(pair<string, string>(first, last));
	}
}



void use_read_phonebook_old()
{
	vector<pair<string, string> > result;
	read_phonebook_old(result);
	auto contains = result[0] = pair<string, string>("Scott", "Meyers");
	// ...
}


void my_vararg_function_old(...)
{
	/*
	I don't remember how to write this!
	but it was ugly, unsafe and slow (by comparison).
	*/
}

void use_vararg_old()
{
	my_vararg_function_old("asdf", 10, 30, 4.0f);
}

// case for calling without arguments
void my_vararg_function_new()
{
}

template<typename Head, typename... Args>
void my_vararg_function_new (Head h, Args... args)
{
	// do something with h
	cout << h;

	// expand arguments; calling self with one argument less
	my_vararg_function_new(args...);
}

void use_vararg_new()
{
	my_vararg_function_new("asfd", 10, 30, 4.0f);
}

class AOld
{
	int withDefaultValue, classicVariable;
public:
	AOld(int classic) : withDefaultValue(10), classicVariable(classic) {}

	virtual void myfunction() {}

	// hide the default constructor
private:
	AOld();
};

class BOld : public AOld
{
public:
	BOld(int classic) : AOld(classic) {};

	// should override AOld::myfunction, but doesn't because of typeo :/
	virtual void myFunction() {};
};

class A
{
	int withDefaultValue = 10, classicVariable;
public:

	A(int classic) : classicVariable(classic) {};

	virtual void myfunction() {};

	// delete the default constructor
	A() = delete;

	// set the copy-constructor to default (redundant)
	A(const A & x) = default;
};

class B : public A
{
public:
	B(int classic) : A(classic) {};

	// overrides A::myfunction. Errors if it can't override.
	virtual void myfunction() override
	{
	}
};

	static string Get(string url)
	{
		this_thread::sleep_for(std::chrono::seconds(url.size()));
		/* implementation omitted */
		return "content from " + url;
	}

	static void launch_async()
	{
		auto search1 = async([]() { return Get("http://www.google.com/index.html"); });
		auto search2 = async([]() { return Get("http://www.bing.com/index.html"); });
		auto search3 = async([]() { return Get("http://www.yahoo.com/index.html"); });

		// do something, run UI thread, etc.

		// get blocks until download is done.
		auto c1 = search1.get();
		auto c2 = search2.get();
		auto c3 = search3.get();
	}


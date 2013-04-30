// VC2012CTP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void saveprint()
{
	cout << endl;
}

template<typename Head, typename... Tail>
void saveprint(Head head, Tail... args)
{
	cout << head << " ";
	saveprint(args...);
}

int main()
{
	saveprint(10, "hello", "world", 30.0f);
}


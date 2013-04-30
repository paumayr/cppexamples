#include "stdafx.h"
#include <iostream>

using namespace std;

	class Person {
	public:
		virtual void print() { cout << "some person" << endl; }
	};

	class Employee : Person {
	public:
		virtual void print() override { cout << "an employee" << endl;	}
	};

	class Student : Person {
	public:
		virtual void print() override final	{ cout << "a student" << endl; }
	};
	/*
	class FirstGrader : Student {
	public:
		virtual void print() override { cout << "a first grader" << endl; }
	};*/
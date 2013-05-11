#pragma once

class Base
{
protected:
	int baseMember;
public:

	Base(int baseMember);
	~Base();

	virtual void print();
};
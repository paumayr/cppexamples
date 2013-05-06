#pragma once

class Base
{
	int baseMember;
public:
	
	Base(int baseMember);
	virtual ~Base();

	int getBaseMember() const;

	virtual void print();
};
#pragma once

class AnotherBase
{	
protected:
	int anotherBaseMember;
public:

	AnotherBase(int anotherBaseMember);
	~AnotherBase();

	virtual void scan();
};
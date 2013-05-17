#pragma once

class IDoSomething
{
public:
	virtual ~IDoSomething() {};
	virtual void PrintSomething() = 0;
};

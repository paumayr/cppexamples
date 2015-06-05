#include "stdafx.h"


class Base
{
public:
	virtual void VirtualMethod() = 0;
};

class AnotherBase
{
public:
	virtual void SomeOtherVirtualMethod() = 0;
};

class Derived : public Base, public AnotherBase
{
public:

	void SomeOtherMethod()
	{
	}

	void SomeMethod()
	{
	}

	virtual void VirtualMethod()
	{
	}

	virtual void SomeOtherVirtualMethod()
	{
	}
};

class OtherDerived : public Base, public AnotherBase
{
public:
	void SomeMethod()
	{
	}

	virtual void VirtualMethod()
	{
	}

	virtual void SomeOtherVirtualMethod()
	{
	}
};

void constCastMethod(const Base * const base)
{
	Base *unconstBase = const_cast<Base*>(base);
	unconstBase->VirtualMethod();
}

void callMethod(Base *base)
{
	Derived *derived = dynamic_cast<Derived*>(base);

	if (derived != nullptr)
	{
		derived->SomeMethod();
	}
	else
	{
		// Log: "got instance of unexpected type, expected Derived instead...."
	}
}

void SomeMethodTakingVoid(void *somepointer)
{
	AnotherBase* pAnother = static_cast<AnotherBase*>(somepointer);
	pAnother->SomeOtherVirtualMethod();
}

void SomeMethodTakingInt(int myAddress)
{
	Base* derived = reinterpret_cast<Base*>(myAddress);
	derived->VirtualMethod();
}

TEST_CLASS(TestCasting)
{
public:
	TEST_METHOD(TestCasts)
	{
		Derived * pDerived = new Derived();
		Base *pBase = pDerived;
		AnotherBase * anotherBase = pDerived;

		void* pWhatever = pDerived;
		SomeMethodTakingVoid(pWhatever);

		// Do not do this, just for an example of reinterpret_cast
		int myAddress = (int)pDerived;
		SomeMethodTakingInt(myAddress);

		callMethod(pBase);
	}
};
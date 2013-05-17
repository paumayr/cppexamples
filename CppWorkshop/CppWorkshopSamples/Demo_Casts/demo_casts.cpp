

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
		// Log: got unexpected..
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

typedef void (*Func)(int, int);

int main(int argc, char **argv)
{
	int i = 12;

	Derived * pDerived = new Derived();
	Base *pBase = pDerived;
	AnotherBase * anotherBase = pDerived;

	void* pWhatever = pDerived;
	SomeMethodTakingVoid(pWhatever);

	int myAddress = (int)pDerived;
	SomeMethodTakingInt(myAddress);

	callMethod(pBase);

	unsigned int w = 3000000000;
	unsigned int h = 200;
	unsigned int *pData = nullptr; //read();
	unsigned int *pTarget = nullptr; 

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			pTarget[i * w + j] = pData[i * w + j];
		}
	}
	
	return 0;
}
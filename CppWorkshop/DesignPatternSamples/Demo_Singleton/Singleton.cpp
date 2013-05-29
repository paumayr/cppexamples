#include "Singleton.hpp"

Singleton* Singleton::instance = 0;

Singleton::Singleton()
	: someSharedResource(0)
{
}

Singleton::~Singleton()
{
}

Singleton * Singleton::Instance()
{
	if (instance == 0)
	{
		instance = new Singleton();
	}

	return instance;
}

void Singleton::accessSharedResource()
{
	someSharedResource++;
}

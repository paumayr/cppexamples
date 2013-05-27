#pragma once

class Singleton
{
public:
	Singleton();
	virtual ~Singleton();

	static Singleton * Instance();

	void accessSharedResource();

private:
	static Singleton * instance;

	int someSharedResource;
};
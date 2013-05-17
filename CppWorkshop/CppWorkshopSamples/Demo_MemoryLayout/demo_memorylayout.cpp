#include <iostream>
#include <string>

class IPrinter
{
protected:
	int printCount;
public:
	virtual void Print(std::string text) = 0; 
};

class IScanner
{
protected:
	int scanCount;
public:
	virtual std::string Scan() = 0;
};

class MultiFunctionDevice : public IPrinter, public IScanner
{
public:
	virtual void Print(std::string text)
	{
		printCount++;
	}

	virtual std::string Scan()
	{
		scanCount++;
		return "Some Scanned Text";
	}
};

void multifunctiondevicememorylayout()
{
	MultiFunctionDevice *mfd = new MultiFunctionDevice;
	IPrinter *printer = mfd;
	IScanner *scanner = mfd;

	delete mfd;
}


/**********************************************
Single Inheritance
**********************************************/

class AbstractShape
{
public:
	virtual void Draw() = 0;
};

class Rectangle : public AbstractShape
{
public:
	int x, y;
	int width; int height;
	virtual void Draw()
	{
		std::cout << "drawing rectangle (" << x << ", " << y << ", " << width << ", " << height << ")" << std::endl;
	}
};

void rectanglememorylayout()
{
	Rectangle *p = new Rectangle();
	delete p;
}

/***********************************************
Nested classes
***********************************************/
class Person
{
public:
	std::string firstName;
	std::string lastName;
};

void personmemorylayout()
{
	Person *p = new Person;

	delete p;
}

/*************************************************
primitve members
************************************************/

class Vector3f
{
public:
	float x;
	float y;
	float z;
};

void vectormemorylayout()
{
	Vector3f a;
	Vector3f *pA = new Vector3f;

	delete pA;
}

int main(int argc, char **argv)
{
	vectormemorylayout();
	personmemorylayout();
	rectanglememorylayout();
	multifunctiondevicememorylayout();
	return 0;
}


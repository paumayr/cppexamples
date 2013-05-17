#include <iostream>
#include <vector>

#define DO(i,min,max) for(int i = min; i < max; ++i)

#define FOREACH(collection, call) \
	for(decltype(collection.begin()) it = begin(collection); \
	    it != end(collection); ++it) \
	{ \
	   (*it).call;\
	}

// #define MAX_BUFFER_LENGTH 10
#ifndef MAX_BUFFER_LENGTH
#define MAX_BUFFER_LENGTH 100
#else
#if MAX_BUFFER_LENGTH < 100
#error MAX_BUFFER_LENGTH must be at least 100
#endif
#endif


class Element
{
public:
	void print() 
	{
	};
};

int main(int argc, char **argv)
{
	DO(counter, 0, 100) {
		std::cout << "loop-di-loop" << std::endl;
	}

	std::vector<Element> numbers;

	FOREACH(numbers, print());
}
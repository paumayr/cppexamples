#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
	using namespace std;
	vector<int> container;

	// fill vector with elements to play with.
	container.push_back(10);
	container.push_back(20);
	container.push_back(20);
	container.push_back(30);
	container.push_back(40);

	// get an iterator to the first element
	vector<int>::iterator iterator1 = begin(container);

	// Invalid: if (iterator == 10) iterator has to be dereferenced to provide the value
	if (*iterator1 == 10)
	{
		cout << "value pointed to by iterator is " << *iterator1 << endl;
	}

	// move iterator to next element.
	iterator1++;

	cout << "value pointed to by iterator is " << *iterator1 << endl;

	// get another iterator, thanks to c++11 auto this is much shorter
	auto iterator2 = begin(container);

	// move iterator2 forward by 2 units (only for random access iterators!)
	iterator2 += 2;

	// compare two iterators (iterator points to the second, iterator2 to the third element)
	if (iterator1 != iterator2)
	{
		cout << "iterator1 != iterator2" << endl;
	}

	// compare the values referenced by the iterators
	if (*iterator1 == *iterator2)
	{
		cout << "*iterator1 == *iterator2 (" << *iterator1 << " = " << *iterator2 << ")" << endl;
	}

	// compare iterators (random access only)
	if (iterator1 < iterator2)
	{
		cout << "iterator1 < iterator2" << endl;
	}

	if (iterator2 > iterator1)
	{
		cout << "iterator2 > iterator1" << endl;
	}

	// end() of a container points to an element behind the last element
	auto iterator3 = begin(container) + 4;
	if (*iterator3 == 40)
	{
		cout << "iterator3 == 40" << endl;
	}

	if (iterator3 != end(container))
	{
		cout << "iterator3 != container.end()" << endl;
	}

	// behavior deriving end() is undefined, will lead to a runtime assertion in debug
	// will assert: *container.end();

	// iterate all elements in a container (note: C++11 support a foreach loop for this specifically)
	for(auto it = begin(container); it != end(container); it++)
	{
		cout << "element: " << *it << endl;
	}

	// iterate all elements, c++11 style
	for(auto x : container)
	{
		cout << "element: " << x;
	}

	return 0;
}
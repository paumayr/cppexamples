
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
	using namespace std;

	vector<int> v;
	v.reserve(10);
	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// find an iterator to the element to remove
	auto three = find(begin(v), end(v), 3);

	// erease the iterator position
	v.erase(three);
	
	// remove all even elements from the range. Does not change std::vector!
	auto newEnd = remove_if(begin(v), end(v), [](int x) { return x % 2 != 0; });

	// erase the elements
	v.erase(newEnd, end(v));

	// of course, we can directly forward the newEnd parameter -> C++ remove-erase idiom
	v.erase(remove_if(begin(v), end(v), [](int x) { return x % 2 == 0; }), end(v));

	if (v.size() == 0)
	{
		cout << "v is empty" << endl;
	}
}
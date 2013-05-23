
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);

	// index operator, just as a normal array would do
	std::cout << arr[1] << std::endl;
	arr[1] = 22;

	// can take the pointer to an element
	// pointer remains valid as long as vector is not modified!
	int *pElem = &arr[1];
	*pElem = 23;

	// bounds-checked at
	std::cout << arr.at(2) << std::endl;

	for_each(begin(arr), end(arr), 
		[](int x) { cout << x << endl; });
	
	std::cin.get();
	return 0;
}
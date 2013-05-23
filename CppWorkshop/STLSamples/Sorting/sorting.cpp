
#include <algorithm>
#include <vector>
#include <iostream>

std::ostream& operator<<(std::ostream &stream, std::vector<int> &v)
{
	for(auto x : v) stream << x << ", ";
	return stream;
}

int main(int argc, char **argv)
{
	using namespace std;

	vector<int> v;
	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// shuffle the elements.
	random_shuffle(begin(v), end(v));
	cout << "randomized: " << v << endl;

	// sort (default ascending)
	sort(begin(v), end(v));
	cout << "sorted, ascending: " << v << endl;

	// sorted descending
	sort(begin(v), end(v), [](int lh, int rh) { return lh > rh; });
	cout << "sorted, descending: " << v << endl;

	return 0;
}
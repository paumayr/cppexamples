#include <vector>
#include <future>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

using namespace std;
void CppAmpMethod();
void TestMatrixAmp();

float performWork(const vector<float> &ca, const vector<float> &cb, vector<float> &sum, int size)
{
	float redux = 0.0;
	// #pragma loop(no_vector)
	for (int i = 0; i < size; i++)
	{
		sum[i] = sqrtf((ca[i] + cb[i]) * (ca[i] + cb[i])) / 2.0f;
	}

	return redux;
}


void perfTest()
{
	const int size = 100000;

	auto a = vector<float>(size);
	auto b = vector<float>(size);
	auto sum = vector<float>(size);

	for (int i = 0; i < size; i++)
	{
		a[i] = i * 2.0f;
		b[i] = i * 0.5f;
	}
	
	//#pragma loop(hint_parallel(2))
	//#pragma loop(ivdep)
	#pragma loop(hint_parallel(0))
	for (int i = 0; i < size; i++)
	{
		performWork(a, b, sum, size);
	}

	cout << "sum is : " << sum[13] << endl;
}

void runPerfTest()
{
	perfTest();

	auto start = std::chrono::high_resolution_clock::now();

	perfTest();

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "code took: " <<  elapsed.count() << "ms" << std::endl;
}

void printCollectionSizes()
{
	using namespace std;
	cout << "sizeof(vector<int>) is " << sizeof(vector<int>) << endl;
	cout << "sizeof(unordered_set<string>) is " << sizeof(unordered_set<std::string>) << endl;
	cout << "sizeof(unordered_map<string, string>) is " << sizeof(unordered_map<string, string>) << endl;
}



int main(int argc, char**argv)
{
	using namespace std;

	runPerfTest();
	//printCollectionSizes();

	//CppAmpMethod();

	//TestMatrixAmp();

	std::cin.get();
}


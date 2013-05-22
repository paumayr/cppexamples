#include <vector>
#include <future>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void CppAmpMethod();
void TestMatrixAmp();

float performWork(const float *ca, const float *cb, int size)
{
	float redux = 0.0;
	#pragma loop(no_vector)
	for (int i = 0; i < size; i++)
	{
		float x = (ca[i] + cb[i]) / 2.0f;
			
		redux += x;
	}

	return redux;
}


void perfTest()
{
	using namespace std;
	const int size = 100000;

	float *a = new float[size];
	float *b = new float[size];
	float *sum = new float[size];

	for (int i = 0; i < size; i++)
	{
		a[i] = i * 2.0f;
		b[i] = i * 0.5f;
	}

	//#pragma loop(hint_parallel(4))
	//#pragma loop(ivdep)
	#pragma loop(hint_parallel(0))
	for(int i = 0; i < size; i++)
	{
		sum[i] = performWork(a, b, size);
	}

	delete[] a;
	delete[] b;

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


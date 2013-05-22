#include <amp.h>
#include <iostream>
#include <functional>

using namespace concurrency;

const int size = 5;

void CppAmpMethod() {
	int aCPP[] = {1, 2, 3, 4, 5};
	int bCPP[] = {6, 7, 8, 9, 10};
	int sumCPP[size] = {0, 0, 0, 0, 0};
    
	// Create C++ AMP objects.
	array_view<const int, 1> a(size, aCPP);
	array_view<const int, 1> b(size, bCPP);
	array_view<int, 1> sum(size, sumCPP);
	sum.discard_data();

	parallel_for_each(
		// Define the compute domain, which is the set of threads that are created.
		sum.extent, 
		// Define the code to run on each thread on the accelerator.
		[=](index<1> idx) restrict(amp) 
		{
			sum[idx] = a[idx] + b[idx];
		}
	);

	// Print the results. The expected output is "7, 9, 11, 13, 15".
	for (int i = 0; i < size; i++) {
		std::cout << sum[i] << "\n";
	}
}

void MatrixMultiplySerial(std::vector<float>& vC, 
		const std::vector<float>& vA, 
		const std::vector<float>& vB, int M, int N, int W)
{
	for (int row = 0; row < M; row++) 
	{
	for (int col = 0; col < N; col++)
	{
		float sum = 0.0f;
		for(int i = 0; i < W; i++)
		sum += vA[row * W + i] * vB[i * N + col];
		vC[row * N + col] = sum;
	}
	}
}

 void MatrixMultiplySimple(std::vector<float>& vC, 
			const std::vector<float>& vA, 
			const std::vector<float>& vB, int M, int N, int W)
{
	array_view<const float,2> a(M, W, vA);
	array_view<const float,2> b(W, N, vB);
	array_view<float,2> c(M, N, vC); c.discard_data();
	parallel_for_each(c.extent, 
		[=](concurrency::index<2> idx) restrict(amp) {
			int row = idx[0]; int col = idx[1];
			float sum = 0.0f;
			for(int i = 0; i < W; i++)
				sum += a(row, i) * b(i, col);
			c[idx] = sum;
		}
	);
}

 std::chrono::milliseconds measure(std::function<void ()> func)
 {
	func();

	auto start = std::chrono::high_resolution_clock::now();

	func();

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return elapsed;
 }

void TestMatrixAmp()
{
	int width = 1024;
	int height = 1024;

	std::vector<float> lh(width * height);
	std::vector<float> rh(width * height);

	// fill with some whatever numbers (demo only!)
	for(int i = 0; i < width * height; i++)
	{
		lh.push_back(i * 2.0f);
		rh.push_back(i * 4.0f);
	}

	std::vector<float> multed(width * height);

	auto serial = measure([&]() { MatrixMultiplySerial(multed, lh, rh, width, height, width); });
	auto amp = measure([&]() { MatrixMultiplySimple(multed, lh, rh, width, height, width); });

	std::cout << "serial took " << serial.count() << "ms, amp took: " << amp.count() << "ms" << std::endl;

}
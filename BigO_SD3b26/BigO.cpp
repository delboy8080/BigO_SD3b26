/*****************************************************************//**
 * \file   BigO.cpp
 * \brief  Provides timing function used to measure performance of a function.
 * This file also contains some common algorithm (search, sort, factorial)
 * implementations which you can use the measureTime function with.
 *
 * \author DF
 * \date   October 2020
 *********************************************************************/
#include <iostream>
#include <list>
#include <iomanip>
#include <chrono>
using namespace std;

template <typename FuncType>
double measureTime(FuncType func);

int binarySearch(int* list, int size, int target);
int linearSearch(int* list, int size, int value);
void printFirstItem(int arrayOfItems[]);
void bubbleSort(int arr[], int size);
void factorial(int i);

struct linearFunctor
{
	int* arr;
	int size;
	int target;
	linearFunctor(int* a, int s, int t)
	{
		arr = a;
		size = s;
		target = t;
	}

	void operator()()
	{
		int pos = linearSearch(arr, size, target);
	}
};

struct binaryFunctor
{
	int* arr;
	int size;
	int target;
	binaryFunctor(int* a, int s, int t)
	{
		arr = a;
		size = s;
		target = t;
	}

	void operator()()
	{
		int pos = binarySearch(arr, size, target);
	}
};


void runTests()
{
	int* sizes = new int[5] {1000,10000,100000,1000000,10000000};
	cout << left<<setw(12) << "Size" << setw(12) << "Linear" << setw(12)
		<< "Binary" << endl;
	for (int i = 0; i < 5;i++)
	{
		int arrSize = sizes[i];
		int* arr = new int[arrSize];
		for (int x = 0; x < arrSize;x++)
		{
			arr[x] = x + 1;
		}

		linearFunctor lf(arr, arrSize, 0);
		binaryFunctor bf(arr, arrSize, 0);
		double linearTotal = 0, binaryTotal = 0;
		for (int x = 0; x < 100; x++)
		{
			linearTotal+= measureTime(lf);
			binaryTotal+= measureTime(bf);
		}
		cout << left << setw(12) << arrSize << setw(12) << linearTotal/100 << setw(12)
			<< binaryTotal/100 << endl;

		delete[] arr;
	}
}
int main2()
{
	std::cout << "Code to use BigO functions...." << endl;
	runTests();
	return 0;
}


template <typename FuncType>
double measureTime(FuncType func)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> st = std::chrono::high_resolution_clock::now();
	func();
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	return (end - st) / std::chrono::nanoseconds(1);

}
// O(log N)
int binarySearch(int* list, int size, int target)
{
	int min = 0, max = size - 1, mid = 0;
	bool found = false;
	while (!found && min <= max)
	{
		mid = (min + max) / 2; // (integer div!)
		if (list[mid] == target)
			found = true;
		else if (target < list[mid])
			max = mid - 1;
		else min = mid + 1;
	}
	if (found) return mid;
	else return -1;
}
// O(N)
int linearSearch(int* list, int size, int value)
{
	for (int x = 0; x < size; x++)
		if (list[x] == value) return x;

	return -1;
}
//O(1)
void printFirstItem(int arrayOfItems[])
{
	cout << arrayOfItems[0] << endl;
}
//O(n^2)
void bubbleSort(int arr[], int size)
{
	int n = size;
	int tmp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
//O(N^2)
void factorial(int i)
{
	int sum = 0;
	for (int x = i; x > 0; x--)
	{
		sum += x;
	}
	cout << sum << endl;

	if (i > 0)
		factorial(i - 1);
	else
		return;
}
//O(log N)
void func(int N)
{
	if (N == 0)
		return;
	cout << N << endl;
	func(N / 2);
}

//#include <iostream>
//#include <vector>
//#include "Array.h"
//#include <typeinfo>
//#include <ctime>
//#include <chrono>
//
//using namespace std;
//using namespace std::chrono;
//
//
////working
//template<class T>
//void selectionSort(T &, const int size);
//template<class T>
//void bubbleSort(T &, const int size);
//template<class T>
//void bubbleSort2(T &, const int size);
//template<class T>
//void insertionSort(T &, const int size);
//template<class T>
//void heapify(T &, int n, int i);
//template<class T>
//void heapSort(T &, int n);
//template<class T>
//int partition(T &, int left, int right);
//template<class T>
//void quickSort(T &, int left, int right);
//template<class T>
//void shellSort(T &, const int size);
//
//
//void mergeSort(int a[], int i, int j);
//void mergeSort(Array<int> & a, int i, int j);
//void mergeSort(vector<int> & a, int i, int j);
//void merge(int a[], int i, int mid, int j);
//void merge(Array<int> & a, int i, int mid, int j);
//void merge(vector<int> & a, int i, int mid, int j);
//
////not working
////template<class T>
////void mergeSort(T &, int i, int j, const int & size);
////template<class T>
////void merge(T &, int i, int mid, int j, const int & size);
//
//
//int main()
//{
//	const int SIZE1 = 10000;
//	const int SIZE2 = 20000;
//	const int SIZE3 = 30000;
//
//	int cArray1[SIZE1];
//	int cArray2[SIZE2];
//	int cArray3[SIZE3];
//	Array<int> myArray1(SIZE1);
//	Array<int> myArray2(SIZE2);
//	Array<int> myArray3(SIZE3);
//	vector<int> vector1(SIZE1);
//	vector<int> vector2(SIZE2);
//	vector<int> vector3(SIZE3);
//
//	
//	//generate random number arrays
//	int num = 0;
//	int cArrayRand1[SIZE1];
//	int cArrayRand2[SIZE2];
//	int cArrayRand3[SIZE3];
//	Array<int> myArrayRand1(SIZE1);
//	Array<int> myArrayRand2(SIZE2);
//	Array<int> myArrayRand3(SIZE3);
//	vector<int> vectorRand1(SIZE1);
//	vector<int> vectorRand2(SIZE2);
//	vector<int> vectorRand3(SIZE3);
//
//	srand(time(0));
//	for (int i = 0; i < SIZE1; i++)
//	{
//		num = rand() % 10000;
//		cArrayRand1[i] = num;
//		myArrayRand1[i] = num;
//		vectorRand1[i] = num;
//	}
//	for (int i = 0; i < SIZE2; i++)
//	{
//		num = rand() % 20000;
//		cArrayRand2[i] = num;
//		myArrayRand2[i] = num;
//		vectorRand2[i] = num;
//	}
//	for (int i = 0; i < SIZE3; i++)
//	{
//		num = rand() % 30000;
//		cArrayRand3[i] = num;
//		myArrayRand3[i] = num;
//		vectorRand3[i] = num;
//	}
//
//	for (int i = 0; i < SIZE1; i++)
//		cArray1[i] = cArrayRand1[i];
//	for (int i = 0; i < SIZE2; i++)
//		cArray2[i] = cArrayRand2[i];
//	for (int i = 0; i < SIZE3; i++)
//		cArray3[i] = cArrayRand3[i];
//	myArray1 = myArrayRand1;
//	myArray2 = myArrayRand2;
//	myArray3 = myArrayRand3;
//	vector1 = vectorRand1;
//	vector2 = vectorRand2;
//	vector3 = vectorRand3;
//
//	high_resolution_clock::time_point t1;
//	high_resolution_clock::time_point t2;
//
//	// Selection Sort 1
//	cout << "C Array 1 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(cArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto cSS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cSS1 << " uS\n\n";
//
//	cout << "My Array 1 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(myArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto mSS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mSS1 << " uS\n\n";
//
//	cout << "Vector 1 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(vector1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto vSS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vSS1 << " uS\n\n";
//	
//	//Selection Sort 2
//	cout << "C Array 2 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(cArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto cSS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cSS2 << " uS\n\n";
//
//	cout << "My Array 2 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(myArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto mSS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mSS2 << " uS\n\n";
//
//	cout << "Vector 2 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(vector2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto vSS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vSS2 << " uS\n\n";
//
//	//Selection Sort 3
//	cout << "C Array 3 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(cArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto cSS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cSS3 << " uS\n\n";
//
//	cout << "My Array 3 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(myArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto mSS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mSS3 << " uS\n\n";
//
//	cout << "Vector 3 SelectionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	selectionSort(vector3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto vSS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vSS3 << " uS\n\n";
//
//	//RESET ARRAYS	
//	for (int i = 0; i < SIZE1; i++)
//		cArray1[i] = cArrayRand1[i];
//	for (int i = 0; i < SIZE2; i++)
//		cArray2[i] = cArrayRand2[i];
//	for (int i = 0; i < SIZE3; i++)
//		cArray3[i] = cArrayRand3[i];
//	myArray1 = myArrayRand1;
//	myArray2 = myArrayRand2;
//	myArray3 = myArrayRand3;
//	vector1 = vectorRand1;
//	vector2 = vectorRand2;
//	vector3 = vectorRand3;
//
//	// Bubble Sort A 1
//	cout << "C Array 1 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(cArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto cBSA1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cBSA1 << " uS\n\n";
//
//	cout << "My Array 1 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(myArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto mBSA1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mBSA1 << " uS\n\n";
//
//	cout << "Vector 1 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(vector1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto vBSA1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vBSA1 << " uS\n\n";
//
//	//Bubble Sort A 2
//	cout << "C Array 2 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(cArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto cBSA2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cBSA2 << " uS\n\n";
//
//	cout << "My Array 2 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(myArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto mBSA2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mBSA2 << " uS\n\n";
//
//	cout << "Vector 2 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(vector2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto bBSA2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << bBSA2 << " uS\n\n";
//
//	//Bubble Sort A 3
//	cout << "C Array 3 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(cArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto cBSA3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cBSA3 << " uS\n\n";
//
//	cout << "My Array 3 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(myArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto mBSA3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mBSA3 << " uS\n\n";
//
//	cout << "Vector 3 BubbleSort A..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort(vector3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto vBSA3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vBSA3 << " uS\n\n";
//
//	//RESET ARRAYS	
//	for (int i = 0; i < SIZE1; i++)
//		cArray1[i] = cArrayRand1[i];
//	for (int i = 0; i < SIZE2; i++)
//		cArray2[i] = cArrayRand2[i];
//	for (int i = 0; i < SIZE3; i++)
//		cArray3[i] = cArrayRand3[i];
//	myArray1 = myArrayRand1;
//	myArray2 = myArrayRand2;
//	myArray3 = myArrayRand3;
//	vector1 = vectorRand1;
//	vector2 = vectorRand2;
//	vector3 = vectorRand3;
//
//	// Bubble Sort B 1
//	cout << "C Array 1 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(cArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto cBSB1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cBSB1 << " uS\n\n";
//
//	cout << "My Array 1 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(myArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto mBSB1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mBSB1 << " uS\n\n";
//
//	cout << "Vector 1 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(vector1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto vBSB1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vBSB1 << " uS\n\n";
//
//	//Bubble Sort B 2
//	cout << "C Array 2 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(cArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto cBSB2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cBSB2 << " uS\n\n";
//
//	cout << "My Array 2 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(myArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto mBSB2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mBSB2 << " uS\n\n";
//
//	cout << "Vector 2 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(vector2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto bBSB2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << bBSB2 << " uS\n\n";
//
//	//Bubble Sort B 3
//	cout << "C Array 3 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(cArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto cBSB3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cBSB3 << " uS\n\n";
//
//	cout << "My Array 3 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(myArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto mBSB3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mBSB3 << " uS\n\n";
//
//	cout << "Vector 3 BubbleSort B..." << endl;
//	t1 = high_resolution_clock::now();
//	bubbleSort2(vector3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto vBSB3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vBSB3 << " uS\n\n";
//
//	//RESET ARRAYS	
//	for (int i = 0; i < SIZE1; i++)
//		cArray1[i] = cArrayRand1[i];
//	for (int i = 0; i < SIZE2; i++)
//		cArray2[i] = cArrayRand2[i];
//	for (int i = 0; i < SIZE3; i++)
//		cArray3[i] = cArrayRand3[i];
//	myArray1 = myArrayRand1;
//	myArray2 = myArrayRand2;
//	myArray3 = myArrayRand3;
//	vector1 = vectorRand1;
//	vector2 = vectorRand2;
//	vector3 = vectorRand3;
//
//	// Insertion Sort 1
//	cout << "C Array 1 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(cArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto cIS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cIS1 << " uS\n\n";
//
//	cout << "My Array 1 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(myArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto mIS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mIS1 << " uS\n\n";
//
//	cout << "Vector 1 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(vector1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto vIS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vIS1 << " uS\n\n";
//
//	//Insertion Sort  2
//	cout << "C Array 2 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(cArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto cIS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cIS2 << " uS\n\n";
//
//	cout << "My Array 2 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(myArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto mIS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mIS2 << " uS\n\n";
//
//	cout << "Vector 2 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(vector2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto vIS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vIS2 << " uS\n\n";
//
//	//Insertion Sort 3
//	cout << "C Array 3 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(cArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto cIS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cIS3 << " uS\n\n";
//
//	cout << "My Array 3 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(myArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto mIS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mIS3 << " uS\n\n";
//
//	cout << "Vector 3 InsertionSort..." << endl;
//	t1 = high_resolution_clock::now();
//	insertionSort(vector3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto vIS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vIS3 << " uS\n\n";
//
//	//RESET ARRAYS	
//	for (int i = 0; i < SIZE1; i++)
//		cArray1[i] = cArrayRand1[i];
//	for (int i = 0; i < SIZE2; i++)
//		cArray2[i] = cArrayRand2[i];
//	for (int i = 0; i < SIZE3; i++)
//		cArray3[i] = cArrayRand3[i];
//	myArray1 = myArrayRand1;
//	myArray2 = myArrayRand2;
//	myArray3 = myArrayRand3;
//	vector1 = vectorRand1;
//	vector2 = vectorRand2;
//	vector3 = vectorRand3;
//
//	// Heap Sort 1
//	cout << "C Array 1 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(cArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto cHS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cHS1 << " uS\n\n";
//
//	cout << "My Array 1 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(myArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto mHS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mHS1 << " uS\n\n";
//
//	cout << "Vector 1 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(vector1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto vHS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vHS1 << " uS\n\n";
//
//	//Heap Sort  2
//	cout << "C Array 2 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(cArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto cHS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cHS2 << " uS\n\n";
//
//	cout << "My Array 2 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(myArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto mHS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mHS2 << " uS\n\n";
//
//	cout << "Vector 2 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(vector2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto vHS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vHS2 << " uS\n\n";
//
//	//Heap Sort 3
//	cout << "C Array 3 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(cArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto cHS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cHS3 << " uS\n\n";
//
//	cout << "My Array 3 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(myArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto mHS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mHS3 << " uS\n\n";
//
//	cout << "Vector 3 HeapSort..." << endl;
//	t1 = high_resolution_clock::now();
//	heapSort(vector3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto vHS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vHS3 << " uS\n\n";
//
//	//RESET ARRAYS	
//	for (int i = 0; i < SIZE1; i++)
//		cArray1[i] = cArrayRand1[i];
//	for (int i = 0; i < SIZE2; i++)
//		cArray2[i] = cArrayRand2[i];
//	for (int i = 0; i < SIZE3; i++)
//		cArray3[i] = cArrayRand3[i];
//	myArray1 = myArrayRand1;
//	myArray2 = myArrayRand2;
//	myArray3 = myArrayRand3;
//	vector1 = vectorRand1;
//	vector2 = vectorRand2;
//	vector3 = vectorRand3;
//
//	// Quick Sort 1
//	cout << "C Array 1 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(cArray1, 0, SIZE1 - 1);
//	t2 = high_resolution_clock::now();
//	auto cQS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cQS1 << " uS\n\n";
//
//	cout << "My Array 1 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(myArray1, 0, SIZE1 - 1);
//	t2 = high_resolution_clock::now();
//	auto mQS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mQS1 << " uS\n\n";
//
//	cout << "Vector 1 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(vector1, 0, SIZE1 - 1);
//	t2 = high_resolution_clock::now();
//	auto vQS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vQS1 << " uS\n\n";
//
//	//Quick Sort  2
//	cout << "C Array 2 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(cArray2, 0, SIZE2 - 1);
//	t2 = high_resolution_clock::now();
//	auto cQS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cQS2 << " uS\n\n";
//
//	cout << "My Array 2 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(myArray2, 0, SIZE2 - 1);
//	t2 = high_resolution_clock::now();
//	auto mQS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mQS2 << " uS\n\n";
//
//	cout << "Vector 2 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(vector2, 0, SIZE2 - 1);
//	t2 = high_resolution_clock::now();
//	auto vQS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vQS2 << " uS\n\n";
//
//	//Quick Sort 3
//	cout << "C Array 3 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(cArray3, 0, SIZE3 - 1);
//	t2 = high_resolution_clock::now();
//	auto cQS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cQS3 << " uS\n\n";
//
//	cout << "My Array 3 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(myArray3, 0, SIZE3 - 1);
//	t2 = high_resolution_clock::now();
//	auto mQS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mQS3 << " uS\n\n";
//
//	cout << "Vector 3 QuickSort..." << endl;
//	t1 = high_resolution_clock::now();
//	quickSort(vector3, 0, SIZE3 - 1);
//	t2 = high_resolution_clock::now();
//	auto vQS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vQS3 << " uS\n\n";
//
//	//RESET ARRAYS	
//	for (int i = 0; i < SIZE1; i++)
//		cArray1[i] = cArrayRand1[i];
//	for (int i = 0; i < SIZE2; i++)
//		cArray2[i] = cArrayRand2[i];
//	for (int i = 0; i < SIZE3; i++)
//		cArray3[i] = cArrayRand3[i];
//	myArray1 = myArrayRand1;
//	myArray2 = myArrayRand2;
//	myArray3 = myArrayRand3;
//	vector1 = vectorRand1;
//	vector2 = vectorRand2;
//	vector3 = vectorRand3;
//
//	// Shell Sort A 1
//	cout << "C Array 1 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(cArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto cShS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cShS1 << " uS\n\n";
//
//	cout << "My Array 1 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(myArray1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto mShS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mShS1 << " uS\n\n";
//
//	cout << "Vector 1 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(vector1, SIZE1);
//	t2 = high_resolution_clock::now();
//	auto vShS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vShS1 << " uS\n\n";
//
//	//Shell Sort A 2
//	cout << "C Array 2 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(cArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto cShS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cShS2 << " uS\n\n";
//
//	cout << "My Array 2 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(myArray2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto mShS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mShS2 << " uS\n\n";
//
//	cout << "Vector 2 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(vector2, SIZE2);
//	t2 = high_resolution_clock::now();
//	auto vShS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vShS2 << " uS\n\n";
//
//	//Shell Sort A 3
//	cout << "C Array 3 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(cArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto cShS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cShS3 << " uS\n\n";
//
//	cout << "My Array 3 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(myArray3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto mShS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mShS3 << " uS\n\n";
//
//	cout << "Vector 3 shellSort..." << endl;
//	t1 = high_resolution_clock::now();
//	shellSort(vector3, SIZE3);
//	t2 = high_resolution_clock::now();
//	auto vShS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vShS3 << " uS\n\n";
//
//	//RESET ARRAYS	
//	for (int i = 0; i < SIZE1; i++)
//		cArray1[i] = cArrayRand1[i];
//	for (int i = 0; i < SIZE2; i++)
//		cArray2[i] = cArrayRand2[i];
//	for (int i = 0; i < SIZE3; i++)
//		cArray3[i] = cArrayRand3[i];
//	myArray1 = myArrayRand1;
//	myArray2 = myArrayRand2;
//	myArray3 = myArrayRand3;
//	vector1 = vectorRand1;
//	vector2 = vectorRand2;
//	vector3 = vectorRand3;
//
//	// Merge Sort 1
//	cout << "C Array 1 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(cArray1, 0, SIZE1 - 1);
//	t2 = high_resolution_clock::now();
//	auto cMS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cMS1 << " uS\n\n";
//
//	cout << "My Array 1 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(myArray1, 0, SIZE1 - 1);
//	t2 = high_resolution_clock::now();
//	auto mMS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mMS1 << " uS\n\n";
//
//	cout << "Vector 1 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(vector1, 0, SIZE1 - 1);
//	t2 = high_resolution_clock::now();
//	auto vMS1 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vMS1 << " uS\n\n";
//
//	//Merge Sort  2
//	cout << "C Array 2 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(cArray2, 0, SIZE2 - 1);
//	t2 = high_resolution_clock::now();
//	auto cMS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cMS2 << " uS\n\n";
//
//	cout << "My Array 2 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(myArray2, 0, SIZE2 - 1);
//	t2 = high_resolution_clock::now();
//	auto mMS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mMS2 << " uS\n\n";
//
//	cout << "Vector 2 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(vector2, 0, SIZE2 - 1);
//	t2 = high_resolution_clock::now();
//	auto vMS2 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vMS2 << " uS\n\n";
//
//	//Merge Sort 3
//	cout << "C Array 3 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(cArray3, 0, SIZE3 - 1);
//	t2 = high_resolution_clock::now();
//	auto cMS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << cMS3 << " uS\n\n";
//
//	cout << "My Array 3 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(myArray3, 0, SIZE3 - 1);
//	t2 = high_resolution_clock::now();
//	auto mMS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << mMS3 << " uS\n\n";
//
//	cout << "Vector 3 mergeSort..." << endl;
//	t1 = high_resolution_clock::now();
//	mergeSort(vector3, 0, SIZE3 - 1);
//	t2 = high_resolution_clock::now();
//	auto vMS3 = duration_cast<microseconds>(t2 - t1).count();
//	cout << "Duration: " << vMS3 << " uS\n\n";
//
//
//
//	//mergeSort(vector1, 0, SIZE1 - 1);
//
//	/*insertionSort(myArray1, SIZE1);
//	insertionSort(vector1, SIZE1);*/
//
//	/*for (int i = 0; i < SIZE1; i++)
//		cout << vector1[i] << " ";
//	cout << "\n\n";*/
//	/*for (int i = 0; i < SIZE1; i++)
//		cout << myArray1[i] << " ";
//	cout << "\n\n";
//	for (int i = 0; i < SIZE1; i++)
//		cout << vector1[i] << " ";*/
//	
//	cout << "done" << endl;
//
//	cin.get();
//	return 0;
//}
//
//
//// SELECTION SORT
//template<class T>
//inline void selectionSort(T & a, const int size)
//{
//
//	for (int i = size - 1; i >= 1; i--)
//	{
//		int index = i; // i is the last item position and
//					   // index is the largest element position 
//		for (int j = 0; j < i; j++)
//		{
//			if (a[j] > a[index])
//				index = j; // j is the current largest item
//		}
//		// swap the largest item a[index] with the last item a[i]
//		int temp = a[index];
//		a[index] = a[i];
//		a[i] = temp;
//	}
//}
//
////BUBBLE SORT
//template<class T>
//inline void bubbleSort(T & a, const int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		for (int j = 0; j < size - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//}
//
////BUBBLE SORT 2
//template<class T>
//inline void bubbleSort2(T & a, const int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		bool isSorted = true; // isSorted = true if a[] is sorted
//		for (int j = 0; j < size - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//				isSorted = false;
//			}
//		}
//		if (isSorted) return;
//	}
//}
//
////INSERTION SORT
//template<class T>
//inline void insertionSort(T & a, const int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		//a[i] is the next data to insert
//		int next = a[i];
//		//Scan backwards to find a place
//		int j;
//
//		for (j = i - 1; j >= 0 && a[j] > next; j--)
//		{
//			a[j + 1] = a[j];
//		}
//		// Now insert the value next after index j at the end of the loop
//		a[j + 1] = next;
//	}
//}
//
////PARTITION
//template<class T>
//inline int partition(T & a, int left, int right)
//{
//	int p = a[left], l = left + 1, r = right;
//	while (l < r)
//	{
//		while (l < right && a[l] < p) l++;
//		while (r > left && a[r] >= p) r--;
//		if (l < r)
//		{
//			int temp = a[l];
//			a[l] = a[r];
//			a[r] = temp;
//		}
//	}
//	a[left] = a[r];
//	a[r] = p;
//	return r;
//}
//
////QUICKSORT
//template <class T>
//inline void quickSort(T & a, int left, int right)
//{
//
//	if (left < right)
//	{
//		int p = partition(a, left, right);
//		quickSort(a, left, p - 1);
//		quickSort(a, p + 1, right);
//	}
//}
//
////SHELLSORT
//template<class T>
//inline void shellSort(T & a, const int size)
//{
//	int j;
//	for (int h = size / 2; h > 0; h /= 2)
//	{
//		for (int i = h; i < size; i++)
//		{
//			int tmp = a[i];
//			for (j = i; j >= h && tmp < a[j - h]; j -= h)
//			{
//				a[j] = a[j - h];
//			}
//			a[j] = tmp;
//		}
//	}
//
//
//}
//
//// To heapify a subtree rooted with node i which is
//// an index in arr[]. n is size of heap
//template<class T>
//inline void heapify(T & arr, int n, int i)
//{
//	int largest = i;  // Initialize largest as root
//	int l = 2 * i + 1;  // left = 2*i + 1
//	int r = 2 * i + 2;  // right = 2*i + 2
//
//						// If left child is larger than root
//	if (l < n && arr[l] > arr[largest])
//		largest = l;
//
//	// If right child is larger than largest so far
//	if (r < n && arr[r] > arr[largest])
//		largest = r;
//
//	// If largest is not root
//	if (largest != i)
//	{
//		swap(arr[i], arr[largest]);
//
//		// Recursively heapify the affected sub-tree
//		heapify(arr, n, largest);
//	}
//}
//
//// main function to do heap sort
//template<class T>
//inline void heapSort(T & arr, int n)
//{
//	// Build heap (rearrange array)
//	for (int i = n / 2 - 1; i >= 0; i--)
//		heapify(arr, n, i);
//
//	// One by one extract an element from heap
//	for (int i = n - 1; i >= 0; i--)
//	{
//		// Move current root to end
//		swap(arr[0], arr[i]);
//
//		// call max heapify on the reduced heap
//		heapify(arr, i, 0);
//	}
//}
//
////MERGE SORT
//template<class T>
//inline void mergeSort(T & a, int i, int j, const int & size)
//{
//	//to sort data from a[i] to a[j], where i<j
//	if (i < j)
//	{
//		int mid = (i + j) / 2; //divide
//		mergeSort(a, i, mid, size); //recursion
//		mergeSort(a, mid + 1, j, size);
//		merge(a, i, mid, j, size); // conquer
//	}
//}
//
////MERGE
//template<class T>
//inline void merge(T & a, int i, int mid, int j, const int & size)
//{
//	//Merges the 2 sorted sub-arrays
//	T temp;
//	//temp = new T[j - i + 1]; // temp storage
//	int left = i, right = mid + 1, it = 0;
//	// it = next index to store merged item in temp[]
//
//	while (left <= mid && right <= j)
//	{
//		if (a[left] <= a[right])
//			temp[it++] = a[left++];
//		else
//			temp[it++] = a[right++];
//	}
//	//copy the remaining elements into temp.
//	while (left <= mid)
//		temp[it++] = a[left++];
//	while (right <= j)
//		temp[it++] = a[right++];
//	//copy the result in temp back into the original array abort
//	for (int k = 0; k < size; k++)
//		a[i + k] = temp[k];
//}
//
//void mergeSort(int a[], int i, int j)
//{
//	//to sort data from a[i] to a[j], where i<j
//	if (i < j)
//	{
//		int mid = (i + j) / 2; //divide
//		mergeSort(a, i, mid); //recursion
//		mergeSort(a, mid + 1, j);
//		merge(a, i, mid, j); // conquer
//	}
//}
//
//void merge(int a[], int i, int mid, int j)
//{
//	//Merges the 2 sorted sub-arrays
//	int * temp;
//	int size = j - i + 1;
//	temp = new int[j - i + 1]; // temp storage
//	int left = i, right = mid + 1, it = 0;
//	// it = next index to store merged item in temp[]
//
//	while (left <= mid && right <= j)
//	{
//		if (a[left] <= a[right])
//			temp[it++] = a[left++];
//		else
//			temp[it++] = a[right++];
//	}
//	//copy the remaining elements into temp.
//	while (left <= mid)
//		temp[it++] = a[left++];
//	while (right <= j)
//		temp[it++] = a[right++];
//	//copy the result in temp back into the original array abort
//	for (int k = 0; k < size; k++)
//		a[i + k] = temp[k];
//	delete[] temp;
//}
//
//void mergeSort(Array<int> & a, int i, int j)
//{
//	//to sort data from a[i] to a[j], where i<j
//	if (i < j)
//	{
//		int mid = (i + j) / 2; //divide
//		mergeSort(a, i, mid); //recursion
//		mergeSort(a, mid + 1, j);
//		merge(a, i, mid, j); // conquer
//	}
//}
//
//void merge(Array<int> & a, int i, int mid, int j)
//{
//	//Merges the 2 sorted sub-arrays
//	int size = j - i + 1;
//	Array<int> temp(size);
//	int left = i, right = mid + 1, it = 0;
//	// it = next index to store merged item in temp[]
//
//	while (left <= mid && right <= j)
//	{
//		if (a[left] <= a[right])
//			temp[it++] = a[left++];
//		else
//			temp[it++] = a[right++];
//	}
//	//copy the remaining elements into temp.
//	while (left <= mid)
//		temp[it++] = a[left++];
//	while (right <= j)
//		temp[it++] = a[right++];
//	//copy the result in temp back into the original array abort
//	for (int k = 0; k < size; k++)
//		a[i + k] = temp[k];
//}
//
//void mergeSort(vector<int> & a, int i, int j)
//{
//	//to sort data from a[i] to a[j], where i<j
//	if (i < j)
//	{
//		int mid = (i + j) / 2; //divide
//		mergeSort(a, i, mid); //recursion
//		mergeSort(a, mid + 1, j);
//		merge(a, i, mid, j); // conquer
//	}
//}
//
//void merge(vector<int> & a, int i, int mid, int j)
//{
//	//Merges the 2 sorted sub-arrays
//	int size = j - i + 1;
//	vector<int> temp(size);
//	int left = i, right = mid + 1, it = 0;
//	// it = next index to store merged item in temp[]
//
//	while (left <= mid && right <= j)
//	{
//		if (a[left] <= a[right])
//			temp[it++] = a[left++];
//		else
//			temp[it++] = a[right++];
//	}
//	//copy the remaining elements into temp.
//	while (left <= mid)
//		temp[it++] = a[left++];
//	while (right <= j)
//		temp[it++] = a[right++];
//	//copy the result in temp back into the original array abort
//	for (int k = 0; k < size; k++)
//		a[i + k] = temp[k];
//}
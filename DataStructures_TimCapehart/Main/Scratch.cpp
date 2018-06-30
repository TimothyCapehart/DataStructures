//#include <crtdbg.h>
//#include <iostream>
//#include "ForwardIterator.h"
//#include "BackwardIterator.h"
//#include "DLList.h"  // Change to your Linked List Header
//#include "Exception.h"

//int main()
//{
//	DLList<int> test;
//	int nums[] = { 5, 4, 3, 2, 1 };
//	for (size_t i = 0; i < 5; i++)
//	{
//		test.Append(nums[i]);
//	}
//	ForwardIterator<int> fit;
//	fit = test.getHead();
//	
//	BackwardIterator<int> bit; 
//	bit = test.getTail();
//
//	for (fit; !fit.IsDone(); fit.MoveNext())
//	{
//		std::cout << fit.GetCurrent() << std::endl;
//	}
//	for (bit; !bit.IsDone(); bit.MoveNext())
//	{
//		std::cout << bit.GetCurrent() << std::endl;
//	}
//	std::cin.get();
//	return 0;
//}
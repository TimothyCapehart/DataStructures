#include "stdafx.h"
#include "CppUnitTest.h"
#include<iostream>
#include "CrtCheckMemory.h"
#include "BinarySearchTree.h"
#include "AVL.h"
#include <vector>
using std::string;
using std::vector;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

static vector<int> testVec;

namespace UnitTests
{

	TEST_CLASS(AVLTest)
	{
	public:
		static void ToVector(AVLNode<int> * p)
		{
			if (p != nullptr)
				testVec.push_back(p->_data);
		}
		TEST_METHOD_INITIALIZE(Init)
		{
			testVec.clear();
		}

		TEST_METHOD(AVLTests)
		{
			AVL<int> test;
			test.Insert(8);
			test.Insert(9);
			test.Insert(10);
			test.Insert(2);
			test.Insert(1);
			test.Insert(5);
			test.Insert(3);
			test.Insert(6);
			test.Insert(4);
			test.Insert(7);
			test.Insert(11);

			test.Delete(5);
			test.Delete(3);
			test.Delete(8);
			test.Delete(9);
			
			test.SetFunction(ToVector);

			int BF[7] = { 7, 4, 10, 2, 6, 11, 1 };
			int IO[7] = { 1, 2, 4, 6, 7, 10, 11 };
			int PO[7] = { 1, 2, 6, 4, 11, 10, 7 };
			int pO[7] = { 7, 4, 2, 1, 6, 10, 11 };

			test.BreadthFirst();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(BF[i], testVec[i]);

			testVec.clear();
			test.InOrder();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(IO[i], testVec[i]);

			testVec.clear();
			test.PostOrder();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(PO[i], testVec[i]);

			testVec.clear();
			test.PreOrder();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(pO[i], testVec[i]);
		}

	};
}
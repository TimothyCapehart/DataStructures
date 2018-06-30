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

	TEST_CLASS(BSTTest)
	{
	public:
		static void ToVector(BSTNode<int> * p)
		{
			if (p != nullptr)
				testVec.push_back(p->_data);
		}
		TEST_METHOD_INITIALIZE(Init)
		{
			testVec.clear();
		}

		TEST_METHOD(BSTInsertBFirst)
		{
			//CrtCheckMemory check;
			BST<int> test;
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

			test.SetFunction(ToVector);

			test.BreadthFirst();

			int *BF;
			BF = new int [11] { 8, 2, 9, 1, 5, 10, 3, 6, 11, 4, 7 };

			for (size_t i = 0; i < 11; i++)
				Assert::AreEqual(BF[i], testVec[i]);
			delete BF;
		}

		TEST_METHOD(BSTInsertInOrder)
		{
			//CrtCheckMemory check;
			BST<int> test;
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
			test.SetFunction(ToVector);

			test.InOrder();

			int IO[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

			for (size_t i = 0; i < testVec.size(); i++)
				Assert::AreEqual(IO[i], testVec[i]);
		}

		TEST_METHOD(BSTInsertPreOrder)
		{
			//CrtCheckMemory check;
			BST<int> test;
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
			test.SetFunction(ToVector);
			test.PreOrder();

			int PO[11] = { 8,2, 1, 5, 3, 4, 6, 7, 9, 10, 11 };

			for (size_t i = 0; i < testVec.size(); i++)
				Assert::AreEqual(PO[i], testVec[i]);
		}

		TEST_METHOD(BSTInsertPostOrder)
		{
			//CrtCheckMemory check;
			BST<int> test;
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

			test.SetFunction(ToVector);
			test.PostOrder();

			int PO[11] = {1, 4, 3, 7, 6, 5, 2, 11, 10, 9, 8};

			for (size_t i = 0; i < 11; i++)
				Assert::AreEqual(PO[i], testVec[i]);
		}

		TEST_METHOD(BSTInsertDeleteBF)
		{
			//CrtCheckMemory check;
			BST<int> test;
			test.Insert(27);
			test.Insert(93);
			test.Insert(11);
			test.Insert(32);
			test.Insert(69);
			test.Insert(77);
			test.Insert(2);
			test.Insert(49);
			test.Insert(33);
			test.Insert(42);
			test.Insert(80);
			test.Insert(75);

			test.Delete(42);
			test.Delete(11);
			test.Delete(69);

			test.SetFunction(ToVector);

			test.BreadthFirst();

			int BF[9] = { 27, 2, 93, 32, 75, 49, 77, 33, 80 };

			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(BF[i], testVec[i]);
		}

		TEST_METHOD(BSTInsertDeleteIO)
		{
			//CrtCheckMemory check;
			BST<int> test;
			test.Insert(27);
			test.Insert(93);
			test.Insert(11);
			test.Insert(32);
			test.Insert(69);
			test.Insert(77);
			test.Insert(2);
			test.Insert(49);
			test.Insert(33);
			test.Insert(42);
			test.Insert(80);
			test.Insert(75);

			test.Delete(42);
			test.Delete(11);
			test.Delete(69);

			test.SetFunction(ToVector);

			test.InOrder();

			int IO[9] = { 2, 27, 32, 33, 49, 75, 77, 80, 93 };

			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(IO[i], testVec[i]);
		}

		TEST_METHOD(BSTInsertDeletePre)
		{
			//CrtCheckMemory check;
			BST<int> test;
			test.Insert(27);
			test.Insert(93);
			test.Insert(11);
			test.Insert(32);
			test.Insert(69);
			test.Insert(77);
			test.Insert(2);
			test.Insert(49);
			test.Insert(33);
			test.Insert(42);
			test.Insert(80);
			test.Insert(75);

			test.Delete(42);
			test.Delete(11);
			test.Delete(69);

			test.SetFunction(ToVector);

			test.PreOrder();

			int BF[9] = { 27, 2, 93, 32, 75, 49, 33, 77, 80 };

			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(BF[i], testVec[i]);
		}

		TEST_METHOD(BSTInsertDeletePost)
		{
			//CrtCheckMemory check;
			BST<int> test;
			test.Insert(27);
			test.Insert(93);
			test.Insert(11);
			test.Insert(32);
			test.Insert(69);
			test.Insert(77);
			test.Insert(2);
			test.Insert(49);
			test.Insert(33);
			test.Insert(42);
			test.Insert(80);
			test.Insert(75);

			test.Delete(42);
			test.Delete(11);
			test.Delete(69);

			test.SetFunction(ToVector);

			test.PostOrder();

			int BF[9] = { 2, 33, 49, 80, 77, 75, 32, 93, 27 };

			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(BF[i], testVec[i]);
		}

		TEST_METHOD(DeleteRainy)
		{
			BST<int> test;
			bool caught = false;
			try
			{
				test.Delete(4);
			}
			catch (Exception &e)
			{
				caught = true;
			}
			Assert::IsTrue(caught);
		}
	};
}
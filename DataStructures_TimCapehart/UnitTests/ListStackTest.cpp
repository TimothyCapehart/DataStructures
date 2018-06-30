#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CrtCheckMemory.h"
#include "DLList.h"
#include "ListStack.h"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ListStackTest)
	{
	public:

		TEST_METHOD(LStackDefault)
		{
			ListStack<string> test;

			Assert::IsTrue(test.IsEmpty() && test.Size() == 0);
		}

		TEST_METHOD(LStackCopy)
		{
			ListStack<int> test;
			for (size_t i = 0; i < 5; i++)
				test.Push(i);

			bool pass1 = true;
			bool pass2 = true;

			ListStack<int> copy(test);
			if (test.Size() != copy.Size())
				pass1 = false;

			for (size_t i = 0; i < 5; i++)
			{
				if (test.Pop() != copy.Pop())
					pass2 = false;
			}
			Assert::IsTrue(pass1 && pass2);
		}

		TEST_METHOD(LStackAssign)
		{
			ListStack<int> test1;
			ListStack<int> test2;
			for (size_t i = 0; i < 5; i++)
				test1.Push(i);

			for (size_t i = 0; i < 9; i++)
				test2.Push(i + 1);

			test2 = test1;

			bool pass1 = true;
			bool pass2 = true;

			if (test1.Size() != test2.Size())
				pass1 = false;

			for (size_t i = 0; i < 5; i++)
			{
				if (test1.Pop() != test2.Pop())
					pass2 = false;
			}
			Assert::IsTrue(pass1 && pass2);
		}

		TEST_METHOD(LStackPush)
		{
			ListStack<int> test;
			test.Push(1);
			test.Push(2);
			test.Push(3);

			Assert::IsTrue(test.Size() == 3);

			int num[3];
			for (size_t i = 0; i < 3; i++)
				num[i] = test.Pop();
			Assert::IsTrue(num[0] == 3 && num[1] == 2
				&& num[2] == 1);
		}

		TEST_METHOD(LStackPopSunny)
		{
			ListStack<int> test;
			for (int i = 0; i < 10; i++)
				test.Push(i);

			Assert::IsTrue(test.Size() == 10);

			int num[10];
			for (int i = 9; i >= 0; i--)
				num[i] = test.Pop();

			bool pass = true;
			for (int i = 9; i >= 0; i--)
			{
				if (num[i] != i)
					pass = false;
			}
			Assert::IsTrue(test.IsEmpty() && pass);
		}

		TEST_METHOD(LStackPopRainy)
		{
			ListStack<int> test;
			for (int i = 0; i < 10; i++)
				test.Push(i);

			Assert::IsTrue(test.Size() == 10);

			bool caught = false;
			try
			{
				for (int i = 0; i < 11; i++)
					test.Pop();
			}
			catch (Exception &e)
			{
				caught = true;
			}
			Assert::IsTrue(caught);
		}

		TEST_METHOD(LStackPeekSunny)
		{
			ListStack<int> test;
			for (int i = 0; i < 5; i++)
				test.Push(i);

			int num[5];
			for (int i = 4; i >= 0; i--)
			{
				num[i] = test.Peek();
				test.Pop();
			}
			bool pass = true;
			for (int i = 4; i >= 0; i--)
			{
				if (num[i] != i)
					pass = false;
			}
			Assert::IsTrue(pass);
		}

		TEST_METHOD(LStackPeekRainy)
		{
			ListStack<int> test;
			
			bool caught = false;
			try
			{
				test.Peek();
			}
			catch (Exception & e)
			{
				caught = true;
			}
			Assert::IsTrue(caught);
		}
	};
}
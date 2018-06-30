#include "stdafx.h"
#include "CppUnitTest.h"
#include<iostream>
#include "CrtCheckMemory.h"
#include "Array.h"
#include "ArrayStack.h"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(StackArrayTest)
	{
	public:

		TEST_METHOD(AStackDefault)
		{
			CrtCheckMemory check;
			ArrayStack<string> test;
		
			Assert::IsTrue(test.getLength() == 1 && test.IsEmpty() && test.Size() == 0);
		}

		TEST_METHOD(AStackParam)
		{
			CrtCheckMemory check;
			ArrayStack<string> test(20);

			Assert::IsTrue(test.getLength() == 20 && test.IsEmpty() && test.Size() == 0);
		}

		TEST_METHOD(AStackCopy)
		{
			CrtCheckMemory check;
			ArrayStack<string> test(5);
			test.Push("Hello, ");
			test.Push("this ");
			test.Push("is ");
			test.Push("a ");
			test.Push("test.");

			ArrayStack<string> copy(test);
			bool pass = true;

			for (size_t i = 0; i < copy.Size(); i++)
			{
				if (copy[i] != test[i])
					pass = false;
			}

			Assert::IsTrue(copy.Size() == test.Size() && copy.getLength() == test.getLength()
				&& copy.getTop() == test.getTop() && pass);
		}

		TEST_METHOD(AStackAssign)
		{
			CrtCheckMemory check;
			ArrayStack<string> test1(5);
			test1.Push("Hello, ");
			test1.Push("this ");
			test1.Push("is ");
			test1.Push("a ");
			test1.Push("test.");

			ArrayStack<string> test2(10);
			test2.Push("This, ");
			test2.Push("is ");
			test2.Push("also ");
			test2.Push("Testy ");
			test2.Push("McTestface.");

			test2 = test1;
			bool pass = true;
			for (size_t i = 0; i < test2.Size(); i++)
			{
				if (test2[i] != test1[i])
					pass = false;
			}

			Assert::IsTrue(test2.Size() == test1.Size() && test2.getLength() == test1.getLength()
				&& test2.getTop() == test1.getTop() && pass);
		}

		TEST_METHOD(AStackPushSunny)
		{
			CrtCheckMemory check;
			ArrayStack<string> test(5);
			test.Push("Hello, ");
			test.Push("this ");
			test.Push("is ");
			test.Push("a ");
			test.Push("test.");
			
			string testString = "";
			for (size_t i = 0; i < test.Size(); i++)
				testString += test[i];

			Assert::IsTrue(testString == "Hello, this is a test." && test.Size() == 5 && test.Peek() == "test."
				&& test.getTop() == 4 & test.IsFull());
		}

		TEST_METHOD(AStackPushRainy)
		{
			CrtCheckMemory check;
			ArrayStack<string> test(5);
			test.Push("Hello, ");
			test.Push("this ");
			test.Push("is ");
			test.Push("a ");
			test.Push("test.");
			bool caught = false;
			try
			{
				test.Push("Should throw exception");
			}
			catch (Exception &e)
			{
				caught = true;
			}
			Assert::IsTrue(caught);
		}

		TEST_METHOD(AStackPopSunny)
		{
			CrtCheckMemory check;
			ArrayStack<string> test(5);
			test.Push("0");
			test.Push("1");
			test.Push("2");
			test.Push("3");
			test.Push("4");

			string testString;
			for (size_t i = 0; i < 5; i++)
				testString += test.Pop();
			
			Assert::IsTrue(test.IsEmpty() && testString == "43210");
		}

		TEST_METHOD(AStackPopRainy)
		{
			CrtCheckMemory check;
			ArrayStack<string> test(5);
			test.Push("0");
			test.Push("1");
			test.Push("2");
			test.Push("3");
			test.Push("4");

			bool caught = false;
			try
			{
				for (size_t i = 0; i < 6; i++)
					test.Pop();
			}
			catch (Exception &e) 
			{
				caught = true;
			}
			Assert::IsTrue(caught);
		}

		TEST_METHOD(AStackPeekSunny)
		{
			CrtCheckMemory check;
			ArrayStack<string> test(5);
			test.Push("0");
			test.Push("1");
			test.Push("2");
			test.Push("3");
			test.Push("4");
			ArrayStack<string> test1(3);
			test1.Push("0");
			test1.Push("1");
			test1.Push("2");
			ArrayStack<string> test2(7);
			test2.Push("0");
			test2.Push("1");
			test2.Push("2");
			test2.Push("3");
			test2.Push("4");
			test2.Push("5");
			test2.Push("6");

			string peek[3];
			peek[0] = test.Peek();
			peek[1] = test1.Peek();
			peek[2] = test2.Peek();

			Assert::IsTrue(peek[0] == "4" && peek[1] == "2" && peek[2] == "6");
		}

		TEST_METHOD(AStackPeekRainy)
		{
			CrtCheckMemory check;
			ArrayStack<string> test;

			bool caught = false;
			try
			{
				test.Peek();
			}
			catch (Exception &e)
			{
				caught = true;
			}
			Assert::IsTrue(caught);
		}
	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CrtCheckMemory.h"
#include "ListQueue.h"

using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ListQueueTest)
	{
	public:

		TEST_METHOD(LQueueDefault)
		{
			CrtCheckMemory check;
			ListQueue<string> test;

			Assert::IsTrue(test.Size() == 0 && test.IsEmpty());
		}

		TEST_METHOD(LQueueCopy)
		{
			CrtCheckMemory check;

			ListQueue<string> test;
			test.Enqueue("This ");
			test.Enqueue("is ");
			test.Enqueue("not ");
			test.Enqueue("a ");
			test.Enqueue("test.");

			ListQueue<string> copy1(test);
			ListQueue<string> copy2(test);

			string testStr;

			for (size_t i = 0; i < 5; i++)
				testStr += copy1.Dequeue();

			bool pass = true;
			for (size_t i = 0; i < 5; i++)
				if (copy2.Dequeue() != test.Dequeue())
					pass = false;

			Assert::IsTrue(testStr == "This is not a test." && pass);
		}

		TEST_METHOD(LQueueAssign)
		{
			CrtCheckMemory check;

			ListQueue<string> test;
			test.Enqueue("This ");
			test.Enqueue("is ");
			test.Enqueue("not ");
			test.Enqueue("a ");
			test.Enqueue("test.");

			ListQueue<string> copy1 = test;
			ListQueue<string> copy2 = test;

			string testStr;

			for (size_t i = 0; i < 5; i++)
				testStr += copy1.Dequeue();

			bool pass = true;
			for (size_t i = 0; i < 5; i++)
				if (copy2.Dequeue() != test.Dequeue())
					pass = false;

			Assert::IsTrue(testStr == "This is not a test." && pass);
		}

		TEST_METHOD(LQueueEnqueue)
		{
			CrtCheckMemory check;

			ListQueue<string> test;
			test.Enqueue("This ");
			test.Enqueue("is ");
			test.Enqueue("not ");
			test.Enqueue("a ");
			test.Enqueue("test.");

			Assert::IsTrue(test.Size() == 5);

			string testStr;

			for (size_t i = 0; i < 5; i++)
				testStr += test.Dequeue();

			Assert::IsTrue(testStr == "This is not a test.");
		}

		TEST_METHOD(LQueueDequeueSunny)
		{
			CrtCheckMemory check;

			ListQueue<string> test;
			test.Enqueue("This ");
			test.Enqueue("is ");
			test.Enqueue("not ");
			test.Enqueue("a ");
			test.Enqueue("test.");
			string testStr;

			for (size_t i = 0; i < 5; i++)
				testStr += test.Dequeue();

			Assert::IsTrue(testStr == "This is not a test." && test.Size() == 0 && test.IsEmpty());
		}

		TEST_METHOD(LQueueDequeueRainy)
		{
			CrtCheckMemory check;

			ListQueue<string> test;
			test.Enqueue("This ");
			test.Enqueue("is ");
			test.Enqueue("not ");
			test.Enqueue("a ");
			test.Enqueue("test.");

			bool caught = false;
			try
			{
				for (size_t i = 0; i < 6; i++)
					test.Dequeue();
			}
			catch (Exception & e)
			{
				caught = true;
			}

			Assert::IsTrue(caught && test.IsEmpty());
		}

		TEST_METHOD(LQueueFrontSunny)
		{
			CrtCheckMemory check;

			ListQueue<string> test;
			test.Enqueue("This ");
			test.Enqueue("is ");
			test.Enqueue("not ");
			test.Enqueue("a ");
			test.Enqueue("test.");

			string front1 = test.Front();
			test.Dequeue();
			string front2 = test.Front();
			test.Front() = "changed";

			Assert::IsTrue(front1 == "This " && front2 == "is " && test.Front() == "changed");
		}

		TEST_METHOD(LQueueFrontRainy)
		{
			CrtCheckMemory check;

			ListQueue<string> test;
			bool caught = false;
			try
			{
				test.Front();
			}
			catch (Exception & e)
			{
				caught = true;
			}
			Assert::IsTrue(caught);
		}

		TEST_METHOD(LQueueIsEmpty)
		{
			CrtCheckMemory check;

			ListQueue<string> test;
			
			Assert::IsTrue(test.IsEmpty());

			test.Enqueue("This ");
			test.Enqueue("is ");
			test.Enqueue("not ");
			test.Enqueue("a ");
			test.Enqueue("test.");

			Assert::IsFalse(test.IsEmpty());

			test.Dequeue();
			test.Dequeue();
			test.Dequeue();
			test.Dequeue();
			test.Dequeue();
			
			Assert::IsTrue(test.IsEmpty());
		}

		TEST_METHOD(LQueueSize)
		{
			CrtCheckMemory check;

			ListQueue<string> test;

			Assert::IsTrue(test.Size() == 0);

			test.Enqueue("This ");
			test.Enqueue("is ");
			test.Enqueue("not ");
			test.Enqueue("a ");
			test.Enqueue("test.");

			Assert::IsTrue(test.Size() == 5);
		}
	};
}
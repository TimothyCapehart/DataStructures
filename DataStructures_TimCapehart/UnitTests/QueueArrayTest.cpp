#include "stdafx.h"
#include "CppUnitTest.h"
#include<iostream>
#include "CrtCheckMemory.h"
#include "ArrayQueue.h"

using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(QueueArrayTest)
	{
	public:

		TEST_METHOD(AQueueDefault)
		{
			ArrayQueue<string> test;

			Assert::IsTrue(test.IsEmpty() && test.Size() == 0);
		}

		TEST_METHOD(AQueueParam)
		{
			ArrayQueue<string> test(5);

			Assert::IsTrue(test.IsEmpty() && test.Size() == 0);
		}

		TEST_METHOD(AQueueCopy)
		{
			ArrayQueue<string> test1(5);
			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("a ");
			test1.Enqueue("test ");

			ArrayQueue<string> copy(test1);
			bool pass = true;
			for (size_t i = 0; i < copy.Size(); i++)
				if (copy.Dequeue() != test1.Dequeue())
					pass = false;
			
			Assert::IsTrue(pass);
		}

		TEST_METHOD(AQueueAssign)
		{
			ArrayQueue<string> test1(5);
			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("a ");
			test1.Enqueue("test ");

			ArrayQueue<string> test2 = test1;
			bool pass = true;
			for (size_t i = 0; i < test2.Size(); i++)
				if (test2.Dequeue() != test1.Dequeue())
					pass = false;

			Assert::IsTrue(pass);
		}

		TEST_METHOD(AQueueEnqueueSunny)
		{
			ArrayQueue<string> test1(5);
			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("not ");
			test1.Enqueue("a ");
			test1.Enqueue("test.");

			Assert::IsTrue(test1.Size() == 5 && test1.IsFull() && test1.Front() == "This ");
		}

		TEST_METHOD(AQueueEnqueueRainy)
		{
			ArrayQueue<string> test1(4);
			bool caught = false;
			try
			{
				test1.Enqueue("This ");
				test1.Enqueue("is ");
				test1.Enqueue("not ");
				test1.Enqueue("a ");
				test1.Enqueue("test.");
			}
			catch (Exception & e)
			{
				caught = true;
			}
			
			Assert::IsTrue(test1.Size() == 4 && test1.IsFull() && caught);
		}

		TEST_METHOD(AQueueDequeueSunny)
		{
			ArrayQueue<string> test1(4);
			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("a ");
			test1.Enqueue("test.");

			string testString = "";
			for (size_t i = 0; i < 4; i++)
				testString += test1.Dequeue();

			Assert::IsTrue(testString == "This is a test.");
		}

		TEST_METHOD(AQueueDequeueRainy)
		{
			ArrayQueue<string> test1(4);
			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("a ");
			test1.Enqueue("test.");
			bool caught = false;
			try
			{
				for (size_t i = 0; i < 5; i++)
					test1.Dequeue();
			}
			catch (Exception & e)
			{
				caught = true;
			}

			Assert::IsTrue(caught && test1.IsEmpty());
		}

		TEST_METHOD(AQueueFrontSunny)
		{
			ArrayQueue<string> test1(4);
			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("a ");
			test1.Enqueue("test.");
			
			string frontStr = test1.Front();

			Assert::IsTrue(frontStr == "This ");

			test1.Front() = "That ";

			Assert::IsTrue(test1.Front() == "That ");
		}

		TEST_METHOD(AQueueFrontRainy)
		{
			ArrayQueue<string> test1(4);
			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("a ");
			test1.Enqueue("test.");
			test1.Dequeue();			
			test1.Dequeue();
			test1.Dequeue();
			test1.Dequeue();
			bool caught = false;
			try
			{
				test1.Front();
			}
			catch (Exception & e)
			{
				caught = true;
			}
			Assert::IsTrue(caught);
		}

		TEST_METHOD(AQueueSize)
		{
			ArrayQueue<string> test1(5);
			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("not ");
			test1.Enqueue("a ");
			test1.Enqueue("test ");

			Assert::IsTrue(test1.Size() == 5);

			test1.Dequeue();
			test1.Dequeue();
			test1.Dequeue();

			Assert::IsTrue(test1.Size() == 2);
		}

		TEST_METHOD(AQueueIsEmpty)
		{
			ArrayQueue<string> test1(5);

			Assert::IsTrue(test1.IsEmpty());

			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("not ");
			test1.Enqueue("a ");
			test1.Enqueue("test ");

			Assert::IsFalse(test1.IsEmpty());

			test1.Dequeue();
			test1.Dequeue();
			test1.Dequeue();
			test1.Dequeue();
			test1.Dequeue();

			Assert::IsTrue(test1.IsEmpty());
		}

		TEST_METHOD(AQueueIsFull)
		{
			ArrayQueue<string> test1(5);

			Assert::IsFalse(test1.IsFull());

			test1.Enqueue("This ");
			test1.Enqueue("is ");
			test1.Enqueue("not ");
			test1.Enqueue("a ");
			test1.Enqueue("test ");

			Assert::IsTrue(test1.IsFull());

			test1.Dequeue();
			test1.Dequeue();

			Assert::IsFalse(test1.IsFull());

			test1.Enqueue("the ");
			test1.Enqueue("end.");
			
			Assert::IsTrue(test1.IsFull());
		}
	};
}
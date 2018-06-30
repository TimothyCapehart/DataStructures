#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "DLList.h"
#include "Exception.h"
#include "ForwardIterator.h"
#include "BackwardIterator.h"
#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(IteratorTests)
	{
	public:
		TEST_METHOD(ForwardReset)
		{
			DLList<int> test;
			int nums[] = { 5, 4, 3, 2, 1 };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(nums[i]);
			}
			ForwardIterator<int> fit;
			fit = test.getHead();
			for (fit; !fit.IsDone(); fit.MoveNext());
			Assert::IsTrue(fit.GetCurrent() == test.getTail()->getData());
			fit.Reset();
			Assert::IsTrue(fit.GetCurrent() == test.getHead()->getData());
		}

		TEST_METHOD(BackwardReset)
		{
			DLList<int> test;
			int nums[] = { 5, 4, 3, 2, 1 };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(nums[i]);
			}
			BackwardIterator<int> bit;
			bit = test.getTail();
			for (bit; !bit.IsDone(); bit.MoveNext());
			Assert::IsTrue(bit.GetCurrent() == test.getHead()->getData());
			bit.Reset();
			Assert::IsTrue(bit.GetCurrent() == test.getTail()->getData());
		}

		TEST_METHOD(ForwardIsDone)
		{
			DLList<int> test;
			int nums[] = { 5, 4, 3, 2, 1 };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(nums[i]);
			}
			ForwardIterator<int> fit;
			fit = test.getHead();
			for (fit; !fit.IsDone(); fit.MoveNext());
			Assert::IsTrue(fit.IsDone() && fit.GetCurrent() == test.getTail()->getData());
		}

		TEST_METHOD(BackwardIsDone)
		{
			DLList<int> test;
			int nums[] = { 5, 4, 3, 2, 1 };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(nums[i]);
			}
			BackwardIterator<int> bit;
			bit = test.getTail();
			for (bit; !bit.IsDone(); bit.MoveNext());
			Assert::IsTrue(bit.IsDone() && bit.GetCurrent() == test.getHead()->getData());
		}

		TEST_METHOD(ForwardMoveNext)
		{
			DLList<int> test;
			int nums[] = { 5, 4, 3, 2, 1 };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(nums[i]);
			}
			ForwardIterator<int> fit;
			fit = test.getHead();
			int i = 0;
			for (fit; !fit.IsDone(); fit.MoveNext())
			{
				Assert::IsTrue(fit.GetCurrent() == nums[i]);
				i++;
			}
		}

		TEST_METHOD(BackwardMoveNext)
		{
			DLList<int> test;
			int nums[] = { 5, 4, 3, 2, 1 };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(nums[i]);
			}
			BackwardIterator<int> bit;
			bit = test.getTail();
			int i = 4;
			for (bit; !bit.IsDone(); bit.MoveNext())
			{
				Assert::IsTrue(bit.GetCurrent() == nums[i]);
				i--;
			}
		}

		TEST_METHOD(ForwardAssign)
		{
			DLList<int> test;
			int nums[] = { 5, 4, 3, 2, 1 };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(nums[i]);
			}
			ForwardIterator<int> fit;
			fit = test.getTail();
			Assert::IsTrue(fit.GetCurrent() == test.getTail()->getData());
			fit = test.getHead();
			Assert::IsTrue(fit.GetCurrent() == test.getHead()->getData());
		}

		TEST_METHOD(BackwardAssign)
		{
			DLList<int> test;
			int nums[] = { 5, 4, 3, 2, 1 };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(nums[i]);
			}
			BackwardIterator<int> bit;
			bit = test.getTail();
			Assert::IsTrue(bit.GetCurrent() == test.getTail()->getData());
			bit = test.getHead();
			Assert::IsTrue(bit.GetCurrent() == test.getHead()->getData());
		}

		TEST_METHOD(ForwardStringReset)
		{
			DLList<std::string> test;
			std::string strings[] = { "One", "Two", "Three", "Four", "Five" };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(strings[i]);
			}
			ForwardIterator<std::string> fit;
			fit = test.getHead();
			for (fit; !fit.IsDone(); fit.MoveNext());
			Assert::IsTrue(fit.GetCurrent() == test.getTail()->getData());
			fit.Reset();
			Assert::IsTrue(fit.GetCurrent() == test.getHead()->getData());
		}

		TEST_METHOD(BackwardStringReset)
		{
			DLList<std::string> test;
			std::string strings[] = { "One", "Two", "Three", "Four", "Five" };
			for (size_t i = 0; i < 5; i++)
			{
				test.Append(strings[i]);
			}
			BackwardIterator<std::string> bit;
			bit = test.getTail();
			for (bit; !bit.IsDone(); bit.MoveNext());
			Assert::IsTrue(bit.GetCurrent() == test.getHead()->getData());
			bit.Reset();
			Assert::IsTrue(bit.GetCurrent() == test.getTail()->getData());
		}

	};
}
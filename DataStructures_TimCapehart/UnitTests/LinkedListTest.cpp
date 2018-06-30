#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "DLList.h"
#include "Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Iterators)
	{
	public:
		TEST_METHOD(LinkedListDefaultConstructor)
		{
			CrtCheckMemory check;
			try
			{
				DLList<int> list;

				Assert::IsTrue(list.isEmpty());
				Assert::IsNull(list.getHead());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListAppend)
		{
			CrtCheckMemory check;
			try
			{
				DLList<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				i = 0;
				for (DLLNode<size_t> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getData());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListCopyConstructor)
		{
			CrtCheckMemory check;
			try
			{
				DLList<int> aList;
				aList.Append(5);

				DLList<int> bList(aList);

				DLList<int> cList;
				DLList<int> dList(cList);

				Assert::IsFalse(bList.isEmpty());
				Assert::AreEqual(5, bList.First());
				Assert::IsTrue(dList.isEmpty());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListPrepend)
		{
			CrtCheckMemory check;
			try
			{
				DLList<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Prepend(values[i]);
				}

				i = 5;
				for (DLLNode<size_t> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[--i], DLLNode->getData());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListAccessors)
		{
			CrtCheckMemory check;
			try
			{
				DLList<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(5, aList.getHead()->getData());
				Assert::AreEqual(45, aList.getTail()->getData());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListFirstAndLast)
		{
			CrtCheckMemory check;
			try
			{
				DLList<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(5, aList.First());
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListPurge)
		{
			CrtCheckMemory check;
			try
			{
				DLList<size_t> aList;
				size_t values[] = { 5, 15, 25, 35, 45 };
				for (size_t i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				aList.Purge();

				Assert::IsNull(aList.getHead());
				Assert::IsNull(aList.getTail());
				Assert::IsTrue(aList.isEmpty());
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListExtract)
		{
			CrtCheckMemory check;
			try
			{
				DLList<int> list;

				list.Append(5);
				list.Extract(5);

				Assert::IsTrue(list.isEmpty());
				Assert::IsNull(list.getHead());

				list.Append(5);
				list.Append(10);
				list.Append(15);

				list.Extract(10);

				Assert::AreEqual(5, list.First());
				Assert::AreEqual(15, list.Last());
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListInsertAfter)
		{
			CrtCheckMemory check;
			try
			{
				DLList<int> aList;
				int i;

				int values[] = { 5, 15, 25, 35, 45 };

				aList.Append(values[0]);
				for (i = 1; i < 5; ++i)
				{
					aList.InsertAfter(values[i], values[i - 1]);
				}

				i = 0;
				for (DLLNode<int> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getData());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListBefore)
		{
			CrtCheckMemory check;
			try
			{
				DLList<int> aList;
				int i;

				int values[] = { 5, 15, 25, 35, 45 };

				aList.Append(values[4]);
				for (i = 3; i >= 0; --i)
				{
					aList.InsertBefore(values[i], values[i + 1]);
				}

				i = 0;
				for (DLLNode<int> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getData());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
		
		TEST_METHOD(LinkedListAssignmentOperator)
		{
			CrtCheckMemory check;
			try
			{
				DLList<size_t> aList;
				DLList<size_t> bList;

				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };

				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				bList = aList;

				i = 0;
				for (DLLNode<size_t> * DLLNode = bList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getData());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
	};
}
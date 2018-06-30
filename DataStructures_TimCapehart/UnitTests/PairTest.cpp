#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CrtCheckMemory.h"
#include "Pair.h"
//using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(PairTest)
	{
	public:
		
		TEST_METHOD(PairCopyConstructorTest)
		{
			// Arrange
			CrtCheckMemory check;
			Pair<int, int> pair1(5, 10);

			// Act
			Pair<int, int> pair2(pair1);


			// Assert
			Assert::IsTrue(pair1.GetKey() == pair2.GetKey() && pair1.GetValue() == pair1.GetValue());
		}

		TEST_METHOD(PairParamConstructor)
		{
			CrtCheckMemory check;
			Pair<int, int> pair1(5, 6);
			Assert::IsTrue(pair1.GetKey() == 5 && pair1.GetValue() == 6);
		}
		TEST_METHOD(PairAssign)
		{
			CrtCheckMemory check;
			Pair<int, int> pair1(4, 2);
			Pair<int, int> pair2;

			try
			{
				pair2 = pair1;
			}
			catch (Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
			}
			Assert::IsTrue(pair2.GetKey() == pair1.GetKey() && pair2.GetValue() == pair1.GetValue());
		}

		TEST_METHOD(EqualToOperator)
		{
			CrtCheckMemory check;
			Pair<int, int> pair1(5, 6);
			Pair<int, int> pair2(5, 6);
			bool pass = false;
			if (pair1 == pair2)
			{
				pass = true;
			}
			Assert::IsTrue(pass);

		}
	};
}
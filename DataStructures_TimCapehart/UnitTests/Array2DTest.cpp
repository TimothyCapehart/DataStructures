#include "stdafx.h"
#include "CppUnitTest.h"
#include<iostream>
#include "CrtCheckMemory.h"
#include "Array2D.h"
#include "Row.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Array2DTest)
	{
	public:
		TEST_METHOD(A2DNoArgConstructor)
		{
			CrtCheckMemory check;
			Array2D<int> test;
			Assert::IsTrue(test.getRow() == 1 && test.getColumn() == 1);
		}

		TEST_METHOD(A2DParamConstructorBadRow)
		{
			CrtCheckMemory check;
			//bad row
			auto badRow = [this] {Array2D<int> test1(-1, 2); };
			Assert::ExpectException<Exception>(badRow);
		}

		TEST_METHOD(A2DParamConstructorBadCol)
		{
			CrtCheckMemory check;
			//bad column
			auto badCol = [this] {Array2D<int> test2(2, -1); };
			Assert::ExpectException<Exception>(badCol);
		}

		TEST_METHOD(A2DParamConstructorBadBoth)
		{
			CrtCheckMemory check;
			//both bad
			auto badBoth = [this] {Array2D<int> test3(0, 0); };
			Assert::ExpectException<Exception>(badBoth);
		}

		TEST_METHOD(A2DParamConstructorGood)
		{
			CrtCheckMemory check;
			//good
			Array2D<int> test4(10, 5);
			Assert::IsTrue(test4.getRow() == 10 && test4.getColumn() == 5);
		}

		TEST_METHOD(A2DCopyConstructor)
		{

			CrtCheckMemory check;
			int k = 0;
			Array2D<int> test(5, 5);
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					test[i][j] = k++;
				}
			}
			Array2D<int> copy(test);
			for (int i = 0; i < copy.getRow(); i++)
			{
				for (int j = 0; j < copy.getColumn(); j++)
				{
					if (copy[i][j] != test[i][j])
					{
						Assert::Fail();
					}
				}
			}
		}

		TEST_METHOD(A2DAssignOperator)
		{
			CrtCheckMemory check;
			Array2D<int> lhs(5, 5);
			Array2D<int> rhs(2, 3);
			int k = 0;
			for (int i = 0; i < lhs.getRow(); i++)
			{
				for (int j = 0; j < lhs.getColumn(); j++)
				{
					lhs[i][j] = k++;
				}
			}

			//Act
			rhs = lhs;

			bool pass = true;
			for (int i = 0; i < rhs.getRow(); i++)
			{
				for (int j = 0; j < rhs.getColumn(); j++)
				{
					if (lhs[i][j] != rhs[i][j])
					{
						pass = false;
					}
				}
			}

			Assert::IsTrue(rhs.getRow() == lhs.getRow() && rhs.getColumn() == lhs.getColumn()
				&& rhs.getSize() == lhs.getSize() && pass);
		}

		TEST_METHOD(A2DBracketOperator)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 2);
			int k = 0;
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					test[i][j] = k++;
				}
			}
			Row<int>rhs(test, 1);
			for (int i = 0; i < test.getColumn(); i++)
			{
				if (test[1][i] != rhs[i])
					Assert::Fail();
			}
		}
		TEST_METHOD(A2DSelect)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);
			int k = 0;
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					test[i][j] = k++;
				}
			}
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					if (test[i][j] != test.Select(i, j))
					{
						Assert::Fail();
					}
				}
			}

		}

		TEST_METHOD(A2DGetRow)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);
			Assert::IsTrue(test.getRow() == 5);
		}

		TEST_METHOD(A2DGetColumn)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);
			Assert::IsTrue(test.getColumn() == 5);
		}

		TEST_METHOD(A2DGetSize)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);
			Assert::IsTrue(test.getSize() == 25);
		}

		TEST_METHOD(A2DSetRowOOBLow)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);
			
			try
			{
				test.setRow(0);
			}
			catch (Exception &e)
			{
				//expected
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(A2DSetRowOOBHigh)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);

			try
			{
				test.setRow(6);
			}
			catch (Exception &e)
			{
				//expected
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(A2DSetRowGood)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);

			test.setRow(3);

			Assert::IsTrue(test.getRow() == 3 && test.getSize() == 15);
		}

		TEST_METHOD(A2DSetColOOBLow)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);

			try
			{
				test.setColumn(0);
			}
			catch (Exception &e)
			{
				//expected
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(A2DSetColOOBHigh)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);

			try
			{
				test.setColumn(6);
			}
			catch (Exception &e)
			{
				//expected
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(A2DSetColGood)
		{
			CrtCheckMemory check;
			Array2D<int> test(5, 5);

			test.setColumn(3);

			Assert::IsTrue(test.getColumn() == 3 && test.getSize() == 15);
		}

		TEST_METHOD(Array2DSetColumnDataLossTest)

		{
			CrtCheckMemory check;
			Array2D<int> myArray(3, 3);
			int index = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					myArray[i][j] = index++;

			myArray.setColumn(2);

			int total = 0;

			for (int i = 0; i < myArray.getRow(); i++)
				for (int j = 0; j < myArray.getColumn(); j++)
					total += myArray[i][j];

			Assert::IsTrue(total == 21);
		}
	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include<iostream>
#include "CrtCheckMemory.h"
#include "Array2DP.h"
#include "RowP.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Array2DPTest)
	{
	public:
		TEST_METHOD(A2DPNoArgConstructor)
		{
			CrtCheckMemory check;
			Array2DP<int> test;
			Assert::IsTrue(test.getRow() == 1 && test.getColumn() == 1);
		}

		TEST_METHOD(A2DPParamConstructorGood)
		{
			CrtCheckMemory check;
			Array2DP<int> test(5, 5);
			Assert::IsTrue(test.getRow() == 5 && test.getColumn() == 5 && test.getSize() == 25);
		}

		TEST_METHOD(A2DPParamConstructorBadRow)
		{
			CrtCheckMemory check;
			auto badRow = [this] {Array2DP<int> test1(-1, 2); };
			Assert::ExpectException<Exception>(badRow);
		}

		TEST_METHOD(A2DPParamConstructorBadCol)
		{
			CrtCheckMemory check;
			auto badCol = [this] {Array2DP<int> test1(2, -1); };
			Assert::ExpectException<Exception>(badCol);
		}

		TEST_METHOD(A2DPParamConstructorBadBoth)
		{
			CrtCheckMemory check;
			auto badBoth = [this] {Array2DP<int> test1(-1, -2); };
			Assert::ExpectException<Exception>(badBoth);
		}

		TEST_METHOD(A2DPCopyConstructor)
		{

			CrtCheckMemory check;
			int k = 0;
			Array2DP<int> test(5, 5);
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					test[i][j] = k++;
				}
			}
			Array2DP<int> copy(test);
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

		TEST_METHOD(A2DPAssignOperator)
		{
			CrtCheckMemory check;
			{
				
				Array2DP<int> lhs(5, 5);
				Array2DP<int> rhs(2, 3);
				int k = 0;
				for (int i = 0; i < lhs.getRow(); i++)
				{
					for (int j = 0; j < lhs.getColumn(); j++)
					{
						lhs[i][j] = k++;
					}
				}
				//Act
				try
				{
					rhs = lhs;
				}
				catch (Exception &e)
				{
					std::cerr << e.getMessage() << std::endl;
				}
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
		}

		TEST_METHOD(A2DPSelect)
		{
			CrtCheckMemory check;
			Array2DP<int> test(5, 5);
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
					if (test.Select(i, j) != test[i][j])
					{
						Assert::Fail();
					}
				}
			}
			
		}

		TEST_METHOD(A2DPSetRowLose)
		{
			CrtCheckMemory check;
			Array2DP<int> test(5, 6);
			int k = 0;
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					test[i][j] = k++;
				}
			}
			Array2DP<int> copy(test);

			test.setRow(3);
			
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					if (test[i][j] != copy[i][j])
					{
						Assert::Fail();
					}
				}
			}
			
		}

		TEST_METHOD(A2DPSetRowAdd)
		{
			CrtCheckMemory check;
			Array2DP<int> test(5, 6);
			int k = 0;
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					test[i][j] = k++;
				}
			}
			test.setRow(10);
			
			Assert::IsTrue(test.getRow() == 10 && test.getSize() == 60);
		}

		TEST_METHOD(A2DPSetColumnLose)
		{
			CrtCheckMemory check;
			Array2DP<int> test(5, 6);
			int k = 0;
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					test[i][j] = k++;
				}
			}
			Array2DP<int> copy(test);
			test.setColumn(2);
			bool pass = true;
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					if (test[i][j] != copy[i][j])
					{
						pass = false;
					}
				}
			}
			Assert::IsTrue(test.getSize() == 10 && pass);
		}

		TEST_METHOD(A2DPSetColumnAdd)
		{
			CrtCheckMemory check;
			Array2DP<int> test(5, 6);
			int k = 0;
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < test.getColumn(); j++)
				{
					test[i][j] = k++;
				}
			}
			Array2DP<int> copy(test);
			test.setColumn(10);
			bool pass = true;
			for (int i = 0; i < test.getRow(); i++)
			{
				for (int j = 0; j < copy.getColumn(); j++)
				{
					if (test[i][j] != copy[i][j])
					{
						pass = false;
					}
				}
			}
			Assert::IsTrue(test.getSize() == 50 && pass);
		}
	};
}


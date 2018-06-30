#include "stdafx.h"
#include "CppUnitTest.h"
#include<iostream>
#include "CrtCheckMemory.h"
#include "Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ArrayTest)
	{
	public:

		TEST_METHOD(StringArrayReduceLengthTest)

		{
			Array<std::string> myStringArray;

			bool pass = true;

			myStringArray.setLength(10);

			for (int i = 0; i < 10; i++)
				myStringArray[i] = ("Test String " + i);

			myStringArray.setLength(5);

			for (int i = 0; i < 5; i++)
			{
				if (myStringArray[i] != "Test String " + i)
					pass = false;
			}
			Assert::IsTrue(pass);
		}

		TEST_METHOD(ArrayNoArgConstructor)
		{
			//Arrange
			CrtCheckMemory check;
			bool thrown = false;
			
			//Act
			try
			{
				Array<int> testArray;
			}
			catch (Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
				thrown = true;
			}

			//Assert
			Assert::IsTrue(!thrown);
		}

		TEST_METHOD(Array1ArgConstructor)
		{
			//Arrange
			CrtCheckMemory check;
			bool valid_index = true;
			bool invalid_index = true;
			//Act
			try 
			{
				Array<int> testArray1(10);
			}
			catch (Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
				valid_index = false;
			}
			try
			{
				Array<int> testArray2(-1);
			}
			catch (Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
				invalid_index = false;
			}

			//Assert
			Assert::IsTrue(valid_index && !invalid_index);
		}

		TEST_METHOD(Array2ArgConstructor)
		{
			//Arrange
			CrtCheckMemory check;
			bool vlvi = true; bool ilvi = true; // vlvi = valid length, valid index... all indexes are valid

			//Act
			try // valid length, valid index
			{
				Array<int> testArray1(10, 0);
			}
			catch (Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
				vlvi = false;
			}
			try // invalid length, valid index 
			{
				Array<int> testArray2(-1, -10);
			}
			catch (Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
				ilvi = false;
			}
			Assert::IsTrue(vlvi && !ilvi);
		}
		
		TEST_METHOD(ArrayCopyConstructor)
		{
			//Arrange
			CrtCheckMemory check;
			bool pass = true;
			Array<int> copyArray(10, 0);
			int j = 0;
			for (int i = copyArray.getStartIndex(); i < copyArray.getStartIndex() + copyArray.getLength(); i++)
			{
				copyArray[i] = j++;
			}
			
			//Act
			Array<int> testArray(copyArray);
			
			for (int i = testArray.getStartIndex(); i < testArray.getLength() + testArray.getStartIndex(); i++)
			{
				if (copyArray[i] != testArray[i])
				{
					pass = false;
					break;
				}
			}
			
			//Assert
			Assert::IsTrue(testArray.getLength() == copyArray.getLength() && 
				testArray.getStartIndex() == copyArray.getStartIndex() && pass);
		}

		TEST_METHOD(ArrayAssignOperator)
		{
			//Arrange
			CrtCheckMemory check;
			Array<int> testArray1(10, 0);
			Array<int> testArray2(15, -10);

			//Act
			for (int i = 0; i < 10; i++)
			{
				testArray1[i] = i;
			}
			try
			{
				testArray2 = testArray1;
			}
			catch (Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
			}
			bool pass = true;
			for (int i = 0; i < testArray2.getLength(); i++)
			{
				if (testArray2[i] != testArray1[i])
					pass = false;
			}
			//Assert
			Assert::IsTrue(pass && testArray1.getLength() == testArray2.getLength() &&
				testArray1.getStartIndex() == testArray2.getStartIndex());
		}

		TEST_METHOD(ArrayGetStartIndex)
		{
			//Arrange
			CrtCheckMemory check;
			Array<int> testArray1(10, -5);
			Array<int> testArray2(10, 0);

			//Assert
			Assert::IsTrue(testArray1.getStartIndex() == -5 && testArray2.getStartIndex() == 0);
		}

		TEST_METHOD(ArrayGetLength)
		{
			//Arrange
			CrtCheckMemory check;
			Array<int> testArray1(10, 0);
			Array<int> testArray2(3, 0);

			//Assert
			Assert::IsTrue(testArray1.getLength() == 10 && testArray2.getLength() == 3);
		}
		
		TEST_METHOD(ArraySetLength)
		{
			//Arrange
			CrtCheckMemory check;
			Array<int> testArray1(10, 0);
			Array<int> testArray2(10, 0);
			Array<int> testArray3(10, 0);
			Array<int> testArray4(10, 0);

			//Act
			bool equal = true; bool larger = true; bool smaller = true; bool invalid = true;
			
			try
			{
				testArray1.setLength(10); // equal
			}
			catch (Exception &ex)
			{
				std::cerr << ex.getMessage() << std::endl;
				equal = false;
			}
			try
			{
				testArray2.setLength(15); // larger
			}
			catch (Exception &ex)
			{
				std::cerr << ex.getMessage() << std::endl;
				larger = false;
			}try
			{
				testArray3.setLength(5); // smaller
			}
			catch (Exception &ex)
			{
				std::cerr << ex.getMessage() << std::endl;
				smaller = false;
			}try
			{
				testArray4.setLength(0); // invalid 
			}
			catch (Exception &ex)
			{
				std::cerr << ex.getMessage() << std::endl;
				invalid = false;
			}
			
			//Assert
			Assert::IsTrue(equal && larger && smaller && !invalid);
		}
		
		TEST_METHOD(ArrayBracketOperator)
		{
			//Arrange
			CrtCheckMemory check;
			Array<int> testArray(10, -5);
			bool inbounds = true; bool outhigh = false; bool outlow = false;
			for (int i = testArray.getStartIndex(); i < testArray.getLength() + testArray.getStartIndex(); i++)
			{
				testArray[i] = i;
			}
			
			//Act
			try // in bounds
			{
				testArray[-1];
			}
			catch (Exception &ex)
			{
				std::cerr << ex.getMessage() << std::endl;
				inbounds = false;
			}
			try // out of bounds high
			{
				testArray[6];
			}
			catch (Exception &ex)
			{
				std::cerr << ex.getMessage() << std::endl;
				outhigh = true;
			}
			try
			{
				testArray[-6];
			}
			catch (Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
				outlow = true;
			}
			//Assert
			Assert::IsTrue(inbounds && outhigh && outlow);
		}

		TEST_METHOD(ArraySetStartIndex)
		{
			//Arrange
			CrtCheckMemory check;
			Array<int> testArray1(10, 0);
			Array<int> testArray2(10, 0);

			//Act
			try
			{
				testArray1.setStartIndex(-10);
				testArray2.setStartIndex(10);
			}
			catch(Exception &e)
			{
				std::cerr << e.getMessage() << std::endl;
			}
			//Assert
			Assert::IsTrue(testArray1.getStartIndex() == -10 && testArray2.getStartIndex() == 10);
		}
	};
}
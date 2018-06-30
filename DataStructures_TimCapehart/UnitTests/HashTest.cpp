#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CrtCheckMemory.h"
#include "HashMap.h"
#include <vector>
using std::string;
using std::vector;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

static const int TABLE_SIZE = 10;

struct Book
{
	string Title;
	string Author;
	int Pages;
};

template<class K>
static int AsciiHashFunction(K key, size_t size)
{
	auto sum = 0;
	for (auto c : key)
		sum += c;
	return sum % size;
};

namespace UnitTests
{
	TEST_CLASS(HashTest)
	{
	public:
		TEST_METHOD(HashInsertTest)
		{
			HashMap<string, Book> table(10, AsciiHashFunction);
			Book book1 = { "Catcher in the Rye", "J.D. Salinger", 635 };
			table.Insert("0763757233", book1);

			Book book2 = { "Adventures of Huckleberry Finn", "Mark Twain", 452 };
			table.Insert("7063757233", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			table.Insert("7063757234", book3);

			Assert::AreEqual(book1.Title, table["0763757233"].Title);
			Assert::AreEqual(book2.Title, table["7063757233"].Title);
			Assert::AreEqual(book3.Title, table["7063757234"].Title);
		}

		TEST_METHOD(HashCopy)
		{
			HashMap<string, Book> table(10, AsciiHashFunction);
			Book book1 = { "Catcher in the Rye", "J.D. Salinger", 635 };
			table.Insert("0763757233", book1);

			Book book2 = { "Adventures of Huckleberry Finn", "Mark Twain", 452 };
			table.Insert("7063757233", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			table.Insert("7063757234", book3);

			HashMap<string, Book> copy(table);

			Assert::AreEqual(table["0763757233"].Title, copy["0763757233"].Title);
			Assert::AreEqual(table["7063757233"].Title, copy["7063757233"].Title);
			Assert::AreEqual(table["7063757234"].Title, copy["7063757234"].Title);
		}

		TEST_METHOD(HashDeleteTest)
		{
			HashMap<string, Book> table(10, AsciiHashFunction);
			Book book1 = { "Catcher in the Rye", "J.D. Salinger", 635 };
			table.Insert("0763757233", book1);

			Book book2 = { "Adventures of Huckleberry Finn", "Mark Twain", 452 };
			table.Insert("7063757233", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			table.Insert("7063757234", book3);

			table.Delete("7063757233");

			Assert::AreEqual(book1.Title, table["0763757233"].Title);
			Assert::AreEqual(book3.Title, table["7063757234"].Title);
			bool found = true;
			found = table.Find("7063757233");
			Assert::IsFalse(found);
		}

		TEST_METHOD(HashAssign)
		{
			HashMap<string, Book> table(10, AsciiHashFunction);
			Book book1 = { "Catcher in the Rye", "J.D. Salinger", 635 };
			table.Insert("0763757233", book1);

			Book book2 = { "Adventures of Huckleberry Finn", "Mark Twain", 452 };
			table.Insert("7063757233", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			table.Insert("7063757234", book3);

			HashMap<string, Book> copy1 = table;
			HashMap<string, Book> copy2(10, AsciiHashFunction);
			copy2 = table;
			
			Assert::AreEqual(table["0763757233"].Title, copy1["0763757233"].Title);
			Assert::AreEqual(table["7063757233"].Title, copy1["7063757233"].Title);
			Assert::AreEqual(table["7063757234"].Title, copy1["7063757234"].Title);

			Assert::AreEqual(table["0763757233"].Title, copy2["0763757233"].Title);
			Assert::AreEqual(table["7063757233"].Title, copy2["7063757233"].Title);
			Assert::AreEqual(table["7063757234"].Title, copy2["7063757234"].Title);
		}

		TEST_METHOD(HashUpdateTest)
		{
			HashMap<string, Book> table(10, AsciiHashFunction);
			Book book1 = { "Catcher in the Rye", "J.D. Salinger", 635 };
			table.Insert("0763757233", book1);

			Book book2 = { "Adventures of Huckleberry Finn", "Mark Twain", 452 };
			table.Insert("7063757233", book2);

			Book book3 = { "Caffeine Rehab", "Lucas Cordova", 1 };
			table.Insert("7063757234", book3);

			Book newBook = { "NewTitle", "New Author", 42 };

			table.Update("7063757234", newBook);

			Assert::AreEqual(book1.Title, table["0763757233"].Title);
			Assert::AreEqual(book2.Title, table["7063757233"].Title);
			Assert::AreEqual(newBook.Title, table["7063757234"].Title);
		}
	};
}

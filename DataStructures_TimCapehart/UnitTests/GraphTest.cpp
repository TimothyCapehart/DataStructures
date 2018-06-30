#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CrtCheckMemory.h"
#include "Graph.h"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	static vector<string> Traversal;

	TEST_CLASS(Graph_Test)
	{
	public:

		template<class V>
		static void ToVector(V data)
		{
			Traversal.push_back(data);
		}

		TEST_METHOD_INITIALIZE(Init)
		{
			Traversal.clear();
		}

		TEST_METHOD(GraphDefaultConstructorTest)
		{
			// Arrange
			CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				Assert::IsTrue(graph.IsEmpty());
			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphInsertVertextest)
		{
			// Arrange
			CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;

				string temp = "StingA";

				graph.InsertVertex(temp);

				Assert::IsFalse(graph.IsEmpty());
			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphDeleteVertextest)
		{
			// Arrange
			//CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;

				graph.InsertVertex("StringA");
				graph.InsertVertex("StringB");

				graph.DeleteVertex("StringB");

				graph.SetFunction(ToVector);
				graph.BreadthFirst();

				string array1[] = { "StringA" };

				for (int i = 0; i < Traversal.size(); i++)
				{
					Assert::AreEqual(array1[i], Traversal[i]);
				}

				Assert::IsFalse(graph.IsEmpty());
			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphInsertArcTest)
		{
			// Arrange
			//	CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				string stringA = "StringA";
				string stringB = "StringB";
				graph.InsertVertex("StringA");
				graph.InsertVertex(stringB);

				Arc<string, string> arcA(graph.GetVertex("StringA"), 5, "name");
				Arc<string, string> arcB(graph.GetVertex("StringB"), 5, "name");
				graph.InsertArc("StringB", "StringA", arcA);
				graph.InsertArc("StringA", "StringB", arcB);

				graph.SetFunction(ToVector);
				graph.BreadthFirst();

				string array1[] = { "StringA", "StringB" };

				for (int i = 0; i < Traversal.size(); i++)
				{
					Assert::AreEqual(array1[i], Traversal[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphDeleteArcTest)
		{
			// Arrange
			//CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				Vertex<string, string> * Vertex1, *Vertex2;
				string stringA = "StringA";
				string stringB = "StringB";
				graph.InsertVertex("StringA");
				graph.InsertVertex(stringB);

				Arc<string, string> arcA(graph.GetVertex("StringA"), 5, "name");
				Arc<string, string> arcB(graph.GetVertex("StringB"), 5, "name");
				graph.InsertArc("StringB", "StringA", arcA);
				graph.InsertArc("StringA", "StringB", arcB);

				graph.DeleteArc("StringB", "StringA", arcA);
				graph.DeleteArc("StringA", "StringB", arcB);

				graph.SetFunction(ToVector);
				graph.BreadthFirst();

				string array1[] = { "StringA" };

				for (int i = 0; i < Traversal.size(); i++)
				{
					Assert::AreEqual(array1[i], Traversal[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphDepthFirstTest)
		{
			// Arrange
			//CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				Vertex<string, string> * Vertex1, *Vertex2;
				string stringA = "StringA";
				string stringB = "StringB";
				graph.InsertVertex("StringA");
				graph.InsertVertex(stringB);

				Arc<string, string> arcA(graph.GetVertex("StringA"), 5, "name");
				Arc<string, string> arcB(graph.GetVertex("StringB"), 5, "name");
				graph.InsertArc("StringB", "StringA", arcA);
				graph.InsertArc("StringA", "StringB", arcB);

				graph.SetFunction(ToVector);
				graph.DepthFirst();

				string array1[] = { "StringA", "StringB" };

				for (int i = 0; i < Traversal.size(); i++)
				{
					Assert::AreEqual(array1[i], Traversal[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphCopyTest)
		{
			// Arrange
			//CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				string stringA = "StringA";
				string stringB = "StringB";
				graph.InsertVertex("StringA");
				graph.InsertVertex(stringB);

				Arc<string, string> arcA(graph.GetVertex("StringA"), 5, "name");
				Arc<string, string> arcB(graph.GetVertex("StringB"), 5, "name");
				graph.InsertArc("StringB", "StringA", arcA);
				graph.InsertArc("StringA", "StringB", arcB);

				Graph<string, string> graph2(graph);

				graph2.SetFunction(ToVector);
				graph2.BreadthFirst();

				string array1[] = { "StringA", "StringB" };

				for (int i = 0; i < Traversal.size(); i++)
				{
					Assert::AreEqual(array1[i], Traversal[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphAssignmentTest)
		{
			// Arrange
			//CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;
				string stringA = "StringA";
				string stringB = "StringB";
				graph.InsertVertex("StringA");
				graph.InsertVertex(stringB);

				Arc<string, string> arcA(graph.GetVertex("StringA"), 5, "name");
				Arc<string, string> arcB(graph.GetVertex("StringB"), 5, "name");
				graph.InsertArc("StringA", "StringB", arcB);
				graph.InsertArc("StringB", "StringA", arcA);

				Graph<string, string> graph2 = graph;

				graph2.SetFunction(ToVector);
				graph2.BreadthFirst();

				string array1[] = { "StringA", "StringB" };

				for (int i = 0; i < Traversal.size(); i++)
				{
					Assert::AreEqual(array1[i], Traversal[i]);
				}

			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(GraphPurgetest)
		{
			// Arrange
			CrtCheckMemory check;
			try
			{
				Graph<string, string> graph;

				string temp = "StringA";

				graph.InsertVertex(temp);

				Assert::IsFalse(graph.IsEmpty());
				graph.Purge();
				Assert::IsTrue(graph.IsEmpty());
			}
			catch (std::bad_alloc &ba)
			{
				Assert::IsTrue(true);
			}
		}
	};
}

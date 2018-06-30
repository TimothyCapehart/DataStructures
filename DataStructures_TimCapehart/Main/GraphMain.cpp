//#include <iostream>
//#include <crtdbg.h>
//#include "Graph.h"
//#include <typeinfo>
//
//using namespace std;
//#define _CRTDBG_MAP_ALLOC
//
//template<class V>
//inline void Visit(V it)
//{
//	//if (it != nullptr)
//	std::cout << it << ' ';
//};
//
////int main()
////{
//
//
//	/*Graph<char, int> graph2;
//	Graph<char, int> graph;
//	
//	graph.InsertVertex('A');
//	graph.InsertVertex('X');
//	graph.InsertVertex('G');
//	graph.InsertVertex('H');
//	graph.InsertVertex('P');
//	graph.InsertVertex('E');
//	graph.InsertVertex('Y');
//	graph.InsertVertex('M');
//	graph.InsertVertex('J');
//
//
//	graph.InsertArc('A', 'X', 0);
//	graph.InsertArc('X', 'H', 0);
//	graph.InsertArc('X', 'G', 0);
//	graph.InsertArc('G', 'P', 0);
//	graph.InsertArc('H', 'P', 0);
//	graph.InsertArc('H', 'E', 0);
//	graph.InsertArc('E', 'Y', 0);
//	graph.InsertArc('E', 'M', 0);
//	graph.InsertArc('Y', 'M', 0);
//	graph.InsertArc('M', 'J', 0);
//	graph.InsertArc('J', 'A', 0);
//
//	graph2 = graph;
//	Graph<char, int> copy(graph);
//
//	graph.SetFunction(Visit);
//	cout << "graph" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//	cout << "graph2" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//	cout << "copy" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//
//	graph.DeleteVertex('Y');
//
//	graph.SetFunction(Visit);
//	cout << "graph" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//	cout << "graph2" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//	cout << "copy" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//
//	graph.DeleteVertex('H');
//
//	graph.SetFunction(Visit);
//	cout << "graph" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//	cout << "graph2" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//	cout << "copy" << endl;
//	graph.DepthFirst();
//	cout << endl;
//	graph.BreadthFirst();
//	cout << endl;
//*/
////	cin.get();
////	return 0;
////
////}
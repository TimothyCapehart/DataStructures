//#include "Dijkstra.h"
//#include "CrtDbg.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	char again;
//	string infile = R"(C:\Users\tcape\source\repos\DataStructures\DataStructures_TimCapehart\DataStructures\Arcs.txt)";
//	Dijkstra dijkstra;
//	Shortest path;
//	try
//	{
//		dijkstra.Build(infile);
//	}
//	catch (Exception &e)
//	{
//		cout << e.getMessage() << endl;
//	}
//	do
//	{
//		string origin, dest;
//		cout << "Enter an origin and a destination to get the shortest path:\n";
//		cout << "Origin: ";
//		getline(cin, origin);
//		while (dijkstra.GetGraph().GetVertex(origin) == nullptr)
//		{
//			cout << "\nOrigin not found.\n";
//			cout << "Origin: ";
//			getline(cin, origin);
//		}
//		cout << "Destination: ";
//		getline(cin, dest);
//		while (dijkstra.GetGraph().GetVertex(dest) == nullptr)
//		{
//			cout << "\nDestination not found.\n";
//			cout << "Destination: ";
//			getline(cin, dest);
//		}
//
//		path = dijkstra.ShortestPath(origin, dest);
//		stack<string> directions = path.GetDirection();
//
//		cout << "\nThe shortest path from " << origin << " to " << dest << " is... " << endl;
//		while (!directions.empty())
//		{
//			cout << directions.top();
//			directions.pop();
//			if (!directions.empty())
//				cout << ", ";
//		}
//		cout << "\nTotal Distance = " << path.GetDistance() << " miles." << endl;
//		cout << "Total Time =  " << path.GetTime() << " hours." << endl;
//		cout << "\n\nFind another path? (y/n)";
//		cin >> again;
//		while (again != 'y' && again != 'Y' && again != 'n' && again != 'N')
//		{
//			cout << "Invalid. Re-enter:";
//			cin >> again;
//		}
//		again = toupper(again);
//		cin.clear();
//		cin.ignore();
//		cout << endl;
//	} while (again == 'Y');
//	return 0;
//}
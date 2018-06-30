//#include <crtdbg.h>
//#include <cassert>
//#include <iostream>
//#include "ForwardIterator.h"
//#include "BackwardIterator.h"
//#include "DLList.h"  
//#include "Exception.h"
//#include "Minesweeper.h"
//#include "ArrayQueue.h"

//int main()
//{
//	/*char again;
//	do
//	{
//		try
//		{
//			Minesweeper game;
//			SetConsoleTextAttribute(hConsole, WHITE);
//			game.chooseLevel();
//			game.setDisplays();
//			int choice;
//			game.print();
//			do
//			{
//				game.menu(choice);
//				game.update(choice);
//			} while (choice != 3 && !game.getGameOver());
//		}
//		catch (Exception &e)
//		{
//			std::cout << e.getMessage();
//		}
//		catch (...)
//		{
//			std::cout << "error.";
//		}
//		cout << "\nPlay again? (y / n): ";
//		try
//		{
//			std::cin >> again;
//			while (cin.fail() || again != 'y' && again != 'Y' && again != 'n' && again != 'N') 
//			{
//				cout << "Invalid. Re-enter." << endl;
//				cin.clear();
//				cin.ignore();
//				cin >> again;
//			}
//		}
//		catch (...)
//		{
//			std::cout << "Error." << std::endl;
//			std::cin.clear();
//			std::cin.ignore();
//			cin >> again;
//		}
//		again = toupper(again);
//	} while (again == 'Y');
//	
//	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
//	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
//	_CrtDumpMemoryLeaks();
//
//	std::cin.get();*/
//
//
//	return 0;
//}
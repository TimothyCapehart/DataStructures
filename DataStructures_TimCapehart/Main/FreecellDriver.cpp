//#include "FreeCell.h"
//
//int main()
//{
//	char again;
//	do
//	{
//		FreeCell game;
//		int choice;
//		do
//		{
//			game.Update();
//			game.Menu(choice);
//		} while (choice != 6 && !game.IsGameOver());
//		cout << "\nPlay again? (y/n): ";
//		cin >> again;
//		while (cin.fail() || again != 'y' && again != 'Y' && again != 'n' && again != 'N')
//		{
//			cout << "Invalid. Re-enter." << endl;
//			cin.clear();
//			cin.ignore();
//			cin >> again;
//		}
//		again = toupper(again);
//	} while (again == 'Y');
//	cin.get();
//	return 0;
//}
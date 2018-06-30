#ifndef FREECELL_H
#define FREECELL_H
#include "FCBoard.h"
using std::cin;

class FreeCell
{
private:
	FCBoard * _board;
	int _moveCol;
	int _destCol;
	bool _gameOver = false;
public:
	FreeCell();
	~FreeCell();

	void Menu(int & choice);
	void GetInput(int & move, int & dest);
	void GetInputFree(int & move, int & dest);
	void GetInputFreePlay(int & move, int & dest);
	void GetInputPlayPlay(int & move, int & dest);
	void Update();
	void GameOver();
	bool IsGameOver() { return _gameOver; }
};

FreeCell::FreeCell()
{
	_board = new FCBoard;
	_board->Deal();
}

FreeCell::~FreeCell()
{
	delete _board;
}

void FreeCell::Menu(int & choice)
{
	cout << "\n\n\n\n Move:\n";
	cout << " 1. Play Card to Free Cell" << endl;
	cout << " 2. Play Card to Home Stack" << endl;
	cout << " 3. Play Card to Play Card" << endl;
	cout << " 4. Free Card to Play Cards" << endl;
	cout << " 5. Free Card to Home Cell" << endl;
	cout << " 6. Quit\n >";
	cin >> choice;
	while (!cin || choice < 1 || choice > 6)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> choice;
	}
	switch (choice)
	{
	case 1:
		GetInput(_moveCol, _destCol);
		try
		{
			_board->MoveToFree(_moveCol, _destCol);
		}
		catch (Exception & e)
		{
			cout << e.getMessage() << endl;
		}
		break;
	case 2:
		GetInput(_moveCol, _destCol);
		try
		{
			_board->MovePlayToHome(_moveCol, _destCol);
		}
		catch (Exception & e)
		{
			cout << e.getMessage() << endl;
		}
		break;
	case 3:
		GetInputPlayPlay(_moveCol, _destCol);
		try
		{
			_board->MovePlayToPlay(_moveCol, _destCol);
		}
		catch (Exception & e)
		{
			cout << e.getMessage() << endl;
		}
		break;
	case 4:
		GetInputFreePlay(_moveCol, _destCol);
		try
		{
			_board->MoveFreeToPlay(_moveCol, _destCol);
		}
		catch (Exception & e)
		{
			cout << e.getMessage() << endl;
		}
		break;
			
	case 5: 
		GetInputFree(_moveCol, _destCol);
		try
		{
			_board->MoveFreeToHome(_moveCol, _destCol);
		}
		catch (Exception & e)
		{
			cout << e.getMessage() << endl;
		}
		break;
	case 6: break;
	}
}

void FreeCell::GetInput(int & move, int & dest)
{
	cout << "\nMove from #: ";
	cin >> move;
	while (!cin || move < 1 || move > 8)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> move;
	}
	move--;
	cout << "\nMove to #: ";
	cin >> dest;
	while (!cin || dest < 1 || dest > 4)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> dest;
	}
	dest--;
}

void FreeCell::GetInputFree(int & move, int & dest)
{
	cout << "\nMove from #: ";
	cin >> move;
	while (!cin || move < 1 || move > 4)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> move;
	}
	move--;
	cout << "\nMove to #: ";
	cin >> dest;
	while (!cin || dest < 1 || dest > 4)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> dest;
	}
	dest--;
}

void FreeCell::GetInputFreePlay(int & move, int & dest)
{
	cout << "\nMove from #: ";
	cin >> move;
	while (!cin || move < 1 || move > 4)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> move;
	}
	move--;
	cout << "\nMove to #: ";
	cin >> dest;
	while (!cin || dest < 1 || dest > 8)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> dest;
	}
	dest--;
}

void FreeCell::GetInputPlayPlay(int & move, int & dest)
{
	cout << "\nMove from #: ";
	cin >> move;
	while (!cin || move < 1 || move > 8)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> move;
	}
	move--;
	cout << "\nMove to #: ";
	cin >> dest;
	while (!cin || dest < 1 || dest > 8)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> dest;
	}
	dest--;
}

void FreeCell::Update()
{
	if (_board->Win())
	{
		cout << "\n\nYOU WIN!!!\n\n";
		GameOver();
	}
	else
	{
		_board->SetDisplays();
		_board->Print();
	}
}

void FreeCell::GameOver()
{
	_gameOver == true;
}
#endif
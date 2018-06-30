#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Board.h"

class Minesweeper
{
private:
	bool _gameOver = false;
	bool _win = false;
	bool _lose = false;
	Board * _game;
	int _row;
	int _col;

public:
	Minesweeper();
	~Minesweeper();

	void chooseLevel();
	void menu(int & choice);
	void update(int & choice);
	void gameOver() { _gameOver = true; };
	bool getGameOver() { return _gameOver; };
	bool checkWin();
	bool checkLose();
	void print();
	void setDisplays() { _game->setDisplays(); };
	void getInput(int & row, int & col);

};

Minesweeper::Minesweeper()
{
	_gameOver = false;
}

Minesweeper::~Minesweeper()
{
	delete _game;
}

void Minesweeper::chooseLevel()
{
	char choice;
	std::cout << "\n\nChoose difficulty (b = beginner, i = intermediate, e = expert): ";
	try
	{
		std::cin >> choice;
		while (cin.fail() || choice != 'b' && choice != 'B' && choice != 'i' && choice != 'I' && choice != 'e' && choice != 'E')
		{
			cout << "Invalid. Re-enter." << endl;
			cin.clear();
			cin.ignore();
			cin >> choice;
		}
	}
	catch (...)
	{
		std::cout << "Error." << std::endl;
		std::cin.clear();
		std::cin.ignore();
		cin >> choice;
	}
	choice = toupper(choice);

	_game = new Board(choice);
	_game->genBombPos();
	_game->setBombs();
	_game->setCellBools();
	_game->setAdjacents();
	
}

void Minesweeper::getInput(int & row, int & col)
{
	try
	{
		std::cout << "\nEnter Cell (ROW -space- COL): ";
		cin.clear();
		cin >> row;
		while (cin.fail() || row < 0 || row > _game->_rows)
		{
			cout << "\nInvalid entry. Re-enter: ";
			cin.clear();
			cin.ignore();
			cin >> row;
		}
	}
	catch (...)
	{
		std::cout << "Error." << std::endl;
		std::cin.clear();
		std::cin.ignore();
		cin >> row;
	}
	try
	{
		cin >> col;
		while (cin.fail() || col < 0 || col > _game->_cols)
		{
			cout << "\nInvalid entry. Re-enter column: ";
			cin.clear();
			cin.ignore();
			cin >> col;
		}
	}
	catch (...)
	{
		std::cout << "Error." << endl;
		getInput(row, col);
	}
}

void Minesweeper::menu(int & choice)
{
	std::cout << "\n\nChoose: \n";
	std::cout << "1. Check Cell\n";
	std::cout << "2. Set Flag\n";
	std::cout << "3. Quit\n";
	std::cin >> choice;
	while (!cin || choice < 1 || choice > 3)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid. Re-enter: ";
		std::cin >> choice;
	}
	switch (choice)
	{
	case 1: 
	{
		int row, col;
		getInput(row, col);
		if (_game->checkCell(row, col))
		{
			_game->setDisplays();
			_game->print();
			std::cout << "\nBOOM!!!\n" << std::endl;
			gameOver();
		}	
		break;
	}
	case 2:
	{
		int row, col;
		getInput(row, col);
		_game->setFlag(row, col);
		checkWin();
		break;
	}
	case 3:
	{
		gameOver();
		break;
	}
	}
}

void Minesweeper::update(int & choice)
{
	if (_gameOver)
	{
		if (checkWin())
		{
			_game->setDisplays();
			_game->print();
			std::cout << "\nYOU WIN!!!\n" << std::endl;
			gameOver();
			std::cin.get();
			return;
		}
		else
			return;
	}
	else
	{
		_game->setDisplays();
		_game->print();
	}
}

bool Minesweeper::checkWin()
{
	if (_game->getBombs() == _game->getFlags())
	{
		gameOver();
		_win = true;
	}
	return _win;
}

bool Minesweeper::checkLose()
{
	return _lose;
}

void Minesweeper::print()
{
	_game->setDisplays();
	_game->print();
}
#endif
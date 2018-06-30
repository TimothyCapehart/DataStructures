#ifndef BOARD_H
#define BOARD_H
#include <time.h>
#include "Array2D.h"
#include "Row.h"
#include "Cell.h"
#include "Windows.h"

const size_t BLUE = 1;
const size_t YELLOW = 14;
const size_t GREEN = 10;
const size_t RED = 12;
const size_t WHITE = 15;
const size_t GREY = 8;
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Board
{
private:
	Array2D<Cell> _board;
	int _bombs = 0;
	int _flags = 0;
	char _level;
	int ** _bombPos;
	
public:
	int _rows;
	int _cols;
	Board();
	Board(char level, int row, int col, int bombs);
	Board(char level);
	~Board();

	void genBombPos();
	void setBombs();
	int getBombs() const { return _bombs; } ;
	int getBombs() { return _bombs; };
	void setAdjacents();
	void setDisplays();
	void setCellBools();
	bool checkCell(const int & row, const int & col);
	void setFlag(int row, int col);
	void print();
	void incrementFlags() { _flags++; };
	int getFlags() { return _flags; };
	void propagate(const Cell & cell);
};

Board::Board()
{
	
}

Board::Board(char level, int row, int col, int bombs)
	
{
	_board.setRow(row);
	_board.setColumn(col);
	_bombs = bombs;
	_level = level;
	_bombPos = new int *[bombs];
	for (size_t i = 0; i < bombs; i++)
	{
		_bombPos[i] = new int[2];
		_bombPos[i][0] = 0;
		_bombPos[i][1] = 0;
	}
}

Board::Board(char level)
{
	switch (level)
	{
	case 'B':
	{
		_rows = 10;
		_cols = 10;
		_board.setRow(10);
		_board.setColumn(10);
		_bombs = 10;
		_level = level;
		_bombPos = new int *[10];
		for (size_t i = 0; i < 10; i++)
		{
			_bombPos[i] = new int[2];
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				_board[i][j].setRow(i);
				_board[i][j].setCol(j);
			}
		}
		break;
	}
	case 'I':
	{
		_rows = 16;
		_cols = 16;
		_board.setRow(16);
		_board.setColumn(16);
		_bombs = 40;
		_level = level;
		_bombPos = new int *[40];
		for (size_t i = 0; i < 40; i++)
		{
			_bombPos[i] = new int[2];
		}
		for (int i = 0; i < _board.getRow(); i++)
		{
			for (int j = 0; j < _board.getColumn(); j++)
			{
				_board[i][j].setRow(i);
				_board[i][j].setCol(j);
			}
		}
		break;
	}
	case 'E':
	{
		_rows = 16;
		_cols = 30;
		_board.setRow(16);
		_board.setColumn(30);
		_bombs = 100;
		_level = level;
		_bombPos = new int *[100];
		for (size_t i = 0; i < 100; i++)
		{
			_bombPos[i] = new int[2];
			_bombPos[i][0] = 0;
			_bombPos[i][1] = 0;
		}
		for (int i = 0; i < _board.getRow(); i++)
		{
			for (int j = 0; j < _board.getColumn(); j++)
			{
				_board[i][j].setRow(i);
				_board[i][j].setCol(j);
			}
		}
		break;
	}
	}
}
Board::~Board()
{
	for (int i = 0; i < _bombs; i++)
	{
		delete[] _bombPos[i];
	}
	delete _bombPos;
}

void Board::genBombPos() 
{
	switch (_level)
	{
	case 'B':
	{
		srand(time(0)); // generate 10 numbers betweewn 0 and 99
		int num[10];
		bool used[100] = { false };
		for (size_t i = 0; i < 10; i++)
		{
			do
			{
				num[i] = rand() % 99;
			} while (used[num[i]]);
			used[num[i]] = true;
		}

		for (size_t i = 0; i < 10; i++) // convert rand numbers to corresponding cell positions
		{
			_bombPos[i][0] = num[i] / _board.getColumn();
			_bombPos[i][1] = num[i] - (_board.getColumn() * _bombPos[i][0]);
		}
		break;
	}
	case 'I':
	{
		srand(time(0)); // generate 10 numbers betweewn 0 and 255
		int num[40];
		bool used[256] = { false };
		for (size_t i = 0; i < 40; i++)
		{
			do
			{
				num[i] = rand() % 255;
			} while (used[num[i]]);
			used[num[i]] = true;
		}

		for (size_t i = 0; i < 40; i++) // convert rand numbers to corresponding cell positions
		{
			_bombPos[i][0] = num[i] / _board.getColumn();
			_bombPos[i][1] = num[i] - (_board.getColumn() * _bombPos[i][0]);
		}
		break;
	}
	case 'E':
	{
		srand(time(0)); // generate 10 numbers betweewn 0 and 479
		int num[100];
		bool used[480] = { false };
		for (size_t i = 0; i < 100; i++)
		{
			do
			{
				num[i] = rand() % 479;
			} while (used[num[i]]);
			used[num[i]] = true;
		}

		for (size_t i = 0; i < 100; i++) // convert rand numbers to corresponding cell positions
		{
			_bombPos[i][0] = num[i] / _board.getColumn();
			_bombPos[i][1] = num[i] - (_board.getColumn() * _bombPos[i][0]);
		}
		break;
	}
	default:
	{
		srand(time(0)); // generate 10 numbers betweewn 0 and 99
		int num[10];
		bool used[100] = { false };
		for (size_t i = 0; i < 10; i++)
		{
			do
			{
				num[i] = rand() % 99;
			} while (used[num[i]]);
			used[num[i]] = true;
		}

		for (size_t i = 0; i < 10; i++) // convert rand numbers to corresponding cell positions
		{
			_bombPos[i][0] = num[i] / _board.getColumn();
			_bombPos[i][1] = num[i] - (_board.getColumn() * _bombPos[i][0]);
		}
		break;
	}
	}
}

void Board::setBombs()
{
	for (size_t i = 0; i < _bombs; i++)
	{
		_board[_bombPos[i][0]][_bombPos[i][1]].setBomb(true);
	}
}

void Board::setCellBools()
{
	//corners
	_board[0][0].setTLCorner(true);
	_board[0][0].setEdge(true);
	_board[0][_board.getColumn() - 1].setTRCorner(true);
	_board[0][_board.getColumn() - 1].setEdge(true);
	_board[_board.getRow() - 1][0].setBLCorner(true);
	_board[_board.getRow() - 1][0].setEdge(true);
	_board[_board.getRow() - 1][_board.getColumn() - 1].setBRCorner(true);
	_board[_board.getRow() - 1][_board.getColumn() - 1].setEdge(true);

	//first column
	for (size_t i = 1; i < _board.getRow() - 1; i++)
	{
		_board[i][0].setFCol(true);
		_board[i][0].setEdge(true);
	}
	//last column
	for (size_t i = 1; i < _board.getRow() - 1; i++)
	{
		_board[i][_board.getColumn() - 1].setLCol(true);
		_board[i][_board.getColumn() - 1].setEdge(true);
	}
	//top row
	for (size_t i = 1; i < _board.getColumn() - 1; i++)
	{
		_board[0][i].setTRow(true);
		_board[0][i].setEdge(true);
	}
	//bottom row
	for (size_t i = 1; i < _board.getColumn() - 1; i++)
	{
		_board[_board.getRow() - 1][i].setBRow(true);
		_board[_board.getRow() - 1][i].setEdge(true);
	}
}

void Board::setAdjacents() 
{
	for (size_t i = 0; i < _bombs; i++)
	{
		if (_board[_bombPos[i][0]][_bombPos[i][1]].getTLCorner()) 
		{
			_board[_bombPos[i][0] + 1][_bombPos[i][1]].incrementAdj();
			_board[_bombPos[i][0]][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1] + 1].incrementAdj();
		}
		else if (_board[_bombPos[i][0]][_bombPos[i][1]].getTRCorner())
		{
			_board[_bombPos[i][0]][_bombPos[i][1]- 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1]].incrementAdj();
		}
		else if (_board[_bombPos[i][0]][_bombPos[i][1]].getBLCorner())
		{
			_board[_bombPos[i][0]][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1]].incrementAdj();
		}
		else if (_board[_bombPos[i][0]][_bombPos[i][1]].getBRCorner())
		{
			_board[_bombPos[i][0]][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1]].incrementAdj();
		}
		else if (_board[_bombPos[i][0]][_bombPos[i][1]].getTRow())
		{
			_board[_bombPos[i][0] + 1][_bombPos[i][1]].incrementAdj();
			_board[_bombPos[i][0]][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0]][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1] - 1].incrementAdj();
		}
		else if (_board[_bombPos[i][0]][_bombPos[i][1]].getBRow())
		{
			_board[_bombPos[i][0]][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1]].incrementAdj();
			_board[_bombPos[i][0]][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1] + 1].incrementAdj();
		}
		else if (_board[_bombPos[i][0]][_bombPos[i][1]].getFCol())
		{
			_board[_bombPos[i][0] + 1][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1]].incrementAdj();
			_board[_bombPos[i][0]][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1]].incrementAdj();
		}
		else if (_board[_bombPos[i][0]][_bombPos[i][1]].getLCol())
		{
			_board[_bombPos[i][0] - 1][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1]].incrementAdj();
			_board[_bombPos[i][0]][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1]].incrementAdj();
		}
		else
		{
			_board[_bombPos[i][0] - 1][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1]].incrementAdj();
			_board[_bombPos[i][0] - 1][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0]][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1] + 1].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1]].incrementAdj();
			_board[_bombPos[i][0] + 1][_bombPos[i][1] - 1].incrementAdj();
			_board[_bombPos[i][0]][_bombPos[i][1] - 1].incrementAdj();
		}
	}
}

void Board::setDisplays()
{
	for (size_t i = 0; i < _board.getRow(); i++)
	{
		for (size_t j = 0; j < _board.getColumn(); j++)
		{
			if (_board[i][j].getBomb() == true)
			{
				_board[i][j].setDisplay('*');
				if(_board[i][j].getFlag() == true)
					_board[i][j].setDisplay('>');
			}
			else 
			{
				char disp = '0';
				_board[i][j].setDisplay(disp + _board[i][j].getAdjacent());
				if (_board[i][j].getDisplay() == '0')
					_board[i][j].setDisplay('-');
			}
			if (!_board[i][j].getRevealed())
			{
				_board[i][j].setDisplay('o');
			}
		}
	}
}

void Board::print()
{
	SetConsoleTextAttribute(hConsole, YELLOW);
	std::cout << "\nMINESWEEPER\n\n" << std::endl;
	std::cout << "X \t";
	SetConsoleTextAttribute(hConsole, WHITE);

	for (size_t i = 0; i < 10; i++)
		std::cout << " " << i << " ";
	for (size_t i = 10; i < _board.getColumn(); i++)
		std::cout << " " << i;
	std::cout << std::endl << std::endl << std::endl;
	for (size_t i = 0; i < _board.getRow(); i++)
	{
		std::cout << i << '\t';
		for (size_t j = 0; j < _board.getColumn(); j++)
		{
			if (_board[i][j].getRevealed())
			{
				SetConsoleTextAttribute(hConsole, GREY);
				if (_board[i][j].getDisplay() == '*')
					SetConsoleTextAttribute(hConsole, RED);

				else if (_board[i][j].getDisplay() == '>')
					SetConsoleTextAttribute(hConsole, GREEN);
			}
			std::cout << " " << _board[i][j].getDisplay() << " ";
			SetConsoleTextAttribute(hConsole, WHITE);
		}
		std::cout << std::endl;
	}
}

bool Board::checkCell(const int & row, const int & col)
{
	_board[row][col].setRevealed(true);
	if (!_board[row][col].getBomb())
		propagate(_board[row][col]);
	return (_board[row][col].getBomb());
}

void Board::setFlag(int row, int col)
{
	_board[row][col].setRevealed(true);
	if (_board[row][col].getBomb())
	{
		incrementFlags();
		_board[row][col].setFlag(true);
		setDisplays();
	}
	else
	{
		_board[row][col].setFlag(true);
		setDisplays();
	}
}

void Board::propagate(const Cell & cell)
{
	const int cellRow = cell.getRow();
	const int cellCol = cell.getCol();
	if (cell.getAdjacent() == 0)
	{
		if (!cell.getEdge())
		{
			_board[cellRow - 1][cellCol - 1].setRevealed(true);
			_board[cellRow - 1][cellCol].setRevealed(true);
			_board[cellRow - 1][cellCol + 1].setRevealed(true);
			_board[cellRow + 1][cellCol + 1].setRevealed(true);
			_board[cellRow + 1][cellCol - 1].setRevealed(true);
			_board[cellRow + 1][cellCol].setRevealed(true);
			_board[cellRow][cellCol - 1].setRevealed(true);
			_board[cellRow][cellCol + 1].setRevealed(true);
			if (_board[cellRow + 1][cellCol + 1].getAdjacent() == 0)
				propagate(_board[cellRow + 1][cellCol + 1]);
		}
		else
		{
			if (cell.getTRow())
			{
				_board[cellRow][cellCol - 1].setRevealed(true);
				_board[cellRow + 1][cellCol - 1].setRevealed(true);
				_board[cellRow + 1][cellCol].setRevealed(true);
				_board[cellRow + 1][cellCol + 1].setRevealed(true);
				_board[cellRow][cellCol + 1].setRevealed(true);
				if (_board[cellRow + 1][cellCol + 1].getAdjacent() == 0)
					propagate(_board[cellRow + 1][cellCol + 1]);
			}
			else if (cell.getBRow())
			{
				_board[cellRow][cellCol - 1].setRevealed(true);
				_board[cellRow - 1][cellCol - 1].setRevealed(true);
				_board[cellRow - 1][cellCol].setRevealed(true);
				_board[cellRow][cellCol + 1].setRevealed(true);
				_board[cellRow - 1][cellCol + 1].setRevealed(true);
				if (_board[cellRow][cellCol + 1].getAdjacent() == 0)
					propagate(_board[cellRow][cellCol + 1]);
			}
			else if (cell.getFCol())
			{
				_board[cellRow - 1][cellCol].setRevealed(true);
				_board[cellRow - 1][cellCol + 1].setRevealed(true);
				_board[cellRow][cellCol + 1].setRevealed(true);
				_board[cellRow + 1][cellCol + 1].setRevealed(true);
				_board[cellRow + 1][cellCol].setRevealed(true);
				if (_board[cellRow + 1][cellCol + 1].getAdjacent() == 0)
					propagate(_board[cellRow + 1][cellCol + 1]);
			}
			else if (cell.getLCol())
			{
				_board[cellRow - 1][cellCol].setRevealed(true);
				_board[cellRow - 1][cellCol - 1].setRevealed(true);
				_board[cellRow][cellCol - 1].setRevealed(true);
				_board[cellRow + 1][cellCol - 1].setRevealed(true);
				_board[cellRow + 1][cellCol].setRevealed(true);
				if (_board[cellRow + 1][cellCol].getAdjacent() == 0)
					propagate(_board[cellRow + 1][cellCol]);
			}
			else if (cell.getTLCorner())
			{
				_board[cellRow][cellCol + 1].setRevealed(true);
				_board[cellRow + 1][cellCol + 1].setRevealed(true);
				_board[cellRow + 1][cellCol].setRevealed(true);
				if (_board[cellRow + 1][cellCol + 1].getAdjacent() == 0)
					propagate(_board[cellRow + 1][cellCol + 1]);
		
			}
			else if (cell.getTRCorner())
			{
				_board[cellRow][cellCol - 1].setRevealed(true);
				_board[cellRow + 1][cellCol - 1].setRevealed(true);
				_board[cellRow + 1][cellCol].setRevealed(true);
				if (_board[cellRow + 1][cellCol].getAdjacent() == 0)
					propagate(_board[cellRow + 1][cellCol]);

			}
			else if (cell.getBLCorner())
			{
				_board[cellRow - 1][cellCol].setRevealed(true);
				_board[cellRow - 1][cellCol + 1].setRevealed(true);
				_board[cellRow][cellCol + 1].setRevealed(true);
				if (_board[cellRow - 1][cellCol + 1].getAdjacent() == 0)
					propagate(_board[cellRow - 1][cellCol + 1]);
	
			}
			else if (cell.getBRCorner())
			{
				_board[cellRow - 1][cellCol].setRevealed(true);
				_board[cellRow - 1][cellCol - 1].setRevealed(true);
				_board[cellRow][cellCol - 1].setRevealed(true);
			}
		}
	}
}
#endif


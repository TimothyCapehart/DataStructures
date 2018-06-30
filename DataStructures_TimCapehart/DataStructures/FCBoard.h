#ifndef FCBOARD_H
#define FCBOARD_H
#include "Windows.h"
#include "Deck.h"
#include "ArrayStack.h"
#include "ListStack.h"
using std::cout;
using std::endl;

const size_t BLUE = 1;
const size_t YELLOW = 14;
const size_t GREEN = 10;
const size_t RED = 12;
const size_t WHITE = 15;
const size_t GREY = 8;
const size_t LIGHTBLUE = 9;
const size_t BROWN = 6;
const size_t MAGENTA = 5;
const size_t CYAN = 3;
const size_t LIGHTGREY = 7;


static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class FCBoard
{
private:
	Deck _deck;
	Array<Card> _freeCells;
	ArrayStack<Card> _homeCells[4];
	ListStack<Card> _playCards[8];
public:
	FCBoard();
	~FCBoard() {};

	void Deal();
	void MoveToFree(int moveCol, int index);
	void MovePlayToHome(int moveCol, int index);
	void MoveFreeToHome(int moveCol, int index);
	void MoveFreeToPlay(int move, int dest);
	void MovePlayToPlay(int move, int dest);
	bool ValidHome(const Card & move, const Card & dest);
	bool Win();
	void SetDisplays();
	void Print();
};

FCBoard::FCBoard()
{
	_deck.Shuffle();
	_freeCells.setLength(4);
	for (size_t i = 0; i < 4; i++)
		_homeCells[i].setArrayLength(14);
}

void FCBoard::Deal()
{
	_deck.Shuffle();

	Card jokerS(0, Card::spades);
	Card jokerH(0, Card::hearts);
	Card jokerD(0, Card::diamonds);
	Card jokerC(0, Card::clubs);
	Card freeCell(0, Card::other);

	_homeCells[0].Push(jokerS);
	_homeCells[1].Push(jokerH);
	_homeCells[2].Push(jokerD);
	_homeCells[3].Push(jokerC);

	for (size_t i = 0; i < 8; i++)
		_playCards[i].Push(freeCell);

	for (size_t i = 0; i < 6; i++)
		for (size_t j = 0; j < 8; j++)
			_playCards[j].Push(_deck.GetTop());

	for (size_t i = 0; i < 4; i++)
		_playCards[i].Push(_deck.GetTop());

	for (size_t i = 0; i < 4; i++)
		_freeCells[i] = freeCell;

	SetDisplays();
}

void FCBoard::MoveToFree(int moveCol, int  index)
{
	if (_freeCells[index].GetRank() != 0)
		throw Exception("Space occupied.");
	else if (_playCards[moveCol].Peek().GetRank() == 0)
		throw Exception("Column Empty.");
	else
	{
		_freeCells[index] = _playCards[moveCol].Peek();
		_playCards[moveCol].Pop();
	}
}

bool FCBoard::ValidHome(const Card & move, const Card & dest)
{
	return (move.GetSuit() == dest.GetSuit() && move.GetRank() == dest.GetRank() + 1);
}

void FCBoard::MovePlayToHome(int moveCol, int index)
{
	if (!ValidHome(_playCards[moveCol].Peek(), _homeCells[index].Peek()))
		throw Exception("Illegal move.");
	else if (_playCards[moveCol].Peek().GetRank() == 0)
		throw Exception("Column Empty.");
	else
	{
		_homeCells[index].Push(_playCards[moveCol].Peek());
		_playCards[moveCol].Pop();
	}
}

void FCBoard::MoveFreeToHome(int moveCol, int index)
{
	if (!ValidHome(_freeCells[moveCol], _homeCells[index].Peek()))
		throw Exception("Illegal move.");
	else
	{
		_homeCells[index].Push(_freeCells[moveCol]);
		_freeCells[moveCol] = Card(0, Card::Suit::other);
	}
}

void FCBoard::MoveFreeToPlay(int move, int dest)
{
	if (_freeCells[move].GetRank() == 0)
		throw Exception("Free Cell Empty.");
	else if (_freeCells[move].GetColor() == _playCards[dest].Peek().GetColor())
		throw Exception("Illegal. Same Color.");
	else if (_freeCells[move].GetColor() != _playCards[dest].Peek().GetColor()
		&& _freeCells[move].GetRank() != _playCards[dest].Peek().GetRank() - 1)
		throw Exception("Illegal. Only Descending Order.");
	else
	{
		_playCards[dest].Push(_freeCells[move]);
		_freeCells[move] = Card(0, Card::Suit::other);
	}
}

void FCBoard::MovePlayToPlay(int move, int dest)
{
	if (_playCards[move].Peek().GetRank() == 0)
		throw Exception("Column is Empty.");
	else if (_playCards[dest].Peek().GetRank() == 0)
	{
		_playCards[dest].Push(_playCards[move].Peek());
		_playCards[move].Pop();
	}
	else if (_playCards[move].Peek().GetColor() == _playCards[dest].Peek().GetColor())
		throw Exception("Illegal. Same Color.");
	else if (_playCards[move].Peek().GetColor() != _playCards[dest].Peek().GetColor()
		&& _playCards[move].Peek().GetRank() != _playCards[dest].Peek().GetRank() - 1)
		throw Exception("Illegal. Only Descending Order.");
	else
	{
		_playCards[dest].Push(_playCards[move].Peek());
		_playCards[move].Pop();
	}
}

bool FCBoard::Win()
{
	return (_homeCells[0].IsFull() && _homeCells[1].IsFull() &&
		_homeCells[2].IsFull() && _homeCells[3].IsFull());
}

void FCBoard::SetDisplays()
{
	for (size_t i = 0; i < 8; i++)
		if (!_playCards[i].Peek().IsFaceUp())
			_playCards[i].Peek().Flip();
	for (size_t i = 0; i < 4; i++)
		if (_freeCells[i].GetRank() != 0 && !_freeCells[i].IsFaceUp())
			_freeCells[i].Flip();
	for (size_t i = 0; i < 4; i++)
		if (_homeCells[i].Peek().GetRank() != 0 && !_homeCells[i].Peek().IsFaceUp())
			_homeCells[i].Peek().Flip();
}

void FCBoard::Print()
{
	SetConsoleTextAttribute(hConsole, WHITE);
	cout << "\nFREECELL" << endl;
	SetConsoleTextAttribute(hConsole, CYAN);
	cout << "\n\t\t\tFree\t\t\t\t\t\t\t\tHome\n\n" << endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	cout << "       1\t    2\t\t 3\t      4\t\t\t       1\t   2\t\t 3\t     4" << endl;
	

	for (size_t i = 0; i < 4; i++)
	{
		cout << "|";
		if (_freeCells[i].GetColor() == Card::black)
			SetConsoleTextAttribute(hConsole, GREY);
		else if (_freeCells[i].GetColor() == Card::red)
			SetConsoleTextAttribute(hConsole, RED);
		cout << _freeCells[i].toString();
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << "|";
	}
	SetConsoleTextAttribute(hConsole, WHITE);
	cout << "\t\t";

	for (size_t i = 0; i < 4; i++)
	{
		cout << "|";
		if (_homeCells[i].Peek().GetColor() == Card::black)
			SetConsoleTextAttribute(hConsole, GREY);
		else if (_homeCells[i].Peek().GetColor() == Card::red)
			SetConsoleTextAttribute(hConsole, RED);
		cout << _homeCells[i].Peek().toString();
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << "|";
	}
	cout << "\t\t\t\t\t\t\t\t\t    ";
	SetConsoleTextAttribute(hConsole, GREY);
	cout << "Spades\t";
	SetConsoleTextAttribute(hConsole, RED);
	cout << "Hearts\t    Diamonds\t   ";
	SetConsoleTextAttribute(hConsole, GREY);
	cout << "Clubs" << endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, CYAN);
	cout << "\n\n\t\t\t\t\t\t     Play Cards\n\n";
	SetConsoleTextAttribute(hConsole, WHITE);
	cout << "\t   1\t\t2\t   3\t\t 4\t       5\t    6\t\t7\t      8\n" << endl;
	cout << "     ";

	for (size_t i = 0; i < 8; i++)
	{
		cout << "|";
		if (_playCards[i].Peek().GetColor() == Card::black)
			SetConsoleTextAttribute(hConsole, GREY);
		else if (_playCards[i].Peek().GetColor() == Card::red)
			SetConsoleTextAttribute(hConsole, RED);
		cout << _playCards[i].Peek().toString();
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << "|";
	}
}
#endif
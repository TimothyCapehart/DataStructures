#ifndef _DECK_H
#define _DECK_H
#include <cstdlib>
#include <ctime>
#include "card.h"

class Deck
{
private:
	Card myCards[52];
	int myIndex;

public:
	Deck();          

	void Shuffle();  
	Card GetCard(); 
	Card GetTop();
	int GetmyIndex();
	int  Size() const; 
};

Deck::Deck()
: myCards(), myIndex(0)
{
	myCards;
	myIndex = 0;
	int rank;
	int suit;
	int num = 0;

	for (rank = 1; rank <= 52 / 4; rank++)
	{
		for (suit = Card::spades; suit <= Card::clubs; suit++)
		{
			myCards[num] = Card(rank, Card::Suit(suit));
			if (suit == Card::spades || suit == Card::clubs)
			{
				myCards[num].SetColor(Card::black);
			}
			else if (suit == Card::hearts || suit == Card::diamonds)
			{
				myCards[num].SetColor(Card::red);
			}
			num++;
		}
	}
}

void Deck::Shuffle()
{
	myIndex = 0;
	srand(time(NULL));
	int k;
	for (k = 0; k < 52 - 1; k++)
	{
		int swapIndex = rand() % 52;
		Card temp = myCards[swapIndex];
		myCards[swapIndex] = myCards[k];
		myCards[k] = temp;
	}
}

Card Deck::GetCard()
{
	Card c;

	if (0 <= myIndex && myIndex < 52)
	{
		c = myCards[myIndex];
		myIndex = (++myIndex) % 52;
	}
	else
	{
		c = Card(0, Card::other);
	}
	return c;
}

Card Deck::GetTop()
{
	Card c;
	c = myCards[myIndex++];
	return c;
}
int Deck::GetmyIndex()
{
	return myIndex;
}

int Deck::Size() const
{
	return 52 - myIndex;
}
#endif

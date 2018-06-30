#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using std::string;

class Card
{
public:
	enum Color { red, black, otherc};
	enum Suit { spades, hearts, diamonds, clubs, other };

	Card();
	Card(int rank, Suit s);

	string toString() const;  
	bool SameSuitAs(const Card& c) const; 
	int  GetRank() const; 
	Suit GetSuit() const;
	string suitString(Suit s) const; 
	bool IsJoker() const; 
	bool IsFaceUp();
	bool IsFaceUp() const { return faceUp; };
	void Flip();
	void SetColor(Color c) { color = c; }
	Color GetColor() { return color; }
	Color GetColor() const { return color; }

	bool operator!=(const Card& rhs);	
	Card & operator=(const Card & rhs);
	Card & operator=(Card & rhs);
	
private:
	int myRank;
	Suit mySuit;
	Color color;
	bool faceUp;
	string rankString(int r) const;
};

Card::Card()
	: myRank(1),
	mySuit(Card::spades)
{
	faceUp = false;
}

Card::Card(int rank, Suit s)
	: myRank(rank), mySuit(s)
{
	faceUp = false;
	color = otherc;
}

bool Card::operator!=(const Card & rhs)
{
	return this->GetRank() != rhs.GetRank() && this->GetSuit() != rhs.GetSuit();
}

Card & Card::operator=(const Card & rhs)
{
	myRank = rhs.GetRank();
	mySuit = rhs.GetSuit();
	color = rhs.GetColor();
	faceUp = rhs.IsFaceUp();
	return *this;
}

Card & Card::operator=(Card & rhs) 
{
	myRank = rhs.GetRank();
	mySuit = rhs.GetSuit();
	color = rhs.GetColor();
	faceUp = rhs.IsFaceUp();
	return *this;
}

string Card::suitString(Suit s) const
{
	if (s == spades)        
		return " Spades";
	else if (s == hearts)   
		return " Hearts";
	else if (s == diamonds) 
		return "Diamond";
	else                    
		return "  Clubs";
}

string Card::rankString(int r) const
{
	if (1 == r)       return "A";
	else if (2 == r)  return "2";
	else if (3 == r)  return "3";
	else if (4 == r)  return "4";
	else if (5 == r)  return "5";
	else if (6 == r)  return "6";
	else if (7 == r)  return "7";
	else if (8 == r)  return "8";
	else if (9 == r)  return "9";
	else if (10 == r) return "10";
	else if (11 == r) return "J";
	else if (12 == r) return "Q";
	else if (13 == r) return "K";
}

string Card::toString() const
{
	if (1 <= myRank && myRank <= 13 && faceUp == true)
	{
		return rankString(myRank) + " - " + suitString(mySuit);
	}
	/*else if (1 <= myRank && myRank <= 13 && faceUp == false)
		return "-----------";*/
	else
		return "-----------";
}

bool Card::SameSuitAs(const Card& c) const
{
	return mySuit == c.mySuit;
}

int Card::GetRank() const
{
	return myRank;
}

Card::Suit Card::GetSuit() const
{
	return mySuit;
}

bool Card::IsJoker() const
{
	return myRank < 1 || 13 < myRank;
}

void Card::Flip()
{
	if (faceUp == false)
		faceUp = true;
	else if (faceUp == true)
		faceUp = false;
}

bool Card::IsFaceUp()
{
	return faceUp;
}
#endif
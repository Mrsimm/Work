#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <random>
using namespace std;
void MainMenu();
void Game(int, int, int, int, int, int, int, int, int);
int ThirdCards(int);
int ComputerMove(int, int, int);
void DecideWin(int, int);
int main()
{	
	MainMenu();
}

void MainMenu()
{
	int credits = 10;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 4);
	uniform_int_distribution<> diC(1, 13);
	srand(time(0));
	int PcardR1 = diC(gen); //Player Card Ranks
	int PcardR2 = diC(gen);
	int PcardC1 = dis(gen); //Player card classes
	int PcardC2 = dis(gen);
	int OcardR1 = diC(gen); //Opponent card Ranks
	int OcardR2 = diC(gen);
	int OcardC1 = dis(gen); //Opponent card classes
	int OcardC2 = dis(gen);
	string R;
	cout << "**************************************************" << endl;
	cout << "Hello and welcome to Alexander's Blackjack Casino!" << endl;
	cout << "        Where all your dreams are crushed         " << endl;
	cout << "**************************************************" << endl;
	cout << "  Would you like to hear the rules of this game ? " << endl;
	cout << "		 Type Y for Yes and type N for No	       " << endl;
	while (R != "Y" || R != "N")
	{
		cin >> R;
	}
	if (R == "Y")
	{
		
			cout << "Blackjack is a card game where players compete against the dealer to get as close to 21 as possible without going over :" << endl;
			cout << "You will start with a set amount of credits, winning means that your credits are doubled, losing means you lose all of you earnings" << endl;
			cout << "Goal: Get a higher hand value than the dealer without going over 21" << endl;
			cout << "Cards : Number cards are worth their face value, face cards(Jacks, Queens, and Kings) are worth 10, and Aces can be worth 1 or 11" << endl;
			cout << "Dealing : Players receive two cards, one face up and one face down, while the dealer receives two cards, one face up and one face down" << endl;
			cout << "Play : Players can choose to hit(take a card) or stand(end their turn)" << endl;
			cout << "Winning : Players win if their hand is higher than the dealers without going over 21, or if the dealer goes over 21" << endl;
	}
	cout << "Your current credit count is: " << credits << endl;
	Game(PcardR1, PcardR2, PcardC1, PcardC2, OcardR1, OcardR2, OcardC1, OcardC2, credits);
}
void Cards(int R, int C)
{
	string Rank[13] = { "Ace", "TWO", "THREE", "FOUR", "Five", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING" };
	string Class[4] = { "HEARTS", "DIAMONDS", "CLUBS", "SPADES" };
	cout << Rank[R] << " of " << Class[C];
}

void Game(int PcardR1, int PcardR2, int PcardC1, int PcardC2, int OcardR1, int OcardR2, int OcardC1, int OcardC2,int credits)
{
	int PScore, OScore;
	cout << "****************************" << endl;
	cout << "The players first card is a ";
	Cards(PcardR1 - 1, PcardC1 - 1);
	cout << endl;
	cout << "The players second card is a ";
	Cards(PcardR2 - 1, PcardC2 - 1);
	cout << endl;
	cout << "*****************************" << endl;
	if (PcardR1 > 10)
	{
		PcardR1 = 10;
	}
	if (PcardR2 > 10)
	{
		PcardR2 = 10;
	}
	PScore = PcardR1 + PcardR2;
	while (PScore < 11 && PcardR1 == 1)
	{
		PcardR1 = 11;
		PScore = PcardR1 + PcardR2;
	}
	while (PScore < 11 && PcardR2 == 1)
	{
		PcardR2 = 11;
		PScore = PcardR1 + PcardR2;
	}
	cout << "*****************************" << endl;
	cout << "The Opponents second card is a ";
	Cards(OcardR2 - 1, OcardC2 - 1);
	cout << endl;
	cout << "*****************************" << endl;
	if (OcardR1 > 10)
	{
		OcardR1 = 10;
	}
	if (OcardR2 > 10)
	{
		OcardR2 = 10;
	}
	OScore = OcardR1 + OcardR2;
	while (OScore < 11 && OcardR1 == 1)
	{
		OcardR1 = 11;
		OScore = OcardR1 + OcardR2;
	}
	while (PScore < 11 && PcardR2 == 1)
	{
		OcardR2 = 11;
		OScore = OcardR1 + OcardR2;
	}
	int decision = 0;
	while (decision != 1 && decision != 2)
	{
		cout << "Type 1 to draw a card, 2 to stay" << endl;
		cout << "*******************************" << endl;
		cout << "Would you like to hit or stay: " << endl;
		cin >> decision;
	}
	if (decision == 1)
	{
		PScore = ThirdCards(PScore);
	}
	OScore = ComputerMove(OScore, OcardR1, OcardR2);
	cout << "The player score is: " << PScore << endl;
	cout << "The Opponents score is: " << OScore << endl;
	DecideWin(PScore, OScore);
}


int ThirdCards(int S)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 4);
	uniform_int_distribution<> diC(1, 13);
	int PcardR3 = diC(gen);
	int PcardC3 = dis(gen);
	cout << "****************************" << endl;
	cout << "The players third card is a ";
	Cards(PcardR3 - 1, PcardC3 - 1);
	cout << endl;
	S = S + PcardR3;
	return S;
}
int ComputerMove(int S, int C1, int C2)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 4);
	uniform_int_distribution<> diC(1, 13);
	int OcardR3 = diC(gen);
	int OcardC3 = dis(gen);
	if (S < 17)
	{
		cout << "****************************" << endl;
		cout << "The Opponents third card is a ";
		Cards(OcardR3 - 1, OcardC3 - 1);
		S = S + OcardR3;
		return S;
	}
	if (S >= 17 && C1 == 1 || C2 == 1)
	{
		uniform_int_distribution<> dec(0, 1);
		int Odecision = dec(gen);
		if (Odecision == 0)
		{
			cout << "****************************" << endl;
			cout << "The Opponents third card is a ";
			Cards(OcardR3 - 1, OcardC3 - 1);
			cout << endl;
			S = S + OcardR3;
			return S;
		}
		else
		{
			return S;
		}
	}
	if (S >= 17)
	{

		return S;
	}
}

void DecideWin(int p, int o)
{
	if (p < o && o < 21)
	{
		cout << "Opponent Wins!" << endl;
	}
	if (p > o && p < 21)
	{
		cout << "Player Wins!" << endl;
	}
	if (p > 21)
	{
		cout << "Player Busts, Opponent Wins!" << endl;
	}
	if (o > 21)
	{
		cout << "Opponent Busts, Player Wins!" << endl;
	}
	if (p == o || p > 21 && o > 21)
	{
		cout << "It's a draw!" << endl;
	}
}

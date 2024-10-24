#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include<time.h>
#include<cstdlib>
using namespace std;
double Jscore;
void getJudgeData(double&);
void calcScore(double, double, double, double, double);
int findLowest(double, double, double, double, double);
int findHighest(double, double, double, double, double);

int main()
{
	double jscore1;
	double jscore2;
	double jscore3;
	double jscore4;
	double jscore5;
	cout << "Input the first judges score: " << endl;
	getJudgeData(jscore1);
	cout << "Input the second judges score: " << endl;
	getJudgeData(jscore2);
	cout << "Input the third judges score: " << endl;
	getJudgeData(jscore3);
	cout << "Input the fourth judges score: " << endl;
	getJudgeData(jscore4);
	cout << "Input the fifth judges score: " << endl;
	getJudgeData(jscore5);
	int lowest = findLowest(jscore1, jscore2, jscore3, jscore4, jscore5);
	int highest = findHighest(jscore1, jscore2, jscore3, jscore4, jscore5);
	cout << "The lowest score is: " << lowest << endl;
	cout << "The highest score is: " << highest << endl;
	calcScore(jscore1, jscore2, jscore3, jscore4, jscore5);
}







void getJudgeData(double& Jscore)
{
	cin >> Jscore;
	while (Jscore < 0 || Jscore > 10)
	{
		cout << "Please enter a number less than 10 and greater than 0" << endl;
		cin >> Jscore;
	}
}

int findLowest(double jscore1, double jscore2, double jscore3, double jscore4, double jscore5)
{
	double Lowest;
	if (jscore1 < jscore2 && jscore1 < jscore3 && jscore1 < jscore4 && jscore1 < jscore5)
	{
		Lowest = jscore1;
	}
	if (jscore2 < jscore1 && jscore2 < jscore3 && jscore2 < jscore4 && jscore2 < jscore5)
	{
		Lowest = jscore2;
	}
	if (jscore3 < jscore2 && jscore3 < jscore1 && jscore3 < jscore4 && jscore3 < jscore5)
	{
		Lowest = jscore3;
	}
	if (jscore4 < jscore2 && jscore4 < jscore3 && jscore4 < jscore1 && jscore4 < jscore5)
	{
		Lowest = jscore4;
	}
	if (jscore5 < jscore2 && jscore5 < jscore3 && jscore5 < jscore4 && jscore5 < jscore1)
	{
		Lowest = jscore5;
	}
	return Lowest;
}

int findHighest(double jscore1, double jscore2, double jscore3, double jscore4, double jscore5)
{
	double Highest;
	if (jscore1 > jscore2 && jscore1 > jscore3 && jscore1 > jscore4 && jscore1 > jscore5)
	{
		Highest = jscore1;
	}
	if (jscore2 > jscore1 && jscore2 > jscore3 && jscore2 > jscore4 && jscore2 > jscore5)
	{
		Highest = jscore2;
	}
	if (jscore3 > jscore2 && jscore3 > jscore1 && jscore3 > jscore4 && jscore3 > jscore5)
	{
		Highest = jscore3;
	}
	if (jscore4 > jscore2 && jscore4 > jscore3 && jscore4 > jscore1 && jscore4 > jscore5)
	{
		Highest = jscore4;
	}
	if (jscore5 > jscore2 && jscore5 > jscore3 && jscore5 > jscore4 && jscore5 > jscore1)
	{
		Highest = jscore5;
	}
	return Highest;
}


void calcScore(double jscore1, double jscore2, double jscore3, double jscore4, double jscore5)
{
	int lowest = findLowest(jscore1, jscore2, jscore3, jscore4, jscore5);
	int highest = findHighest(jscore1, jscore2, jscore3, jscore4, jscore5);
	int score = ((jscore1 + jscore2 + jscore3 + jscore4 + jscore5) - lowest) - highest;
	int Avg = score / 3;
	cout << "The average score is: " << Avg;
}

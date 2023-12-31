#pragma once
#include<iostream>
#include<string>
#include"RandomNumber.h"
using namespace std;

class Roulette
{
private:
	enum DetectUserPlay //previously: UserInputDetection
	{
		detectInterger = 36,  // 0-36
		detectHalf = 37,	  // "left" , "right"
		detectThird = 38,	  // "1/3", "2/3", "3/3", 
		detectColor = 39,	  // "red" , "black"
		detectParity = 40,	  // "odd" , "even
		detectRow = 41,		  // "top" , "middle" , "bottom"
		detectNull = 100
	};
private:
	RandomNumber mRn; //setUserMinValue , setUserMaxValue
	int mCurrentRandomNumber;
	string mUserInput;
	static const int mRowSize = 12;
	int topRow[mRowSize];
	int middleRow[mRowSize];
	int bottomRow[mRowSize];
	static const int mRedBlack = 18;
	int mRed[mRedBlack];
	int mBlack[mRedBlack];
public: //was private
	auto assignWithDetectUserPlay();
public:
	Roulette();
	void setMUserInput(string userInput);
	bool checkIfUserIsCorrect();
	void gameRules();
};
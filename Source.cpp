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
	static const int mRedBlack= 18;
	int mRed[mRedBlack];
	int mBlack[mRedBlack];
public: //was private
	auto assignWithDetectUserPlay();
public:
	Roulette();
	void setMUserInput(string userInput);
	bool checkIfUserIsCorrect();
};

Roulette::Roulette()
{
	//numbers from 0-36:
	mRn.setUserMinValue(0);
	mRn.setUserMaxValue(36);

	mCurrentRandomNumber = mRn.getRandomNumber();

	//inatalize top, middle,bottom rows
	for (int i = 0; i < mRowSize; i++) { topRow[i] = 3 * (i + 1); } //[(3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36)]
	for (int i = 0; i < mRowSize; i++) { middleRow[i] = 2 + 3 * i; }//[(2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35)]
	for (int i = 0; i < mRowSize; i++) { bottomRow[i] = 3 * i + 1; }//[(1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34)]

	mUserInput = "NULL";
}

auto Roulette::assignWithDetectUserPlay()
{
	if (mUserInput == "1/3" || mUserInput == "2/3" || mUserInput == "3/3")
		return DetectUserPlay::detectThird;
	else if (mUserInput < to_string(37) && mUserInput > to_string(-1))
		return DetectUserPlay::detectInterger;
	else if (mUserInput == "left" || mUserInput == "right")
		return DetectUserPlay::detectHalf;
	else if (mUserInput == "red" || mUserInput == "black")
		return DetectUserPlay::detectColor;
	else if (mUserInput == "even" || mUserInput == "odd")
		return DetectUserPlay::detectParity;
	else if (mUserInput == "top" || mUserInput == "middle" || mUserInput == "bottom")
		return DetectUserPlay::detectRow;
	return DetectUserPlay::detectNull;
}

void Roulette::setMUserInput(string userInput)
{
	//for (int i = 0; i < userInput.length(); i++) { mUserInput[i] = tolower(userInput[i]); }
	this->mUserInput = userInput;
}

bool Roulette::checkIfUserIsCorrect()
{
	cout << mCurrentRandomNumber << endl;
	switch (assignWithDetectUserPlay())
	{
	case detectInterger:
		if (stoi(mUserInput) == mCurrentRandomNumber) //stoi "string to int"
			return true;
		return false;
		break;

	case detectHalf:
		if (mUserInput == "left" && mCurrentRandomNumber < 19)
			return true;
		else if (mUserInput == "right" && mCurrentRandomNumber > 18)
			return true;
		return false;
		break;

	case detectThird:
		break;

	case detectColor:
		break;

	case detectParity:
		if (mUserInput == "even" && mCurrentRandomNumber % 2 == 0)
			return true;
		else if (mUserInput == "odd" && mCurrentRandomNumber % 2 == 1)
			return true;
		return false;
		break;

	case detectRow:
		for (int i = 0; i < mRowSize; i++)
			if (mUserInput == "top" && mCurrentRandomNumber == topRow[i])
				return 1;
		for (int i = 0; i < mRowSize; i++)
			if (mUserInput == "middle" && mCurrentRandomNumber == middleRow[i])
				return 1;
		for (int i = 0; i < mRowSize; i++)
			if (mUserInput == "bottom" && mCurrentRandomNumber == bottomRow[i])
				return 1;
		return 0;
		break;

	case detectNull:
		break;

	}
}

int main()
{
	Roulette rl;
	rl.setMUserInput("top");
	cout << rl.checkIfUserIsCorrect();



	return 0;
}
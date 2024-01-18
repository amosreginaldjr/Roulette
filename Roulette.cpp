#include"Roulette.h"

Roulette::Roulette()
{
	//numbers from 0-36:
	mRn.setUserMinValue(0);
	mRn.setUserMaxValue(36);

	mCurrentRandomNumber = mRn.getRandomNumber();

	//inatalize top, middle, bottom rows
	for (int i = 0; i < mRowSize; i++) { topRow[i] = 3 * (i + 1); } //[(3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36)]
	for (int i = 0; i < mRowSize; i++) { middleRow[i] = 2 + 3 * i; }//[(2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35)]
	for (int i = 0; i < mRowSize; i++) { bottomRow[i] = 3 * i + 1; }//[(1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34)]

	//initalize red values
	mRed[0] = 1; mRed[1] = 3; mRed[2] = 5; mRed[3] = 7; mRed[4] = 9; mRed[5] = 12; mRed[6] = 14; mRed[7] = 16;
	mRed[8] = 18; mRed[9] = 19; mRed[10] = 21; mRed[11] = 23; mRed[12] = 25; mRed[13] = 27; mRed[14] = 30;
	mRed[15] = 32; mRed[16] = 34; mRed[17] = 36;
	//initalize black values
	mBlack[0] = 2; mBlack[1] = 4; mBlack[2] = 6; mBlack[3] = 8; mBlack[4] = 10; mBlack[5] = 11; mBlack[6] = 13;
	mBlack[7] = 15; mBlack[8] = 17; mBlack[9] = 20; mBlack[10] = 22; mBlack[11] = 24; mBlack[12] = 26;
	mBlack[13] = 28; mBlack[14] = 29; mBlack[15] = 31; mBlack[16] = 33; mBlack[17] = 35;

	mUserInput = "NULL";
}

auto Roulette::assignWithDetectUserPlay()
{
	if (mUserInput == "1/3" || mUserInput == "2/3" || mUserInput == "3/3")
		return DetectUserPlay::detectThird;
	else if (mUserInput < to_string(37) && mUserInput > to_string(-1))
		return DetectUserPlay::detectInterger;
	else if (mUserInput == "left" || mUserInput == "right" || mUserInput == "Q" || mUserInput == "E")
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
		{
			generateNewRandomNumber();
			return true;
		}
		return false;
		break;

	case detectHalf:
		if (mUserInput == "left" && mCurrentRandomNumber < 19 || mUserInput == "Q" && mCurrentRandomNumber < 19)
		{
			generateNewRandomNumber();
			return true;
		}
		else if (mUserInput == "right" && mCurrentRandomNumber > 18 || mUserInput == "E" && mCurrentRandomNumber > 18)
		{
			generateNewRandomNumber();
			return true;
		}
		return false;
		break;

	case detectThird:
		if (mUserInput == "1/3" && mCurrentRandomNumber < 13 && mCurrentRandomNumber > 0)
		{
			generateNewRandomNumber();
			return true;
		}
		else if (mUserInput == "2/3" && mCurrentRandomNumber > 12 && mCurrentRandomNumber < 25)
		{
			generateNewRandomNumber();
			return true;
		}
		else if (mUserInput == "3/3" && mCurrentRandomNumber > 24)
		{
			generateNewRandomNumber();
			return true;
		}
		return false;
		break;

	case detectColor:
		for (int i = 0; i < mRedBlack; i++)
			if (mUserInput == "red" && mCurrentRandomNumber == mRed[i])
			{
				generateNewRandomNumber();
				return true;
			}
		for (int i = 0; i < mRedBlack; i++)
			if (mUserInput == "black" && mCurrentRandomNumber == mBlack[i])
			{
				generateNewRandomNumber();
				return true;
			}
		return false;
		break;

	case detectParity:
		if (mUserInput == "even" && mCurrentRandomNumber % 2 == 0)
		{
			generateNewRandomNumber();
			return true;
		}
		else if (mUserInput == "odd" && mCurrentRandomNumber % 2 == 1)
		{
			generateNewRandomNumber();
			return true;
		}
		return false;
		break;

	case detectRow:
		for (int i = 0; i < mRowSize; i++)
			if (mUserInput == "top" && mCurrentRandomNumber == topRow[i])
			{
				generateNewRandomNumber();
				return true;
			}
		for (int i = 0; i < mRowSize; i++)
			if (mUserInput == "middle" && mCurrentRandomNumber == middleRow[i])
			{
				generateNewRandomNumber();
				return true;
			}
		for (int i = 0; i < mRowSize; i++)
			if (mUserInput == "bottom" && mCurrentRandomNumber == bottomRow[i])
			{
				generateNewRandomNumber();
				return true;
			}
		return false;
		break;

	case detectNull:
		cout << "There has been an error, try to run the program again\n";
		break;
	}
}

void Roulette::gameControls()
{
	cout << "Controls:\n";
	cout << "Enter an integer from \"0-36\" to place a bet on one number\n";
	cout << "Enter \"left\" or \"right\" to place your bet on lower or upper half respectively\n";
	cout << "Enter \"1/3\" or \"2/3\" or \"3/3\" to place you bet on (1-12), (13-24), or (25-36)\n";
	cout << "Enter \"red\" or \"black\" to place your bet on red values or black values\n";
	cout << "Enter \"even\" or \"odd\" to place your bet on even or odd values\n";
	cout << "Enter \"\" or \"\" or \"\" to place your bet on row one, row two, or row three\n";
}

void Roulette::generateNewRandomNumber()
{
	mCurrentRandomNumber = mRn.getRandomNumber();
}
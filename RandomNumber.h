#pragma once
#include<iostream>

class RandomNumber
{
private:
	int mUserMinValue;
	int mUserMaxValue;
	int mCurrentRandomNumber;
public:
	RandomNumber();
	void setUserMinValue(int userMinValue);
	void setUserMaxValue(int userMaxValue);
	int getRandomNumber();
};
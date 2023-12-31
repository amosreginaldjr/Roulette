#include<iostream>
#include<string>
#include"Roulette.h"
using namespace std;

int main()
{
	Roulette rl;
	
	rl.setMUserInput("red");
	cout << rl.checkIfUserIsCorrect() << endl;

	return 0;
}
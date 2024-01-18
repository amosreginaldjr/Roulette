#include<iostream>
#include<string>
#include"Roulette.h"

#include<conio.h>
#include<Windows.h>
#include<Winuser.h>

using namespace std;

int main()
{
	Roulette rl;
	
	//rl.setMUserInput("red");
	//cout << rl.checkIfUserIsCorrect() << endl;
	//system("cls");

	while (true)
	{
		_getch(); //used to give the loop a pause until user makes a selection
		if (GetAsyncKeyState('Q'))
		{
			rl.setMUserInput("Q");
			if (rl.checkIfUserIsCorrect())
				cout << "WIN\n";
			else
				cout << "LOSS\n";
		}
		else if (GetAsyncKeyState('E'))
		{
			rl.setMUserInput("E");
			if (rl.checkIfUserIsCorrect())
				cout << "WIN\n";
			else
				cout << "LOSS\n";
		}
	}
	
	return 0;
}




/*
if (GetAsyncKeyState(VK_LSHIFT))
			cout << "NumPad2 Pressed\n";
		else
			cout << "No key pressed\n";
		Sleep(500);
*/
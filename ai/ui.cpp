#include "ui.h"
#include<Windows.h>
#include<iostream>
using namespace std;
void ui::init()
{
	for (int i = 0; i < 10; i++)
	{
		Chequer[i] = ' ';
	}
	hold[1] = '|'; hold[3] = '|'; hold[11] = '|'; hold[13] = '|'; hold[21] = '|'; hold[23] = '|';
	for (int i = 5; i <= 9; i++)
	{
		hold[i] = '-';
	}
	for (int i = 15; i <= 19; i++)
	{
		hold[i] = '-';
	}
}

void ui::printChequer(int pos,char ch)
{
	system("clean");
	Chequer[pos] = 'ch';
	for (int i = 0; i < 25; i++)
	{
		if (i % 5 == 0)
		{
			cout << endl;
		}
		cout << hold[i];
	}
}

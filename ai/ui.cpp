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
	system("cls");
	Chequer[pos] = ch;
	hold[0] = Chequer[1]; hold[2] = Chequer[2]; hold[4] = Chequer[3]; 
	hold[10] = Chequer[4]; hold[12] = Chequer[5]; hold[14] = Chequer[6]; 
	hold[20] = Chequer[7]; hold[22] = Chequer[8]; hold[24] = Chequer[9];
	for (int i = 0; i < 25; i++)
	{
		if (i % 5 == 0)
		{
			cout << endl;
		}
		cout << hold[i];
	}
}

void ui::memory(int pos)
{
	this->compu.push_back(pos);
}

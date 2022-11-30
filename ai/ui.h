#pragma once
#include<vector>
using namespace std;
class ui {
public:
	char Chequer[11];
	char hold[25];
	vector<int> compu;
public:
	void init();
	void printChequer(int pos,char ch);
	void memory(int);
};
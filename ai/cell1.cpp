#include "cell1.h"
#include<ctime>
#include<cstdlib>
double cell1::loss(double loss,int pos,int cell,double effect)
{
	
	if (this->weight[pos][cell] * this->score[pos] == 0 || effect == 0)
	{
		return 0;
	}
	else {
		if (loss == 0)
		{
			this->weight[pos][cell] = this->weight[pos][cell] + 10;
			return -10;
		}
		else {
			this->weight[pos][cell] -= loss;
			return loss;
		}
		
	}
}

double cell1::giveScore()
{
    return 0;
}

void cell1::init()
{
	for (int i = 1; i < 10; i++)
	{
		this->score[i] = 0;
	}
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			this->weight[i][j] = (rand() % 100 + 1) / 100.0;
			//srand(this->weight[i][j]);
		}
	}
}

void cell1::renew()
{
	for (int i = 1; i < 10; i++)
	{
		this->score[i] = 0;
	}
}

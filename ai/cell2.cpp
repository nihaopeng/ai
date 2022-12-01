#include "cell2.h"
#include<ctime>
#include<cstdlib>
double cell2::loss(double loss,int pos)
{
	double temp = this->weight[pos];
	
	if (this->weight[pos] * this->score[pos] == 0)
	{
		return 0;
	}
	else {
		if (loss == 0)
		{
			this->weight[pos] = this->weight[pos] + 10;
			return -10;
		}
		else {
			this->weight[pos] = this->weight[pos] - loss;
			return loss;
		}
		
	}
}

double cell2::giveScore()
{
    return 0;
}

void cell2::init()
{
	for (int i = 1; i < 10; i++)
	{
		this->score[i] = 0;
	}
	for (int i = 1; i < 10; i++)
	{
			this->weight[i] = (rand() % 100 + 1) / 100.0;
	}
}

void cell2::renew()
{
	for (int i = 1; i < 10; i++)
	{
		this->score[i] = 0;
	}
}

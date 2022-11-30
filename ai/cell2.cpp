#include "cell2.h"
#include<ctime>
#include<cstdlib>
double cell2::loss(double loss,int pos)
{
	double temp = this->weight[pos];
	if (this->weight[pos] * this->score == 0)
	{
		return 0;
	}
	else {
		this->weight[pos] = this->weight[pos] - loss;
		return loss;
	}
}

double cell2::giveScore()
{
    return 0;
}

void cell2::init()
{
	for (int i = 0; i < 10; i++)
	{
		this->score = 0;
	}
	for (int i = 1; i < 10; i++)
	{
			this->weight[i] = (rand() % 100 + 1) / 100.0;
	}
}

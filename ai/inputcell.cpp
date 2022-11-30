#include "inputcell.h"
#include<ctime>
#include<cstdlib>
void inputcell::loss(double loss,int pos,int cell,double effect)
{
	if (this->weight[pos][cell] * this->score == 0 || effect == 0)
	{
		return;
	}
	else {
		this->weight[pos][cell] -= loss;
	}
}

double inputcell::giveScore()
{
	return 0;
}

void inputcell::init()
{
	srand(time(0));
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			this->weight[i][j] = (rand() % 100 + 1) / 100.0;
			//srand(this->weight[i][j]);
		}
	}
}

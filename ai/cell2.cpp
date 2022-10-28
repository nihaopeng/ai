#include "cell2.h"
#include<ctime>
#include<cstdlib>
void cell2::loss(int)
{
}

double cell2::giveScore()
{
    return 0;
}

void cell2::init()
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->weight[i][j] = (rand() % 100 + 1) / 100.0;
			//srand(this->weight[i][j]);
		}
	}
}

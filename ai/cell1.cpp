#include "cell1.h"
#include<ctime>
#include<cstdlib>
void cell1::loss(int)
{

}

double cell1::giveScore()
{
    return 0;
}

void cell1::init()
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

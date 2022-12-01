#include "result.h"

double result::MAX()
{
    return 0;
}

void result::init()
{
    for (int i = 1; i < 10; i++)
    {
        this->score[i] = 0;
    }
}

int result::definePos(int chequer[10])
{
    double max = -100000000;
    int maxi = 1;
    for (int i = 1; i < 10; i++)
    {
        if (this->score[i] > max&&chequer[i]==0)
        {
            max = this->score[i];
            maxi = i;
        } 
    }
    return maxi;
}

void result::renew()
{
    for (int i = 1; i < 10; i++)
    {
        this->score[i] = 0;
    }
}

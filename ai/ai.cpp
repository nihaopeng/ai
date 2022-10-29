#include<iostream>
#include"inputcell.h"
#include"cell1.h"
#include"cell2.h"
#include"result.h"
using namespace std;
int calc(inputcell*& in, cell1*& c1, cell2*& c2, result& re) {
	for (int i = 0; i < 10; i++)//哪个位置
	{
		//第一层
		for (int j = 0; j < 10; j++)//对第几个神经元
		{
			for (int k = 0; k < 10; k++)//对第几个输入
			{
				c1[j].score += in[k].weight[i][j] * in[k].score;
			}
		}
		//第二层
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				c2[j].score += c1[k].score * c1[k].weight[i][j];
			}
		}
		//结果层
		for (int j = 0; j < 10; j++)
		{
			re.score[i] = c2[j].score * c2[j].weight[i][0];
		}
	}
}
int main()
{
	//前向传播
	inputcell in[10];
	for (int i = 0; i < 10; i++)
	{
		in[i].init();
	}
	cell1 c1[10];
	for (int i = 0; i < 10; i++)
	{
		c1[i].init();
	}
	cell2 c2[10];
	for (int i = 0; i < 10; i++)
	{
		c2[i].init();
	}
	result re;
	re.init();
	
	while (1) {

	}
	return 0;
}
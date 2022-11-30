#include<iostream>
#include<cmath>
#include"inputcell.h"
#include"cell1.h"
#include"cell2.h"
#include"result.h"
#include"ui.h"
using namespace std;
void calc(inputcell* in, cell1* c1, cell2* c2, result& re) {
	for (int i = 1; i < 10; i++)//哪个位置
	{
		//第一层
		for (int j = 1; j < 10; j++)//对第几个神经元
		{
			for (int k = 1; k < 10; k++)//对第几个输入
			{
				c1[j].score += in[k].weight[i][j] * in[k].score;
			}
		}
		//第二层
		for (int j = 1; j < 10; j++)
		{
			for (int k = 1; k < 10; k++)
			{
				c2[j].score += c1[k].score * c1[k].weight[i][j];
			}
		}
		//结果层
		for (int j = 1; j < 10; j++)
		{
			re.score[i] = c2[j].score * c2[j].weight[i];
		}
	}
}
void Relu(inputcell* in, cell1* c1, cell2* c2, result& re, int pos, double loss) {
	for (int i = 1; i < 10; i++)
	{
		double effectC2 = c2[i].loss(loss, pos);
		for (int j = 1; j < 10; j++)
		{
			double effectC1 = c1[j].loss(loss, pos, i, effectC2);
			for (int k = 1; k < 10; k++)
			{
				in[k].loss(loss, pos, j, effectC1);
			}
		}
	}
}
int judge(int chequer[10])
{
	if ((chequer[1] && chequer[2] && chequer[3]) ||
		(chequer[4] && chequer[5] && chequer[6]) ||
		(chequer[7] && chequer[8] && chequer[9]) ||
		(chequer[1] && chequer[4] && chequer[7]) ||
		(chequer[2] && chequer[5] && chequer[8]) ||
		(chequer[3] && chequer[6] && chequer[9]) ||
		(chequer[1] && chequer[5] && chequer[9]) ||
		(chequer[3] && chequer[5] && chequer[7]))
		{
		return 1;
	}
	else {
		return 0;
	}
}
void peopleTurn(int chequer[10],ui &u) {
	cout << "turn to you:" << endl;
	int choice;
	cin >> choice;
	chequer[choice] = 1;
	u.printChequer(choice, '@');
	system("pause");
}
void compuTurn(int chequer[10],inputcell* in, cell1* c1, cell2* c2, result& re,double &loss, ui& u) {
	for (int i = 1; i < 10; i++)
	{
		in[i].score = chequer[i];
	}
	calc(in,c1, c2, re);
	chequer[re.definePos()] = 1;
	loss += 0.25;
	u.memory(re.definePos());
	for (int i = 1; i < 10; i++)
	{
		cout << re.score[i] << endl;
	}
	system("pause");
	u.printChequer(re.definePos(), '#');
}
void totalProcess(int chequer[10], inputcell* in, cell1* c1, cell2* c2, result &re)
{
	for (int i = 1; i < 10; i++)
	{
		in[i].score = chequer[i];
	}
	double loss = 0;
	ui u;
	u.init();
	while (1) {
		peopleTurn(chequer, u);
		if (judge(chequer))
		{
			for (int i = 0; i < u.compu.size(); i++)
			{
				Relu(in, c1, c2, re, u.compu[i], -log10(loss));
				return;
			}
		}
		compuTurn(chequer, in, c1, c2, re, loss, u);
		if (judge(chequer))
		{
			for (int i = 0; i < u.compu.size(); i++)
			{
				Relu(in, c1, c2, re, u.compu[i], -log10(loss));
				return;
			}
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
	int chequer[10] = { 0 };
	totalProcess(chequer, in, c1, c2, re);
	
	return 0;
}
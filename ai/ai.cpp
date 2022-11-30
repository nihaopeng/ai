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
				//cout << c1[j].score;
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
			re.score[i] += c2[j].score * c2[j].weight[i];
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
int judge(ui u)
{
	if ((u.Chequer[1]=='@' && u.Chequer[2] == '@' && u.Chequer[3] == '@') ||
		(u.Chequer[4] == '@' && u.Chequer[5] == '@' && u.Chequer[6] == '@') ||
		(u.Chequer[7] == '@' && u.Chequer[8] == '@' && u.Chequer[9] == '@') ||
		(u.Chequer[1] == '@' && u.Chequer[4] == '@' && u.Chequer[7] == '@') ||
		(u.Chequer[2] == '@' && u.Chequer[5] == '@' && u.Chequer[8] == '@') ||
		(u.Chequer[3] == '@' && u.Chequer[6] == '@' && u.Chequer[9] == '@') ||
		(u.Chequer[1] == '@' && u.Chequer[5] == '@' && u.Chequer[9] == '@') ||
		(u.Chequer[3] == '@' && u.Chequer[5] == '@' && u.Chequer[7] == '@')||
		(u.Chequer[1] == '#' && u.Chequer[2] == '#' && u.Chequer[3] == '#') ||
		(u.Chequer[4] == '#' && u.Chequer[5] == '#' && u.Chequer[6] == '#') ||
		(u.Chequer[7] == '#' && u.Chequer[8] == '#' && u.Chequer[9] == '#') ||
		(u.Chequer[1] == '#' && u.Chequer[4] == '#' && u.Chequer[7] == '#') ||
		(u.Chequer[2] == '#' && u.Chequer[5] == '#' && u.Chequer[8] == '#') ||
		(u.Chequer[3] == '#' && u.Chequer[6] == '#' && u.Chequer[9] == '#') ||
		(u.Chequer[1] == '#' && u.Chequer[5] == '#' && u.Chequer[9] == '#') ||
		(u.Chequer[3] == '#' && u.Chequer[5] == '#' && u.Chequer[7] == '#'))
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
		//cout << in[i].score << endl;
	}
	calc(in,c1, c2, re);
	chequer[re.definePos(chequer)] = 1;
	loss += 0.25;
	u.memory(re.definePos(chequer));
	for (int i = 1; i < 10; i++)
	{
		cout << re.score[i] << endl;
	}
	system("pause");
	u.printChequer(re.definePos(chequer), '#');
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
		if (judge(u))
		{
			for (int i = 0; i < u.compu.size(); i++)
			{
				Relu(in, c1, c2, re, u.compu[i], -log10(loss));
				return;
			}
		}
		compuTurn(chequer, in, c1, c2, re, loss, u);
		if (judge(u))
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
	srand((time(NULL)));
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
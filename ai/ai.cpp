#include<iostream>
#include<cmath>
#include"inputcell.h"
#include"cell1.h"
#include"cell2.h"
#include"result.h"
#include"ui.h"
using namespace std;
void calc(int chequer[10],inputcell* in, cell1* c1, cell2* c2, result& re);
void Relu(inputcell* in, cell1* c1, cell2* c2, result& re, int pos, double loss);
int judge(ui u,int cnt);
void peopleTurn(int chequer[10], ui& u);
void compuTurn(int chequer[10], inputcell* in, cell1* c1, cell2* c2, result& re, double& loss, ui& u);
void totalProcess(int chequer[10], inputcell* in, cell1* c1, cell2* c2, result& re);
void renewAll(int chequer[10], inputcell* in, cell1* c1, cell2* c2, result& re);

void calc(int chequer[10],inputcell* in, cell1* c1, cell2* c2, result& re) {
	
	for (int i = 1; i < 10; i++)//哪个位置
	{
		//第一层
		for (int j = 1; j < 10; j++)//对第几个神经元
		{
			for (int k = 1; k < 10; k++)//对第几个输入
			{
				c1[j].score[i] += in[k].weight[i][j] * in[k].score;
			}
		}
		//第二层
		for (int j = 1; j < 10; j++)
		{
			for (int k = 1; k < 10; k++)
			{
				c2[j].score[i] += c1[k].score[i] * c1[k].weight[i][j];
				//cout << c1[k].weight[i][j] << endl;
			}
		}
		//结果层
		for (int j = 1; j < 10; j++)
		{
			re.score[i] += c2[j].score[i] * c2[j].weight[i];
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
int judge(ui u,int cnt)
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
	else if (cnt == 9)
	{
		return 1;
	}
	else {
		return 0;
	}
}
void peopleTurn(int chequer[10],ui &u) {
	cout <<endl<< "turn to you:" << endl;
	int choice;
	cin >> choice;
	chequer[choice] = 1;
	u.printChequer(choice, '@');
	system("pause");
}
void compuTurn(int chequer[10],inputcell* in, cell1* c1, cell2* c2, result& re,double &loss, ui& u) {
	renewAll(chequer, in, c1, c2, re);
	calc(chequer,in,c1, c2, re);
	int pos = re.definePos(chequer);
	chequer[pos] = 1;
	loss += 0.25;
	u.memory(pos);
	/*for (int i = 1; i < 10; i++)
	{
		cout << re.score[i] << endl;
	}*/
	cout << pos << endl;
	system("pause");
	u.printChequer(pos, '#');
}
void totalProcess(int chequer[10], inputcell* in, cell1* c1, cell2* c2, result &re)
{
	int cnt = 0;
	double loss = 0;
	ui u;
	u.init();
	while (1) {
		peopleTurn(chequer, u);
		cnt++;
		if (judge(u,cnt))
		{
			for (int i = 0; i < u.compu.size(); i++)
			{
				Relu(in, c1, c2, re, u.compu[i], -log10(loss));
				cout << "you win" << endl;
				return;
			}
		}
		
		compuTurn(chequer, in, c1, c2, re, loss, u);
		cnt++;
		if (judge(u,cnt))
		{
			for (int i = 0; i < u.compu.size(); i++)
			{
				Relu(in, c1, c2, re, u.compu[i], -log10(loss));
				cout << "you lose" << endl;
				return;
			}
		}
	}
}
void renewAll(int chequer[10], inputcell* in, cell1* c1, cell2* c2, result& re) {
	for (int i = 1; i < 10; i++)
	{
		in[i].score = chequer[i];
	}
	for (int i = 0; i < 10; i++)
	{
		c1[i].renew();
	}
	for (int i = 0; i < 10; i++)
	{
		c2[i].renew();
	}
	re.renew();
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
	while (1) {
		int chequer[10] = { 0 };
		totalProcess(chequer, in, c1, c2, re);
		cout << "continue?(y/n)" << endl;
		char choice;
		cin >> choice;
		flag:
		if (choice == 'y')
		{
			continue;
		}
		else if(choice=='n')
		{
			cout << "bye" << endl;
		}
		else {
			cout << "no this selection" << endl;
			goto flag;
		}
	}
	
	
	return 0;
}
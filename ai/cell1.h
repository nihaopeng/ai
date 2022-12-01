#pragma once
class cell1 {
public:
	double score[10];
	double weight[10][10];
	double loss(double,int,int,double);
	double giveScore();
	void init();
	void renew();
};
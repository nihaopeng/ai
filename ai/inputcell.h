#pragma once
class inputcell {
public:

	double score;
	double weight[10][10];
	void loss(double,int,int,double);
	double giveScore();
	void init();
};
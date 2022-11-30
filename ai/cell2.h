#pragma once
class cell2 {
public:

	double score;
	double weight[10];
	double loss(double,int);
	double giveScore();
	void init();
};
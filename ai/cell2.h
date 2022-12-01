#pragma once
class cell2 {
public:

	double score[10];
	double weight[10];
	double loss(double,int);
	double giveScore();
	void init();
	void renew();
};
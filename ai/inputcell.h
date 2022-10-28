#pragma once
class inputcell {
public:

	double score;
	double weight[10][10];
	void loss(int);
	double giveScore();
	void init();
};
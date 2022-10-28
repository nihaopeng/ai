#pragma once
class inputcell {
public:

	int score;
	int weight[10];
	void loss(int);
	int giveScore();
};
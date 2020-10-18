#ifndef TOURNAMENT_PREDICTOR_H
#define TOURNAMENT_PREDICTOR_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "TwoBitPredictor.h"
#include "GSharePredictor.h"

class TournamentPredictor {
private:
	const std::string NOT_TAKEN = "NT";
	const std::string TAKEN = "T";
	const int TAKE = 1;
	const int NO_TAKE = 0;
	const int STRONG_TWOBIT = 3;
	const int STRONG_GSHARE = 0;
	const int WEAK_GSHARE = 1;
	unsigned long predictions_made;
	unsigned long correct;
	unsigned long incorrect;
	double accuracy;
	int* mem_table;
	unsigned long history_size;
	GSharePredictor global = GSharePredictor((unsigned long)11);
	TwoBitPredictor bits = TwoBitPredictor((unsigned long)2048);
public:
	TournamentPredictor(unsigned long);
	~TournamentPredictor();
	void setAccuracy() {
		this->accuracy = ((double)this->correct / this->predictions_made) * 100;
	}
	double getAccuracy() {
		setAccuracy();
		return this->accuracy;
	}
	unsigned long getCorrect() {
		return this->correct;
	}
	unsigned long getIncorrect() {
		return this->incorrect;
	}
	unsigned long getTotal() {
		return this->predictions_made;
	}
	unsigned long getSize() {
		return this->history_size;
	}
	void predict(std::string behavoir, unsigned long long address);
};

#endif

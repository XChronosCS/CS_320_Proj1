#ifndef G_SHARE_PREDICTOR_H
#define G_SHARE_PREDICTOR_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <bitset>

class GSharePredictor {
private:
	const std::string NOT_TAKEN = "NT";
	const std::string TAKEN = "T";
	const int TAKE = 1;
	const int NO_TAKE = 0;
	const int STRONG_TAKE = 3;
	const int STRONG_NO_TAKE = 0;
	std::bitset<11> global_history;
	unsigned long bit_size;
	unsigned long predictions_made;
	unsigned long correct;
	unsigned long incorrect;
	bool last_prediction;
	double accuracy;
	int* mem_table;
	unsigned long history_size;
public:
	GSharePredictor(unsigned long);
	~GSharePredictor();
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
	bool getResult() {
		return this->last_prediction;
	}
	std::bitset<11> getGlobal() {
		return this->global_history;
	}
	void predict(std::string behavoir, unsigned long long address);
};

#endif
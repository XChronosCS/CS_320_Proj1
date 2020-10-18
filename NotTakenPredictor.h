#ifndef NOT_TAKEN_PREDICTORS_H
#define NOT_TAKEN_PREDICTOR_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>


class NTPredictor {
private:
	const std::string NOT_TAKEN = "NT";
	unsigned long predictions_made;
	unsigned long correct;
	unsigned long incorrect;
	double accuracy;
public:
	NTPredictor();
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
	void predict(std::string behavoir);
};

NTPredictor::NTPredictor() {
	this->predictions_made = 0;
	this->correct = 0;
	this->incorrect = 0;
	this->accuracy = 0;
}

void NTPredictor::predict(std::string behavoir) {
	if (behavoir == this->NOT_TAKEN) {
		this->correct++;
	}
	else {
		this->incorrect++;
	}
	this->predictions_made++;
}
#endif

#ifndef TAKEN_PREDICTORS_H
#define TAKEN_PREDICTOR_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>


class TakenPredictor {
private:
	const std::string TAKEN = "T";
	unsigned long predictions_made;
	unsigned long correct;
	unsigned long incorrect;
	double accuracy;
public:
	TakenPredictor();
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

TakenPredictor::TakenPredictor() {
	this->predictions_made = 0;
	this->correct = 0;
	this->incorrect = 0; 
	this->accuracy = 0;
}

void TakenPredictor::predict(std::string behavoir) {
	if (behavoir == this->TAKEN) {
		this->correct++;
	}
	else {
		this->incorrect++;
	}
	this->predictions_made++;
}
#endif
#include "TwoBitPredictor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

TwoBitPredictor::TwoBitPredictor(unsigned long size) {
	this->predictions_made = 0;
	this->correct = 0;
	this->incorrect = 0;
	this->accuracy = 0;
	this->mem_table = new int[size];
	this->history_size = size;
	for (unsigned int i = 0; i < size; i++) {
		mem_table[i] = this->STRONG_TAKE;
	}
	this->last_prediction = false;
}

void TwoBitPredictor::predict(std::string behavior, unsigned long long address) {
	int index = (int)address % this->history_size;
	int correct_prediction = (behavior == this->TAKEN) ? this->TAKE : this->NO_TAKE;
	if ((mem_table[index] & 2)  == (correct_prediction << 1)) {
		this->correct++;
		this->last_prediction = true;
	}
	else {
		this->incorrect++;
		this->last_prediction = false;
	}
	if (correct_prediction == this->TAKE) {
		if (mem_table[index] != this->STRONG_TAKE) {
			mem_table[index]++;
		}
	}
	else {
		if (mem_table[index] != this->STRONG_NO_TAKE){
			mem_table[index]--;
		}
	}
	this->predictions_made++;
}

TwoBitPredictor::~TwoBitPredictor() {
	delete[] mem_table;
}
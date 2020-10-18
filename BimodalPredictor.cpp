#include "BimodalPredictor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

BimodalPredictor::BimodalPredictor(unsigned long size) {
	this->predictions_made = 0;
	this->correct = 0;
	this->incorrect = 0;
	this->accuracy = 0;
	this->mem_table = new int[size];
	this->history_size = size;
	for (unsigned int i = 0; i < size; i++) {
		mem_table[i] = this->TAKE;
	}
}

void BimodalPredictor::predict(std::string behavior, unsigned long long address) {
	int index = (int)address % this->history_size;
	int correct_prediction = (behavior == this->TAKEN) ? this->TAKE : this->NO_TAKE;
	if (mem_table[index] == correct_prediction) {
		this->correct++;
	}
	else {
		this->incorrect++;
		if (behavior == this->NOT_TAKEN) {
			mem_table[index] = this->NO_TAKE;
		}
		else {
			mem_table[index] = this->TAKE;
		}
	}
	this->predictions_made++;
}
#include "BTBPredictor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

BTBPredictor::BTBPredictor(unsigned long size) {
	this->predictions_made = 0;
	this->correct = 0;
	this->incorrect = 0;
	this->accuracy = 0;
	this->mem_table = new int[size];
	this->btb_table = new unsigned long long[size];
	this->history_size = size;
	for (unsigned int i = 0; i < size; i++) {
		mem_table[i] = this->TAKE;
	}
}

void BTBPredictor::predict(std::string behavior, unsigned long long address, unsigned long long target) {
	unsigned long long tar_var;
	unsigned long index = (unsigned long)address % this->history_size;
	int correct_prediction = (behavior == this->TAKEN) ? this->TAKE : this->NO_TAKE;
	if (this->mem_table[index] == this->TAKE) {
		predictions_made++;
		tar_var = this->btb_table[index];
		if (tar_var == target) {
			correct++;
		}
	}
	if (this->mem_table[index] != correct_prediction) {
		this->incorrect++;
		if (behavior == this->NOT_TAKEN) {
			mem_table[index] = this->NO_TAKE;
		}
		else {
			mem_table[index] = this->TAKE;
		}
	}
	if (correct_prediction == this->TAKE) {
		this->btb_table[index] = target;
	}
}

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "TournamentPredictor.h"

TournamentPredictor::TournamentPredictor(unsigned long size) {
	this->predictions_made = 0;
	this->correct = 0;
	this->incorrect = 0;
	this->accuracy = 0;
	this->mem_table = new int[size];
	this->history_size = size;
	for (unsigned int i = 0; i < size; i++) {
		mem_table[i] = this->STRONG_GSHARE;
	}
}

void TournamentPredictor::predict(std::string behavior, unsigned long long address) {
	int index = (int)address % this->history_size;
	this->bits.predict(behavior, address);
	this->global.predict(behavior, address);
	bool chosen_prediction = (mem_table[index] > this->WEAK_GSHARE) ? bits.getResult() : global.getResult();
	if (chosen_prediction) { //if the prediction chosen was accurate
		this->correct++;
	}
	else {
		this->incorrect++;
	}
	if (this->bits.getResult() != this->global.getResult()) {
		if (this->bits.getResult()) {
			if (mem_table[index] != this->STRONG_TWOBIT) {
				mem_table[index]++;
			}
		}
		else {
			if (mem_table[index] != this->STRONG_GSHARE) {
				mem_table[index]--;
			}
		}
	}
	this->predictions_made++;
}

TournamentPredictor::~TournamentPredictor() {
	delete[] mem_table;
}
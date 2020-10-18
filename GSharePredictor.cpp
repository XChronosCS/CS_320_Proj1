#include "GSharePredictor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <bitset>

GSharePredictor::GSharePredictor(unsigned long size) {
	this->predictions_made = 0;
	this->correct = 0;
	this->incorrect = 0;
	this->accuracy = 0;
	this->bit_size = size;
	this->mem_table = new int[2048];
	this->history_size = 2048;
	this->last_prediction = false;
	for (unsigned int i = 0; i < this->history_size; i++) {
		mem_table[i] = this->STRONG_TAKE;
	}
}

void GSharePredictor::predict(std::string behavior, unsigned long long address) {
	std::bitset<48> addr_bits(address);
	std::bitset<11> pc_bits;
	for (unsigned int i = 0; i < 11; i++) {
		pc_bits[i] = addr_bits[i];
	}
	pc_bits ^= this->global_history; //xor's the bits
	int index = (unsigned int)(pc_bits.to_ulong()) % this->history_size;
	int correct_prediction = (behavior == this->TAKEN) ? this->TAKE : this->NO_TAKE;
	if ((mem_table[index] & 2) == (correct_prediction << 1)) {
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
		if (mem_table[index] != this->STRONG_NO_TAKE) {
			mem_table[index]--;
		}
	}
	this->predictions_made++;
	this->global_history <<= 1;
	for (unsigned int i = 11; i >= this->bit_size; i--) {
		this->global_history[i] = 0;
	}
	this->global_history[0] = (behavior == this->TAKEN) ? true : false;
}

GSharePredictor::~GSharePredictor() {
	delete[] mem_table;
}
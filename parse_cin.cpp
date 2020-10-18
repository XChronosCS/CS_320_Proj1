#include<iostream>
#include<fstream>
#include<string>

#include "GSharePredictor.h"

using namespace std;

int main(int argc, char* argv[]) {

	// Temporary variables
	unsigned long long addr;
	string behavior;
	unsigned long long target;
	GSharePredictor test1 = GSharePredictor((unsigned long)3);
	// Open file for reading
	ifstream infile("short_trace1.txt");

	// The following loop will read a hexadecimal number and
	// a string each time and then output them
	while (infile >> std::hex >> addr >> behavior >> std::hex >> target) {
		/*
		cout << addr;
		if(behavior == "T") {
		  cout << " -> taken, ";
		}else {
		  cout << " -> not taken, ";
		}
		cout << "target=" << target << endl;
		*/

		test1.predict(behavior, addr);
	}
	cout << test1.getCorrect() << "," << test1.getTotal() << ";";
	cout << endl;
	return 0;
}


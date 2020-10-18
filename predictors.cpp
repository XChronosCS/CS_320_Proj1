
#include<iostream>
#include<fstream>
#include<string>
#include "TakenPredictor.h"
#include "NotTakenPredictor.h"
#include "BimodalPredictor.h"
#include "TwoBitPredictor.h"
#include "GSharePredictor.h"
#include "TournamentPredictor.h"
#include "BTBPredictor.h"

int main(int argc, char* argv[]) {
	unsigned long long addr;
	std::string behavior;
	unsigned long long target;
	char* input_file = argv[1];
	char* output_file = argv[2];
	std::ifstream input;
	input.open(input_file);
	std::ofstream output;
	output.open(output_file);
	TakenPredictor take_all = TakenPredictor();
	NTPredictor take_none = NTPredictor();
	BimodalPredictor bimodal16 = BimodalPredictor((unsigned long)16);
	BimodalPredictor bimodal32 = BimodalPredictor((unsigned long)32);
	BimodalPredictor bimodal128 = BimodalPredictor((unsigned long)128);
	BimodalPredictor bimodal256 = BimodalPredictor((unsigned long)256);
	BimodalPredictor bimodal512 = BimodalPredictor((unsigned long)512);
	BimodalPredictor bimodal1024 = BimodalPredictor((unsigned long)1024);
	BimodalPredictor bimodal2048 = BimodalPredictor((unsigned long)2048);
	TwoBitPredictor twobit16 = TwoBitPredictor((unsigned long)16);
	TwoBitPredictor twobit32 = TwoBitPredictor((unsigned long)32);
	TwoBitPredictor twobit128 = TwoBitPredictor((unsigned long)128);
	TwoBitPredictor twobit256 = TwoBitPredictor((unsigned long)256);
	TwoBitPredictor twobit512 = TwoBitPredictor((unsigned long)512);
	TwoBitPredictor twobit1024 = TwoBitPredictor((unsigned long)1024);
	TwoBitPredictor twobit2048 = TwoBitPredictor((unsigned long)2048);
	GSharePredictor gshare3 = GSharePredictor((unsigned long)3);
	GSharePredictor gshare4 = GSharePredictor((unsigned long)4);
	GSharePredictor gshare5 = GSharePredictor((unsigned long)5);
	GSharePredictor gshare6 = GSharePredictor((unsigned long)6);
	GSharePredictor gshare7 = GSharePredictor((unsigned long)7);
	GSharePredictor gshare8 = GSharePredictor((unsigned long)8);
	GSharePredictor gshare9 = GSharePredictor((unsigned long)9);
	GSharePredictor gshare10 = GSharePredictor((unsigned long)10);
	GSharePredictor gshare11 = GSharePredictor((unsigned long)11);
	TournamentPredictor tourny = TournamentPredictor((unsigned long)2048);
	BTBPredictor btb = BTBPredictor((unsigned long)512);
	// The following loop will read a hexadecimal number and
	// a string each time and then output them
	while (input >> std::hex >> addr >> behavior >> std::hex >> target) {
		take_all.predict(behavior);
		take_none.predict(behavior);
		bimodal16.predict(behavior, addr);
		bimodal32.predict(behavior, addr);
		bimodal128.predict(behavior, addr);
		bimodal256.predict(behavior, addr);
		bimodal512.predict(behavior, addr);
		bimodal1024.predict(behavior, addr);
		bimodal2048.predict(behavior, addr);
		twobit16.predict(behavior, addr);
		twobit32.predict(behavior, addr);
		twobit128.predict(behavior, addr);
		twobit256.predict(behavior, addr);
		twobit512.predict(behavior, addr);
		twobit1024.predict(behavior, addr);
		twobit2048.predict(behavior, addr);
		gshare3.predict(behavior, addr);
		gshare4.predict(behavior, addr);
		gshare5.predict(behavior, addr);
		gshare6.predict(behavior, addr);
		gshare7.predict(behavior, addr);
		gshare8.predict(behavior, addr);
		gshare9.predict(behavior, addr);
		gshare10.predict(behavior, addr);
		gshare11.predict(behavior, addr);
		tourny.predict(behavior, addr);
		btb.predict(behavior, addr, target);
	}
	output << take_all.getCorrect() << "," << take_all.getTotal() << ";" << std::endl;
	output << take_none.getCorrect() << "," << take_none.getTotal() << ";" << std::endl;
	output << bimodal16.getCorrect() << "," << bimodal16.getTotal() << "; ";
	output << bimodal32.getCorrect() << "," << bimodal32.getTotal() << "; ";
	output << bimodal128.getCorrect() << "," << bimodal128.getTotal() << "; ";
	output << bimodal256.getCorrect() << "," << bimodal256.getTotal() << "; ";
	output << bimodal512.getCorrect() << "," << bimodal512.getTotal() << "; ";
	output << bimodal1024.getCorrect() << "," << bimodal1024.getTotal() << "; ";
	output << bimodal2048.getCorrect() << "," << bimodal2048.getTotal() << ";" << std::endl;
	output << twobit16.getCorrect() << "," << twobit16.getTotal() << "; ";
	output << twobit32.getCorrect() << "," << twobit32.getTotal() << "; ";
	output << twobit128.getCorrect() << "," << twobit128.getTotal() << "; ";
	output << twobit256.getCorrect() << "," << twobit256.getTotal() << "; ";
	output << twobit512.getCorrect() << "," << twobit512.getTotal() << "; ";
	output << twobit1024.getCorrect() << "," << twobit1024.getTotal() << "; ";
	output << twobit2048.getCorrect() << "," << twobit2048.getTotal() << ";" << std::endl;
	output << gshare3.getCorrect() << "," << gshare3.getTotal() << "; ";
	output << gshare4.getCorrect() << "," << gshare4.getTotal() << "; ";
	output << gshare5.getCorrect() << "," << gshare5.getTotal() << "; ";
	output << gshare6.getCorrect() << "," << gshare6.getTotal() << "; ";
	output << gshare7.getCorrect() << "," << gshare7.getTotal() << "; ";
	output << gshare8.getCorrect() << "," << gshare8.getTotal() << "; ";
	output << gshare9.getCorrect() << "," << gshare9.getTotal() << "; ";
	output << gshare10.getCorrect() << "," << gshare10.getTotal() << "; ";
	output << gshare11.getCorrect() << "," << gshare11.getTotal() << ";" << std::endl;
	output << tourny.getCorrect() << "," << tourny.getTotal() << ";" << std::endl;
	output << btb.getCorrect() << "," << btb.getTotal() << ";" << std::endl;
	output << std::endl;
	input.close();
	output.close();
	return 0;
}
M = predictors
R = TournamentPredictor
B = BTBPredictor
D = BimodalPredictor
T = TwoBitPredictor
G = GSharePredictor
CFLAGS= -g -Wall -Werror -std=c++14

all: $(M)

$(M): $(M).o $(R).o $(B).o $(T).o $(G).o $(D).o
	g++ $(CFLAGS) $(M).o $(R).o  $(B).o $(T).o $(G).o $(D).o -o $(M)

$(M).o: $(M).cpp
	g++ $(CFLAGS) -c $(M).cpp -o $(M).o

$(R).o: $(R).cpp
	g++ $(CFLAGS) -c $(R).cpp -o $(R).o
$(G).o: $(G).cpp
	g++ $(CFLAGS) -c $(G).cpp -o $(G).o
$(T).o: $(T).cpp
	g++ $(CFLAGS) -c $(T).cpp -o $(T).o
$(D).o: $(D).cpp
	g++ $(CFLAGS) -c $(D).cpp -o $(D).o
$(B).o: $(B).cpp
	g++ $(CFLAGS) -c $(B).cpp -o $(B).o



.PHONY: clean all memcheck


clean:
	rm -rf *.o $(M).o $(M) 

memcheck: $(M)
	valgrind --leak-check=full ./$(M)

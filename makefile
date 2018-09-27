ensemble : Ensemble.o EnsembleTest.o
	g++ -o ensemble Ensemble.o EnsembleTest.o -Werror -pedantic -Wall

ens.o : Ensemble.h Ensemble.cpp
	g++ -c Ensemble.cpp -Werror -pedantic -Wall

ensT.o : EnsembleTest.h EnsembleTest.cpp
	g++ -c EnsembleTest.cpp -Werror -pedantic -Wall

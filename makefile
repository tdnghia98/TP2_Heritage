CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=voyage
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

voyage: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: voyage.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

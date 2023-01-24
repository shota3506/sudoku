OBJ=board.o solver.o game.o

all: $(OBJ)
	g++ -Wall main.cpp -o sudoku $(OBJ)

clean:
	rm $(OBJ) sudoku

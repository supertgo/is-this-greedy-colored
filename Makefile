CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/graph.h $(INC)/heap.h $(INC)/vertex.h
OBJS = $(OBJ)/main.o $(OBJ)/graph.o $(OBJ)/heap.o $(OBJ)/vertex.o
CFLAGS = -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/tp2.out

all: run

run: $(EXE)
	$(EXE)

$(BIN)/tp2.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/tp2.out $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out

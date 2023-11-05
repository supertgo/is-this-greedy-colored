CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/graph.h $(INC)/vertex.h $(INC)/memlog.h $(INC)/msgassert.h
OBJS = $(OBJ)/main.o $(OBJ)/graph.o $(OBJ)/vertex.o $(OBJ)/memlog.o
CFLAGS = -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/tp2.out

all:  mem perf gprof
mem: $(EXE)
	$(EXE)

perf: $(EXE)
	$(EXE)

gprof: $(EXE)
	$(EXE)
	gprof $(EXE) gmon.out > /tmp/greedy.txt

$(BIN)/tp2.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/tp2.out $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJ)/*.o gmon.out

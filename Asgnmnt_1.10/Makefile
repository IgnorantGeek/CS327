CC = gcc
CXX = g++
ECHO = echo
RM = rm -f

CXXFLAGS = -Wall -Werror
LDFLAGS = -lncurses

BIN = PuzzleGame
OBJS = PuzzleGame.o Puzzle.o PuzzleReader.o PuzzleRunner.o

all: $(BIN) etags

$(BIN): $(OBJS)
	@$(ECHO) Linking $@
	@$(CXX) $^ -o $@ $(LDFLAGS)

-include $(OBJS:.o=.d)

%.o: %.cpp
	@$(ECHO) Compiling $<
	@$(CXX) $(CXXFLAGS) -MMD -MF $*.d -c $<

.PHONY: all clean clobber etags

clean:
	@$(ECHO) Removing all generated files
	@$(RM) *.o $(BIN) *.d TAGS core vgcore.* gmon.out

clobber: clean
	@$(ECHO) Removing backup files
	@$(RM) *~ \#* *pgm

etags:
	@$(ECHO) Updating TAGS
	@etags *.c *.cpp *.h
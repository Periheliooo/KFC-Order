.DEFAULT_GOAL := all

EXE := main.exe

$(EXE): *.cpp
	g++ -Wall -g -o $@ $^

.PHONY: all
all: $(EXE)

.PHONY: run
run: $(EXE)
	@echo '... Here comes your program ...'
	@./$(EXE)

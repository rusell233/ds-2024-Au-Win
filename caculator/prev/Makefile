CC=g++
CFLAGS=-std=c++11 -Wall

all: calculator run

calculator:
	$(CC) $(CFLAGS) calculator.cpp -o calculator

run:
	./calculator

report:
	pdflatex report.tex

clean:
	rm -f calculator
	rm -f report.aux
	rm -f report.log
	rm -f report.pdf

.PHONY: all calculator run report clean
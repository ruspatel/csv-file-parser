all: csv-parser

csv-parser: main.cpp
	g++ -std=c++11 -o csv-parse main.cpp

clean:
	rm *.o csv-parse
all: csv-parser

csv-parser: parser.h parser.cpp main.cpp
	g++ -std=c++11 -o csv-parse main.cpp parser.cpp

clean:
	rm *.o csv-parse
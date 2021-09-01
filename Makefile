all: csv-parser

csv-parser: parser.h fileHelper.h parser.cpp main.cpp fileHelper.cpp
	g++ -std=c++11 -o csv-parse main.cpp parser.cpp fileHelper.cpp

clean:
	rm *.o csv-parse
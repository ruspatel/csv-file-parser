#include "parser.h"
#include "stdio.h"
#include <vector>

parser::parser(){ // constructor

}

int parser::findNan(){

    return 0;
}

int parser::calculateMean(){

    return 0;
}

char* parser::readLine(int lineNumber){
    char* line = new char[256];

    FILE *fptr = fopen("sample.csv", "r");

    if(fptr == NULL){
        std::cout<<"Error: Cannot open file"<<std::endl;
        return line;
    }
   
    for(int i=0; i < lineNumber; i++){
        fgets(line, 256, fptr);
    }

    for(int i=0; i < strlen(line); i++){
        std::cout<<line[i];
    }
    std::cout<<std::endl;


    fclose(fptr);

    return line;
}

parser::~parser(){ // destructor
    
}
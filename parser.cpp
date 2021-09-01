#include "parser.h"
#include "stdio.h"
#include <vector>

parser::parser(){ // constructor

}

int parser::findNan(char* fileName){
    char* line = new char[256];

    FILE *fptr = fopen(fileName, "r");

    if(fptr == NULL){
        std::cout<<"Error: Cannot open file"<<std::endl;
        return -1;
    }

    std::vector<int> nullRows;
    int rowCount = 0;
    while(fgets(line, 256, fptr) != NULL){
        rowCount++;
        int lineLength = strlen(line);
        for(int i=0; i < lineLength-1; i++){
            if((line[i] == ',' && line[i+1] == ',') || (line[lineLength-2] == ',')){
                nullRows.push_back(rowCount);
                break;
            }
        }
    }
    std::cout<<"Rows with missing entries: ";

    int nullRowsSize = nullRows.size();
    for(int i=0; i < nullRowsSize-1; i++){
        std::cout<<nullRows[i]<<",";
    }
    std::cout<<nullRows[nullRowsSize-1]<<std::endl;

    delete[] line;
    fclose(fptr);

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

    delete[] line;
    fclose(fptr);

    return line;
}

parser::~parser(){ // destructor
    
}
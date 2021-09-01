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

int parser::calculateColumnMean(char* fileName, char* columnName){
    int columnEntries = 0;
    int columnSum = 0;
    char* line = new char[256];

    FILE *fptr = fopen(fileName, "r");
    if(fptr == NULL){
        std::cout<<"Error: Cannot open file"<<std::endl;
        return -1;
    }
    
    std::string columnStr = "";
    int columnIndex = -1;

    if(fgets(line, 256, fptr) != NULL){
        for(int i=0; i < strlen(line); i++){
            if(line[i] != ','){
                columnStr += line[i];
            }
            if(line[i] == ',' || i == strlen(line)-1){
                columnIndex++;
                const char* ColumnStrName = columnStr.c_str();
                if(this->fileHelperTool.compareStrings(ColumnStrName, columnName)){
                    break;
                }else{
                    columnStr = "";
                }
            }
        }
    }

    std::string rowVal;
    while(fgets(line, 256, fptr) != NULL){
        int lineLength = strlen(line);
        int commaCount = 0;
        rowVal = "";
        for(int i=0; i < lineLength; i++){
            if(line[i] == ',' || i == strlen(line)-1){
                if(commaCount == columnIndex && rowVal != ""){
                    columnEntries++;
                    try{
                        columnSum += std::stoi(rowVal);
                    }catch(std::invalid_argument e){
                        std::cout<<"Error: non-numeric row entry"<<std::endl;
                        return -1;
                    }
                    break;
                }
                commaCount++;
            }else if(commaCount == columnIndex){
                rowVal += line[i];
            }
        }
    }

    int columnMean = columnSum/columnEntries;

    std::cout<<columnName<<" Mean: "<<columnMean<<std::endl;

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
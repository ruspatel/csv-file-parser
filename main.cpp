#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "parser.h"

bool compareStrings(const char* str1, const char* str2){
    if(strlen(str1) != strlen(str2)){
        return false;
    }

    for(int i=0; i < strlen(str1); i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }
    
    return true;
}

int main(int argc, char** argv){
    parser parserTool;
    if(argc < 2){
        std::cout<<"Not enough input parameters"<<std::endl;
        return -1;
    }

    const char* findNan = "findNan";
    const char* calculateMean = "calculateMean";

    if(compareStrings(argv[1], findNan)){
        std::cout<<"findNan received"<<std::endl;
        parserTool.findNan();
    }else if(compareStrings(argv[1], calculateMean)){
        std::cout<<"calculateMean received"<<std::endl;
    }
    
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "parser.h"
#include "fileHelper.h"

int main(int argc, char** argv){
    parser parserTool;
    FileHelper fileHelperTool;

    if(argc < 2){
        std::cout<<"Not enough input parameters"<<std::endl;
        return -1;
    }

    const char* findNan = "findNan";
    const char* calculateMean = "calculateMean";

    if(fileHelperTool.compareStrings(argv[1], findNan)){
        std::cout<<"findNan received"<<std::endl;
        if(fileHelperTool.isFileNameProvided(argc)){
            parserTool.findNan(argv[2]);
        }
    }else if(fileHelperTool.compareStrings(argv[1], calculateMean)){
        std::cout<<"calculateMean received"<<std::endl;
    }
    
    return 0;
}
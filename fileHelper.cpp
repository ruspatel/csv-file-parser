#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "fileHelper.h"

FileHelper::FileHelper(){ // constructor

}

bool FileHelper::compareStrings(const char* str1, const char* str2){
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

bool FileHelper::isFileNameProvided(int numInputParams){
    if(numInputParams < 3){
        std::cout<<"Please provide a csv file name"<<std::endl;
        return false;
    }

    return true;
}

FileHelper::~FileHelper(){ // destructor
    
}
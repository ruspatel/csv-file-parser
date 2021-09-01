#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

class FileHelper{
    public:
        FileHelper();
        ~FileHelper();
        bool compareStrings(const char* str1, const char* str2);
        bool isFileNameProvided(int numInputParams);
        bool isColumnNameProvided(int numInputParams);

    private:

};
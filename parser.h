#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "fileHelper.h"

class parser{
    public:
        parser();
        ~parser();
        int findNan(char* fileName);
        int calculateColumnMean(char* fileName, char* columnName);
        char* readLine(int lineNumber);


    private:
        FileHelper fileHelperTool;

};
#include <iostream>
#include "tagstruct"
#include "functions"
#define string std::string


int main(int argc, char* argv[]) {
    string fileName;
    
     if(argc == 1)
        fileName = "simple.txt";
   else
        fileName = argv[1];


    SHVNKA005::menu(fileName);

    return 0;

}
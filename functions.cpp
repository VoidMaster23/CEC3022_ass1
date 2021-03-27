#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "functions"
#include <queue>
#include <vector>
#include <regex>
#include <algorithm>
#include <stack>
#define string std::string
#define str_queue std::queue<string>
#define tag_vector std::vector<tagStruct>


namespace SHVNKA005 {
  void readFile(string fileName, str_queue &inQueue, tag_vector &outVect) {
    std::ifstream in(fileName);

    if (!in) {
        std::cerr << "Couldn't open file " << fileName << std::endl;
        throw "File could not be opened";
    }

    //define an individual line
    string line;
    while (std::getline(in,line)) {
        processLine(line, inQueue, outVect);
    }

    in.close();

}

void processLine(string line, str_queue &inQueue, tag_vector &outVect) {
std::cout << line << std::endl;
}


void prepareOutput(str_queue &inputQueue, tag_vector &outputvector ) {
    
} 

}   


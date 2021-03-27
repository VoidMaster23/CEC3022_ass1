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
string text = "";
string tagText ="";

std::regex tag ("<[^\\s*].+?>");
//loop through each character 

if(line[0] != '<' && line[0] != '\t') {
        inQueue.push(line);
    } else {

    for(string::size_type i = 0; i < line.size(); ++i) {

    

    char myChar  = line[i];
    if (myChar != '\t' && myChar != '\n'){
        if (myChar == '<') {
            tagText = "";

        }
        text += myChar;
        tagText += myChar;

        
        if(std::regex_match (tagText, tag) && myChar == '>') {
            
          

            if (tagText != text) {
                //string contains the other string
                auto startInd = text.find(tagText);
                if (startInd != string::npos) {
                   //  std::cout << "I AM HERE" << std::endl;
                     text.replace(startInd, tagText.size(), " ");
                }
            }

            // at this point place the tag into the queue
            

            if (!std::regex_match(text, tag)) {
            inQueue.push(text);
            
            std::cout << text << std::endl;
            std::cout << std::endl;
            }

            std::cout << tagText << std::endl;
            inQueue.push(tagText);


            text = "";
            tagText = "";
        }

        
    }
    }
}


}


void prepareOutput(str_queue &inputQueue, tag_vector &outputvector ) {
    for (str_queue dump = inputQueue; !dump.empty(); dump.pop())
    
        std::cout << dump.front() << std::endl;

    std::cout << "(" << inputQueue.size() << " elements)\n";
} 

}   


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
std::regex tag ("<[^\\s*].+?>");
std::regex closingTag("</[^\\s*].+?>");

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


//loop through each character 

if(line[0] != '<' && line[0] != '\t') {
        line.replace(line.size()-1, 1, "");
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
            }

            inQueue.push(tagText);


            text = "";
            tagText = "";
        }

        
    }
    }
}


}


void prepareOutput(str_queue &inputQueue, tag_vector &outputvector ) {
    for (str_queue dump = inputQueue; !dump.empty(); dump.pop()) {
        string current = dump.front();
    dump.pop();
    tagStruct tagS;

     if (!std::regex_match(current, closingTag)) {

    if(std::regex_match(current, tag) && !std::regex_match(dump.front(), tag)) {
        // check if the tag has already been added
        current.replace(0, 1, "");
        current.replace(current.size()-1, 1, "");
        bool found= false;

       std::for_each(outputvector.begin(), outputvector.end(), [&found, &dump, &current](tagStruct &tempTag) {
           if(tempTag.tagName == current) {
               
               tempTag.tagText += ":"+dump.front();
               tempTag.numPairs++;
               found = true;
           }
       });

        //found = false ==>> create a tagstruct and place it into into the vector
       if(!found) {
           tagS.numPairs = 1;
           tagS.tagName = current;
           tagS.tagText = dump.front();
           outputvector.push_back(tagS);
       }

       dump.pop();

       
    }
    }


    }
        
        
} 

}   


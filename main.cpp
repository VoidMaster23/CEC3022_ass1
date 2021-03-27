#include <iostream>
#include "tagstruct"
#include "functions"
#define str std::string
#define str_queue std::queue<str>
#define tag_vector std::vector<SHVNKA005::tagStruct>

int main(int argc, char* argv[]) {
    SHVNKA005::tagStruct test;
    str fileName;
    str_queue inQueue;
    tag_vector outVect;

    if(argc == 1)
        fileName = "simple.txt";
   else
        fileName = argv[1];
    

    SHVNKA005::readFile(fileName, inQueue, outVect);
    SHVNKA005::prepareOutput(inQueue, outVect);

    // std::cout << outVect.size() << std::endl;
    // for (int i=0; i<outVect.size(); i++){
    //    std::cout << outVect[i] << std::endl;
    // }

    
    // for (str_queue dump = inQueue; !dump.empty(); dump.pop())
    //     std::cout << dump.front() << std::endl;

    // std::cout << "(" << inQueue.size() << " elements)\n";


    return 0;

}
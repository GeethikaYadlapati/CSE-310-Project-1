#include <iostream>
#include <fstream>
using namespace std;
#include "defns.cpp"

int main(int argc, char* argv[]){
    initialize();
    ifstream inputFile;
    inputFile.open(argv[1]);
    //cout << argc << "\n";
    
    string line;
    while(getline(inputFile, line)){
    char *line2 = &line[0];
    int i = 0;
     while(line2[i]!= '\0' && line2[i] != '\n'){ 
         //go to each line count number of times each symbol repeated in line and 
         //increment freq field
         for(int j = 0; j < NSYMBOLS; j++){
             if(Symbols[j].symbol == line2[i]){
                 Symbols[j].freq++;
             }
         }
         i++;
     }
     Symbols[10].freq++;
    }
    inputFile.close();
    ofstream outputFile;
    outputFile.open(argv[2]);
    for(int j = 0; j < NSYMBOLS; j++){
        if(Symbols[j].freq != 0){
        outputFile << std::to_string(j) + "\t" + std::to_string(Symbols[j].freq) + "\n";
        }
    }
    outputFile.close();
    //create output file
    //iterate through array
    //write array content in formatted form in output file
    return 0;
}
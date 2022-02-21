#include <iostream>
#include <fstream>
#include "defns.h"
#include "defns.cpp"
#include "makeTree.cpp"
using namespace std;

int main(int argc, char* argv[]){

	symbol *Root = makeTree(argc, argv);

ifstream input;
input.open(argv[3]);
string skipLine;
getline(input, skipLine);
int num = stoi(skipLine); //freq greater than 0
int count = 0;
while(getline(input, skipLine) && count < num ){
count++;
}
string encodedLine;
string encodedLinePart;
while(getline(input, encodedLinePart)){
    encodedLine = encodedLine + encodedLinePart;
}
char *encodedLine2 = &encodedLine[0];
string decoded = "";
int i = 0;
struct symbol *currentNode = Root;
     while(encodedLine2[i] != '\0'){
         if(currentNode->left != NULL && currentNode->right != NULL){
             if(encodedLine2[i] == '0'){
                currentNode = currentNode->left;
             }else {
                 currentNode = currentNode->right;
             }
         }else{
             decoded = decoded + currentNode->symbol;
             currentNode = Root;
         }
         i++;
     }
     ofstream outputFile;
     outputFile.open(argv[4]);
     outputFile << decoded;
     outputFile.close();
return 0;
}
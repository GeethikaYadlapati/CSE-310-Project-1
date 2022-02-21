#include <iostream>
#include <fstream>
#include "defns.h"
#include "defns.cpp"
#include "makeTree.cpp"

using namespace std;

int buildOutput(int argc, char* argv[]);
string a;

int main(int argc, char* argv[]){
	symbol *Root = makeTree(argc, argv);
	return buildOutput(argc, argv);
}


int buildOutput(int argc, char* argv[])
{
int numOfSymbolsFreqGreaterThanZero = 0;
symbol *SymbolNode = Symbols;
symbol *currentNode = Symbols;
for(int i = 0; i < NSYMBOLS; i++){

int count = 0;


while(currentNode != NULL && currentNode->parent && currentNode->parent != NULL){

if(currentNode->parent->left == currentNode){
	Symbols[i].encoding[count] = '0';
}else {
	Symbols[i].encoding[count] = '1';
}
count++;

currentNode = currentNode->parent;

}
int index = 0;

int end = count;


while(index < end){ //reversing the encoding
char temp = Symbols[i].encoding[index];

Symbols[i].encoding[index] = Symbols[i].encoding[end-1];

Symbols[i].encoding[end-1] = temp;

index++;

end--;

}


if(Symbols[i].freq > 0){

numOfSymbolsFreqGreaterThanZero++;

}

SymbolNode++;
currentNode = SymbolNode;

}

ofstream outputFile;


outputFile.open(argv[4]);

outputFile << std::to_string(numOfSymbolsFreqGreaterThanZero) + "\n";

for(int j = 0; j < NSYMBOLS; j++){

if(Symbols[j].freq > 0){

outputFile << std::to_string(j) + "\t" + Symbols[j].symbol + "\t";//std::to_string(Symbols[j].symbol)

for(int p = 0; p < E_LEN; p++){            //8 is the length ig

outputFile << Symbols[j].encoding[p];
}

outputFile << "\n";

}

}

//using the encoding of symbols to encode input

//yet to write the code- easy


string lineEncoding = "";
string l;
ifstream input;
input.open(argv[3]);
while(getline(input, l)){
char *line2 = &l[0];
int i = 0;
     while(line2[i]!= '\0' /*&& line2[i] != '\n'*/){
         for(int ii = 0; ii < NSYMBOLS; ii++){
             if(Symbols[ii].symbol == line2[i]){
                 for(int j = 0; j < E_LEN; j++){
                	 if ( Symbols[ii].encoding[j] == '0' ||
                			 Symbols[ii].encoding[j] == '1' )
                     lineEncoding = lineEncoding + Symbols[ii].encoding[j];
                 }
             }
         }
i++;
}

for(int q = 0; q < E_LEN; q++){
	 if ( Symbols[10].encoding[q] == '0' ||
			 Symbols[10].encoding[q] == '1' )
	 {
		 lineEncoding = lineEncoding + Symbols[10].encoding[q];
	 }
}
lineEncoding = lineEncoding;

}
input.close();

outputFile << lineEncoding << "\n";

outputFile.close();
return 0;
}
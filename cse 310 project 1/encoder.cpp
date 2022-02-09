#include <iostream>
#include <fstream>
#include "main.cpp"
using namespace std;

int encoder(int argc, char* argv[]){
ifstream inputFile;
inputFile.open(argv[1]);
    string line;
    while(getline(inputFile, line)){
        char *line2 = &line[0];
        int i = 0;
     while(line2[i]!= '\0' && line2[i] != '\n'){
         if(line2[i] == '\t'){
             for(int j = 0; j < NSYMBOLS; j++){
                 if(Symbols[j].symbol == line[0]){
                    Symbols[j].freq = line[i+1];
                 
                 }
                 
             }
             
         }
         i++;
     }
    }

    tree Alpha[52];
    tree NonAlpha[76];
    for(int x = 65; x < 91; x++){
        for(int y = 97; y < 123; y++){
            Alpha[x].symbol = x;
            Alpha[y].symbol = y;
            for(int p = 0; p < NSYMBOLS; p++){
            if(Symbols[p].symbol == Alpha[x].symbol){
                Alpha[x].freq = Symbols[p].freq;
                Alpha[x].root = &Symbols[p];

            }
            if(Symbols[p].symbol == Alpha[y].symbol){
                Alpha[y].freq = Symbols[p].freq;
                Alpha[y].root = &Symbols[p];
            }
        }

        }
    }
    
    for(int i = 0; i < 65; i++){
        for(int j = 91; j < 97; j++){
            for(int k = 123; k < NSYMBOLS; k++){
                NonAlpha[i].symbol = i;
                NonAlpha[j].symbol = j;
                NonAlpha[k].symbol = k;
                for(int q = 0; q <  NSYMBOLS; q++){
                    if(Symbols[q].symbol == NonAlpha[i].symbol){
                        NonAlpha[i].freq = Symbols[q].freq;
                        NonAlpha[i].root = &Symbols[q];
                    }
                    if(Symbols[q].symbol == NonAlpha[j].symbol){
                        NonAlpha[j].freq = Symbols[q].freq;
                        NonAlpha[j].root = &Symbols[q];
                    }
                    if(Symbols[q].symbol == NonAlpha[k].symbol){
                        NonAlpha[k].freq = Symbols[q].freq;
                        NonAlpha[k].root = &Symbols[q];
                    }
                }
            }
        }
    }
    if(strcasecmp(argv[2],"insertion") == 0){
        int q, key;
        for(int p = 2; p < 52; p++){
            key = Alpha[p].freq;
            q = p - 1;
            while(q > 0 && Alpha[q].freq > key){
                Alpha[q + 1] = Alpha[q];
                q = q - 1;
            }
            Alpha[q + 1].freq = key;
        }

        int j, key2;
        for(int i = 2; i < 76; i++){
            key2 = NonAlpha[i].freq;
            j = i - 1;
            while(j > 0 && NonAlpha[j].freq > key2){
                NonAlpha[j + 1] = NonAlpha[j];
                j = j - 1;
            }
            NonAlpha[j + 1].freq = key2;
        }
    }else if(strcasecmp(argv[2],"merge") == 0){

    }else{
        cout << "invalid second argument. Type insertion or merge.";
    }
    
    while(sizeof(Alpha)/sizeof(Alpha[0]) != 0){
    struct symbol t;
    t.parent = NULL;
    t.left = Alpha[0].root;
    t.right = Alpha[1].root;
    t.freq = Alpha[0].freq + Alpha[1].freq;

    for(int j = 0; j < 52; j++){
        if(j != 0 || j != 1){
        Alpha[j] = Alpha[j - 2];
        }
    }
    for(int i = 0; i  < 52; i++){
        if(t.freq < Alpha[i].freq){
            for(int p = 51; p > i - 1; p--){
                Alpha[p] = Alpha[p - 1];
            }
            Alpha[i - 1].freq = t.freq;
            Alpha[i - 1].root = &t;
        }
    }
   
    }
    while(sizeof(NonAlpha)/sizeof(NonAlpha[0]) != 0){
    struct symbol t;
    t.parent = NULL;
    t.left = NonAlpha[0].root;
    t.right = NonAlpha[1].root;
    t.freq = NonAlpha[0].freq + NonAlpha[1].freq;

    for(int j = 0; j < 76; j++){
        if(j != 0 || j != 1){
        NonAlpha[j] = NonAlpha[j - 2];
        }
    }
    for(int i = 0; i  < 76; i++){
        if(t.freq < NonAlpha[i].freq){
            for(int p = 51; p > i - 1; p--){
                NonAlpha[p] = NonAlpha[p - 1];
            }
            NonAlpha[i - 1].freq = t.freq;
            NonAlpha[i - 1].root = &t;
        }
    }
   
    }

    //repeat the steps or try defining a method and calling it twice for  both the arrays

struct symbol dummyRoot;
struct symbol *Root = &dummyRoot;

Root->left = Alpha[0].root;

Root->right = NonAlpha[0].root;

int numOfSymbolsFreqGreaterThanZero = 0;

for(int i = 0; i < NSYMBOLS; i++){

struct symbol *currentNode = &Symbols[i];


int count = 0;

while(currentNode->parent != NULL){

if(currentNode->parent->left == currentNode){

currentNode->encoding[count] = 0;

}else { currentNode->encoding[count] = 1;

}

count++;

currentNode = currentNode -> parent;


}

int index = 0;

int end = count + 1;

while(index < end){ //reversing the encoding

int temp = Symbols[i].encoding[index];

Symbols[i].encoding[index] = Symbols[i].encoding[end];

Symbols[i].encoding[end] = temp;

index++;

end--;

}

if(Symbols[i].freq > 0){

numOfSymbolsFreqGreaterThanZero++;

}



}

ofstream outputFile;


outputFile.open(argv[4]);

outputFile << std::to_string(numOfSymbolsFreqGreaterThanZero) + "\n";

for(int j = 0; j < NSYMBOLS; j++){

if(Symbols[j].freq > 0){

outputFile << std::to_string(j) + "\t" + std::to_string(Symbols[j].symbol) + "\t";

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
     while(line2[i]!= '\0' && line2[i] != '\n'){
         for(int i = 0; i < NSYMBOLS; i++){
             if(Symbols[i].symbol == line2[i]){
                 for(int j = 0; j < E_LEN; j++){
                     lineEncoding = lineEncoding + Symbols[i].encoding[j];
                 }
             }
         }
i++;
}

for(int q = 0; q < E_LEN; q++){
    lineEncoding = lineEncoding + Symbols[10].encoding[q];
}
lineEncoding = lineEncoding + "\n";

}
input.close();

outputFile << lineEncoding;

outputFile.close();
return 0;
}
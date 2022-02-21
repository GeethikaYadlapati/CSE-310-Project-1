#ifndef MYINITIALIZE
#define	MYINITIALIZE	1

#include "defns.h"
using namespace std;

symbol *Symbols;

//symbol Symbols[NSYMBOLS];

void initialize();

void initialize(){

	Symbols = (symbol*) malloc(sizeof(symbol)*NSYMBOLS);


for(int i = 0; i < NSYMBOLS; i++){
    Symbols[i].symbol = i;
    Symbols[i].freq = 0;
    Symbols[i].parent = NULL;
    Symbols[i].left = NULL;
    Symbols[i].right = NULL;
    for(int j = 0; j < E_LEN; j++){
        Symbols[i].encoding[j] = '\0';
    }
}
}
#endif
#include "defns.h"
using namespace std;
void initialize();
symbol Symbols[NSYMBOLS];
void initialize(){

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
#include <stdio.h>
#include <stdlib.h>
#include "convertFunctions.h"
int main(){
    char* n="456";
    int b=10;
    char* hn=toHex(n,b);
    prettyPrint_ops(n,"decimal",hn,"hexadecimal");
    free(hn);
    return 0;

}
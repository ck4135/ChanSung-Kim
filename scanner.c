/// File: scanner.c
/// Author: ChanSung Kim
///         ck4135
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"
#include "scanner.h"

void process( state **matrix ) {
    char buf[BUFFER], *token;
    char c;
    token = buf;

    while ((c = getchar()) != EOF) {
        int cc = char_class(c);
        printf("%d\n", cc);
    }

    return;
}

int char_class( char cc ) {
    int class;
    int ascii = cc;
    if (*cc == *SPACE || *cc == *TAB) {
        class = CC_WS;
    } 
    else if (*cc == *NL) {
        class = CC_NL;
    } 
    else if (isalpha(cc) || *cc == *SCORE) {
        class = CC_ALPHA;
    } 
    else if ((int)*cc == 0) {
        class = CC_ZERO;
    } 
    else if ((int)*cc >= 1 && (int)*cc <= 7) {
        class = CC_OCTAL;
    }
    else if ((int)*cc == 8 || (int)*cc == 9) {
        class = CC_DECIMAL;
    }
    else if (*cc == *SLASH) {
        class = CC_SLASH;
    }
    else if (*cc == *STAR) {
        class = CC_STAR;
    }
    else if (*cc == *PLUS || *cc == *DASH || *cc == *MOD) {
        class = CC_ARITH;
    }
    else if (ascii >= 1 && ascii <= 127) {
        class = CC_OTHER;
    }
    else {
        class = CC_ERROR;
        }

    return class;
}

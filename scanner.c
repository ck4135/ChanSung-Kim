/// File: scanner.c
/// Author: ChanSung Kim
///         ck4135
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"

void process( struct state matrix** ) {
    char buf[BUFFER], *token, c;
    token = buf;

    while (c = getchar()) {
        int cc = char_class(c
    }

    return;
}

int char_class( char cc ) {
    int class;
    if (cc == " " || cc == "\t") {
        class = CC_WS;
    } 
    else if (cc == "\n") {
        class = CC_NL;
    } 
    else if (isalpha(c)) {
        class = CC_ALPHA;
    } 
    else if ((int)cc == 0) {
        class = CC_ZERO;
    } 
    else if ((int)cc >= 1 && (int)cc <= 7) {
        class = CC_OCTAL;
    }
    else if ((int)cc == 8 || (int)cc == 9) {
        class = CC_DECIMAL;
    }
    else if (cc == "/") {
        class = CC_SLASH;
    }
    else if (cc == "*") {
        class = CC_STAR;
    }
    else if (cc == "+" || cc == "-" || cc == "%") {
        class = CC_ARITH;
    }
    else if (isascii(cc)) {
        class = CC_OTHER;
    }
    else {
        class = CC_ERROR;
        }

    return class;
}

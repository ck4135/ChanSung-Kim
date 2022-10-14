/// File: scanner.c
/// Author: ChanSung Kim
///         ck4135
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"
#include "scanner.h"

void process( state **matrix, int nstates ) {
    char buf[BUFFER];
    char c = getchar();
    int count = 1;

    // find starting and accepting states
    int start, accept;
    for (int i=0; i<nstates; i++) {
        if (matrix[i * NUM_CLASSES]->status == STARTING) {
            start = i;
        } 
        if (matrix[i * NUM_CLASSES]->status == ACCEPTING) {
            accept = i;
        }
    }

    // read characters 1 by 1 from stdin and scan it with matrix
    printf("%d", start);
    buf[0] = c;
    int currNum = start;
    state *curr;
    while ((c = getchar()) != EOF) {
        curr = matrix[currNum * NUM_CLASSES + char_class(c)];
        printf(" %d", curr->transition);
        if (curr->transition == 9) {
            buf[count++] = '\0';
            printf(" recognized '%s'\n%d", buf, start);
            currNum = start;
            memset(buf, 0, BUFFER);
            count = 0;
            continue;
        }
        if (curr->transition == -1) {
            printf(" rejected\n%d", start);
            while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\n') {
                    break;
                }
            }
            currNum = start;
            memset(buf, 0, BUFFER);
            count = 0;
            continue;

        }
        if (curr->action == 's') {
            buf[count] = c;
        }
        currNum = curr->transition;
        count++;
    }

    //reaches EOF
    printf(" %d EOF\n", accept);

    return;
}

int char_class( char cc ) {
    int class;
    if (cc == ' ' || cc == '\t') {
        class = CC_WS;
    } 
    else if (cc == '\n') {
        class = CC_NL;
    } 
    else if (isalpha(cc) || cc == '_') {
        class = CC_ALPHA;
    } 
    else if (cc == '0') {
        class = CC_ZERO;
    } 
    else if (cc >= '1' && cc <= '7') {
        class = CC_OCTAL;
    }
    else if (cc == '8' || cc == '9') {
        class = CC_DECIMAL;
    }
    else if (cc == '/') {
        class = CC_SLASH;
    }
    else if (cc == '*') {
        class = CC_STAR;
    }
    else if (cc == '+' || cc == '-' || cc == '%') {
        class = CC_ARITH;
    }
    else {
        class = CC_OTHER;
    }

    return class;
}

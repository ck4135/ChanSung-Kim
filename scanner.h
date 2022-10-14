/// File: scanner.c
/// Author: ChanSung Kim
///         ck4135
///
#ifndef SCANNER_H_
#define SCANNER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef
    struct State{
        char action;
        int transition;
        int status;
    } state;

#define BUFFER  79  // max buffer size of a token

#define STARTING    0
#define NORMAL      1
#define ACCEPTING   2

void process( state **matrix, int nstates );

int char_class( char cc );

#endif

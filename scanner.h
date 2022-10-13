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
    } state;

#define BUFFER  79  // max buffer size of a token

static const char* SPACE  = " ";
static const char* TAB    = "\t";
static const char* NL     = "\n";
static const char* SCORE  = "_";
static const char* SLASH  = "/";
static const char* STAR   = "*";
static const char* PLUS   = "+";
static const char* DASH   = "-";
static const char* MOD    = "%";

void process( state **matrix );

int char_class( char* cc );

#endif

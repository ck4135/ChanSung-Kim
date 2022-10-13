/// File: scanner.c
/// Author: ChanSung Kim
///         ck4135
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"

#define BUFFER  79  // max buffer size of a token
 
void process( struct state matrix** );

int char_class( char cc );

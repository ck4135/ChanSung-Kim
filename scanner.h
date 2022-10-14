// File: scanner.c
// Author: ChanSung Kim
//         ck4135
//
#ifndef SCANNER_H_
#define SCANNER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for each state of the transition matrix
typedef
    struct State{
        char action;        /// save or discard the given character
        int transition;     /// next state to go to
        int status;         /// what type of state it is
    } state;

#define BUFFER  79  /// max buffer size of a token

#define STARTING    0 /// integer value of starting state
#define NORMAL      1 /// integer value of normal state
#define ACCEPTING   2 /// integer value of accepting state 

/// Process reads in characters 1 by 1 and parses it through the transition matrix, accepting or rejecting tokens based on the action 
///     and transition of the current state
///
///@param matrix = given transition matrix
///@param nstates = number of states
void process( state **matrix, int nstates );

/// Classifies a given character into one of the character classes provided in classes.h
///
///@param char cc == given character
int char_class( char cc );

#endif

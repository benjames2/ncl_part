//ECE 405: Senior Design III
//NCL Equivalence Checker
//Created by James Campbell, Dylan Visto, Julian Thrash, Ben Trnka


//NOTE: User must provide an inputs list and netlist (circuit list) for this code to properly work
//This code creates the NCL SMT statements for use by Z3 in proving equivalence between NCL circuit and Synchronous

//Include header files and standard library files

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "GateLogic.h"
#include "ReadNetlistandInput.h"
#include "NclGatesSmtFunctions.h"
#include "PrintingFunctions.h"


int main(int argc, char *argv[])
{
    char filename[] = "netlist.txt";
    char inputFilename[] = "input_list.txt";
    readInputList(inputFilename);
    readNetlist(filename);
    PrintNclGatesSmtFunctions();
    printSmt(gateStorage, MAX_SIZE);
    printArrayStruct(gateStorage, MAX_SIZE);
    return 0;
}

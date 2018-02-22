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
    //Creates a character array (string) called netlist.txt to store in filename
    char filename[] = "netlist_nclfulladder.txt";
    //Creates a string called inputs_list.txt to store in inputFilename
    char inputFilename[] = "input_list.txt";

    //Passes the filenames to the readInputList and readNetlist header files to read the netlist and
    //inputs list text files
    readInputList(inputFilename);
    readNetlist(filename);
    PrintNclGatesSmtFunctions(); //This prints off the NCL SMT functions first

    //This passes the parameters gateStorage and MAX_SIZE to printSmt and printArrayStruct functions in the PrintingFunctions header
    //and writes the SMT to a text file

    printSmt(gateStorage, MAX_SIZE);
    printArrayStruct(gateStorage, MAX_SIZE);
    //GateStorage holds the information on each gate from the netlist and MAX_SIZE defines the maximum size of the global array
    return 0;
}

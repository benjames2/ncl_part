#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "GateLogic.h"
#include "ReadNetlistandInput.h"
#include "NclGatesFunctons.h"
#include "PrintingFunctions.h"


int main(int argc, char *argv[])
{
    char filename[] = "netlist.txt";
    char inputFilename[] = "input_list.txt";
    readInputList(inputFilename);
    readNetlist(filename);
    printSmt(gateStorage, MAX_SIZE);
    printArrayStruct(gateStorage, MAX_SIZE);

    return 0;
}

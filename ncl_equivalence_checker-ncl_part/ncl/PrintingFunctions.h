//This header file handles the writing of the SMT statements to an output SMT text file, which will be used in proving the equivalence of NCL and Synchronous Circuits

#ifndef PRINTING_FUNCTIONS_H
#define PRINTING_FUNCTIONS_H
#include <stdint.h>


const char *printSynchronousGateType(int a){
    char str1[20];
    switch(a) {

    case 0  :
      strcpy(str1, "DECLARATION");
      break;

    case 1  :
      strcpy(str1, "AND");
      break;

    case 2  :
        strcpy(str1, "OR");
      break;

    case 3  :
        strcpy(str1, "NOT");
      break;

    case 4  :
        strcpy(str1, "NAND");
      break;

    case 5  :
        strcpy(str1, "NOR");
      break;

    case 6  :
        strcpy(str1, "XOR");
      break;

    case 7  :
        strcpy(str1, "XNOR");
      break;

    case 8  :
        strcpy(str1, "DFF");
      break;
    }
    return str1;

}
const char *printNclGateType(int a){//Depending on the number value of the gatetype integer it will select one of the cases to identify the gate type
    char str1[20];//This array will hold the string of text that is used in writing the gate type to the text file
    switch(a) {

    case 0  :
      strcpy(str1, "DECLARATION");
      break;

case 1  :
      strcpy(str1, "TH12 ");
      break;

    case 2  :
        strcpy(str1, "TH22 ");
      break;

    case 3  :
        strcpy(str1, "TH13 ");
      break;

    case 4  :
        strcpy(str1, "TH23 ");
      break;

    case 5  :
        strcpy(str1, "TH33 ");
      break;

    case 6  :
        strcpy(str1, "TH23w2 ");
      break;

    case 7  :
        strcpy(str1, "TH33w2 ");
      break;

    case 8  :
        strcpy(str1, "TH14 ");
      break;

    case 9  :
        strcpy(str1, "TH24 ");
      break;

    case 10  :
        strcpy(str1, "TH34 ");
      break;

    case 11  :
        strcpy(str1, "TH44 ");
      break;

    case 12  :
        strcpy(str1, "TH24w2 ");
      break;

    case 13  :
        strcpy(str1, "TH34w2 ");
      break;

    case 14  :
        strcpy(str1, "TH44w2 ");
      break;

    case 15  :
        strcpy(str1, "TH34w3 ");
      break;

    case 16  :
        strcpy(str1, "TH44w3 ");
      break;

    case 17  :
        strcpy(str1, "TH24w22 ");
      break;

    case 18  :
        strcpy(str1, "TH34w22 ");
      break;

    case 19  :
        strcpy(str1, "TH44w22 ");
      break;

    case 20  :
        strcpy(str1, "TH54w22 ");
      break;

    case 21  :
        strcpy(str1, "TH34w32 ");
      break;

    case 22  :
        strcpy(str1, "TH54w32 ");
      break;

    case 23  :
        strcpy(str1, "TH44w322");
      break;

    case 24  :
        strcpy(str1, "TH54w322 ");
      break;

    case 25  :
        strcpy(str1, "THxor0 ");
      break;

    case 26  :
        strcpy(str1, "THand0 ");
      break;

    case 27  :
        strcpy(str1, "TH24comp ");
      break;
    }
    return str1;

}

const char *printSynchronousFunctionSymbol(int a){
    char str1[20];
    switch(a) {

    case 1  :
      strcpy(str1, "(bvand ");
      break;

    case 2  :
        strcpy(str1, "(bvor ");
      break;

    case 3  :
        strcpy(str1, "(bvnot ");
      break;

    case 4  :
        strcpy(str1, "(bvnand ");
      break;

    case 5  :
        strcpy(str1, "(bvnor ");
      break;

    case 6  :
        strcpy(str1, "(bvxor ");
      break;

    case 7  :
        strcpy(str1, "(bvxnor ");
      break;

    }
    return str1;

}

const char *printNclFunctionSymbol(int a){ //Storing a string based on a case identified.  This string is used to write the operation used in the SMT
    char str1[20];
    switch(a) {

    case 1  :
      strcpy(str1, "(TH12 ");
      break;

    case 2  :
        strcpy(str1, "(TH22 ");
      break;

    case 3  :
        strcpy(str1, "(TH13 ");
      break;

    case 4  :
        strcpy(str1, "(TH23 ");
      break;

    case 5  :
        strcpy(str1, "(TH33 ");
      break;

    case 6  :
        strcpy(str1, "(TH23w2 ");
      break;

    case 7  :
        strcpy(str1, "(TH33w2 ");
      break;

    case 8  :
        strcpy(str1, "(TH14 ");
      break;

    case 9  :
        strcpy(str1, "(TH24 ");
      break;

    case 10  :
        strcpy(str1, "(TH34 ");
      break;

    case 11  :
        strcpy(str1, "(TH44 ");
      break;

    case 12  :
        strcpy(str1, "(TH24w2 ");
      break;

    case 13  :
        strcpy(str1, "(TH34w2 ");
      break;

    case 14  :
        strcpy(str1, "(TH44w2 ");
      break;

    case 15  :
        strcpy(str1, "(TH34w3 ");
      break;

    case 16  :
        strcpy(str1, "(TH44w3 ");
      break;

    case 17  :
        strcpy(str1, "(TH24w22 ");
      break;

    case 18  :
        strcpy(str1, "(TH34w22 ");
      break;

    case 19  :
        strcpy(str1, "(TH44w22 ");
      break;

    case 20  :
        strcpy(str1, "(TH54w22 ");
      break;

    case 21  :
        strcpy(str1, "(TH34w32 ");
      break;

    case 22  :
        strcpy(str1, "(TH54w32 ");
      break;

    case 23  :
        strcpy(str1, "(TH44w322");
      break;

    case 24  :
        strcpy(str1, "(TH54w322 ");
      break;

    case 25  :
        strcpy(str1, "(THxor0 ");
      break;

    case 26  :
        strcpy(str1, "(THand0 ");
      break;

    case 27  :
        strcpy(str1, "(TH24comp ");
      break;
    }
    return str1;

}

//'a' is a pointer of type GATE_IO, looks at what is stored in the global array, 'size' is the size of the total array
void printNclArrayStruct(GATE_IO *a, int size){//Prints off information on each line of the netlist to the console

    int i;
    int b;
    char gateName[20];
    for(i = 0; i < size; i++){//Executes this loop for the size of the global array

        if(a[i].bit_size != 0){                              //Printing format for inputs
            //calling the function printGateType with current structure
            strcpy(gateName, printNclGateType(a[i].gate));//Copies over the string from printGateType function and stores it in gateName
            //Printing format for all entries in the gate storage
            printf("Gate Type: %s | Bit Size: %d", gateName, a[i].bit_size);//This prints off the gatetype and the bitvector size from the global array of structures

            if(a[i].gate == 0){
                printf(" | Wire: %d |", i);//Prints off the number wire
            }

            if(a[i].gate != 0){                             //Printing format for each gate
                printf(" Output: %d | Number of Inputs: %d |", a[i].wire_out, a[i].num_inputs);//prints off the output wire and the number of inputs for each given structure
            }

            if(a[i].gate != 0){//This prints off the input wires of each gate/line of netlist
                printf(" Inputs:");

                for(b = 0; b < a[i].num_inputs; b++){//This loops for the total number of inputs of each gate
                    printf(" %d,", a[i].wire_in[b]);//Prints off the input wire

                }
            }
            printf("\n\n");
        }
    }

}

void printSynchronousArrayStruct(GATE_IO *a, int size){//Prints off information on each line of the netlist to the console

    int i;
    int b;
    char gateName[20];
    for(i = 0; i < size; i++){//Executes this loop for the size of the global array

        if(a[i].bit_size != 0){                              //Printing format for inputs
            //calling the function printGateType with current structure
            strcpy(gateName, printSynchronousGateType(a[i].gate));//Copies over the string from printGateType function and stores it in gateName
            //Printing format for all entries in the gate storage
            printf("Gate Type: %s | Bit Size: %d", gateName, a[i].bit_size);//This prints off the gatetype and the bitvector size from the global array of structures

            if(a[i].gate == 0){
                printf(" | Wire: %d |", i);//Prints off the number wire
            }

            if(a[i].gate != 0){                             //Printing format for each gate
                printf(" Output: %d | Number of Inputs: %d |", a[i].wire_out, a[i].num_inputs);//prints off the output wire and the number of inputs for each given structure
            }

            if(a[i].gate != 0){//This prints off the input wires of each gate/line of netlist
                printf(" Inputs:");

                for(b = 0; b < a[i].num_inputs; b++){//This loops for the total number of inputs of each gate
                    printf(" %d,", a[i].wire_in[b]);//Prints off the input wire

                }
            }
            printf("\n\n");
        }
    }

}

void printNclInputDeclaration(GATE_IO *a, int size)
{    int i;//Counter variables
    int numberOfGates = 0;  //This variable is used to count the total number of gates

    //Declaring an array of strings for declaring the variables
    char def[] = "(define-fun ncl_wire"; //This declares a string that will be held for each input declaration to the SMT file
    char bitvec[] = "(_ BitVec";//This is used for the bit vectors
    char closing[] = "))";//This closes SMT statements

    char getfuncSymbol[12];//Array for holding the function symbols for SMT statement

    FILE *fp;//Creates a file pointer used for writing the SMT statements for the given netlist and inputs list
    fp = fopen("SMT.txt", "a");//This opens the output text file SMT.txt.  It appends to the file with "a"

    if (fp == NULL)//File open exception
    {
        printf("Cannot open file \n");
        exit;
    }

    for(i = 0; i < size; i++){//This loops through the global structure array and counts the total number of gates
        if((a[i].bit_size != 0) && (a[i].gate != 0)){
            numberOfGates++;
        }

    }

    for(i = 0; i <= MAX_SIZE; i++){                         //Goes through all the gate storage and look for inputs to be declared
        if(a[i].bit_size != 0){                       //looks for gate storage that actually holds something
            if(a[i].gate == 0){                      //looks for the inputs
                fprintf(fp, "%s" "%i" "%s" "%i" "%s", def, i, bitvec, a[i].bit_size, closing);//Prints off the input declaration statements to the SMT text file
                fprintf(fp, "\n");//does a new line for each write to the SMT text file
            }
        }
    }

   // fprintf(fp,"\n");//Separates the input declarations from the netlist SMT functions
    fclose(fp);//Close the file

}



void printNclSmt(GATE_IO *a, int size)//This function writes the SMT statements to a text file
{
    int i, j;//Counter variables
    int exit = 1;
    int numberOfGates = 0;  //This variable is used to count the total number of gates
    int maxOutputIndex = 0; //This variable is for the output index of the netlist

    //Declaring an array of strings for declaring the variables
    char cs[] = "cs_";//This is used for defining the current state (cs) wires of the NCL circuit
    char closing1[] = "))";//This closes SMT statements
    char closing2[] = "))))";//This closes SMT statements
    char wire[] = "(let ((ncl_wire";//This is used for the let statements
    char wire2[] = "ncl_wire";//Used for wires
    char getfuncSymbol[12];//Array for holding the function symbols for SMT statement

    FILE *fp;//Creates a file pointer used for writing the SMT statements for the given netlist and inputs list
    fp = fopen("SMT.txt", "a");//This opens the output text file SMT.txt.  It appends to the file with "a"

    if (fp == NULL)//File open exception
    {
        printf("Cannot open file \n");
        exit;
    }

    //fprintf(fp, "\n");//Prints new lines to separate the previous functions for the SMT theorems

    for(i = 0; i < size; i++){//This loops through the global structure array and counts the total number of gates
        if((a[i].bit_size != 0) && (a[i].gate != 0)){
            numberOfGates++;
            maxOutputIndex = i;//Holds the current count of the output index
        }

    }
    for (i = 0; i <= MAX_SIZE; i++){//Goes through the entire global array and looks for info on each element/gate
        if(a[i].bit_size != 0){
            if(a[i].gate != 0){                                                    //format for every other gate
                fprintf(fp, "%s" "%i ", wire, i);//prints off first part of nested let statement
                strcpy(getfuncSymbol, printNclFunctionSymbol(a[i].gate));//copies the string from the given gate in the global array and stores it in getfuncSymbol
                fprintf(fp, "%s", getfuncSymbol);//Prints off the gate function symbol to the SMT file
                fprintf(fp,"%s" "%i ", cs, a[i].wire_out);//prints current state wire output

                for(j = 0; j < a[i].num_inputs; j++){//This prints off the inputs for the number of inputs to the SMT file on the same line as the let statement
                    if(j == (a[i].num_inputs - 1)){                                //choose proper format if last input or not
                            fprintf(fp, "%s" "%i", wire2, a[i].wire_in[j]);
                        }
                        else{
                            fprintf(fp, "%s" "%i ", wire2, a[i].wire_in[j]);
                        }
                    }
                    numberOfGates--;    //keeps track of the number of gates so it knows when to close

                    if(numberOfGates == 0){//When the count of the number of gates is 0 print off the closing parentheses
                        fprintf(fp, "%s" "\n", closing2);
                        exit = 0;
                    }
                    else{//If it isn't done then close the current function and start a new line
                        fprintf(fp, "%s" "\n", closing1);
                    }
            }
    }
}
    fclose(fp);//Close the file
}



void printSyncInputDeclaration(GATE_IO *a, int size)
{    int i;//Counter variables
    int numberOfGates = 0;  //This variable is used to count the total number of gates

    //Declaring an array of strings for declaring the variables
    char def[] = "(define-fun wire"; //This declares a string that will be held for each input declaration to the SMT file
    char bitvec[] = "(_ BitVec";//This is used for the bit vectors
    char closing[] = "))";//This closes SMT statements

    char getfuncSymbol[12];//Array for holding the function symbols for SMT statement

    FILE *fp;//Creates a file pointer used for writing the SMT statements for the given netlist and inputs list
    fp = fopen("SMT.txt", "a");//This opens the output text file SMT.txt.  It appends to the file with "a"

    if (fp == NULL)//File open exception
    {
        printf("Cannot open file \n");
        exit;
    }

    for(i = 0; i < size; i++){//This loops through the global structure array and counts the total number of gates
        if((a[i].bit_size != 0) && (a[i].gate != 0)){
            numberOfGates++;
        }

    }

    for(i = 0; i <= MAX_SIZE; i++){                         //Goes through all the gate storage and look for inputs to be declared
        if(a[i].bit_size != 0){                       //looks for gate storage that actually holds something
            if(a[i].gate == 0){                      //looks for the inputs
                fprintf(fp, "%s" "%i" "%s" "%i" "%s", def, i, bitvec, a[i].bit_size, closing);//Prints off the input declaration statements to the SMT text file
                fprintf(fp, "\n");//does a new line for each write to the SMT text file
            }
        }
    }

    fprintf(fp,"\n");//Separates the input declarations from the netlist SMT functions
    fclose(fp);//Close the file

}




void printSynchronousSmt(GATE_IO *a, int size)//This function writes the SMT statements to a text file
{
    int i, j;//Counter variables
    int exit = 1;
    int numberOfGates = 0;  //This variable is used to count the total number of gates
    int maxOutputIndex = 0; //This variable is for the output index of the netlist

    //Declaring an array of strings for declaring the variables
    char wire[] = "(let ((wire";//This is used for the let statements
    char wire2[] = "wire";//Used for wires
    char closing1[] = "))";//This closes SMT statements
    char closing2[] = "))))";//This closes SMT statements
    char getfuncSymbol[12];//Array for holding the function symbols for SMT statement

    FILE *fp;//Creates a file pointer used for writing the SMT statements for the given netlist and inputs list
    fp = fopen("SMT.txt", "a");//This opens the output text file SMT.txt.  It appends to the file with "a"

    if (fp == NULL)//File open exception
    {
        printf("Cannot open file \n");
        exit;
    }

    fprintf(fp, "\n");//Prints new lines to separate the previous functions for the SMT theorems

    for(i = 0; i < size; i++){//This loops through the global structure array and counts the total number of gates
        if((a[i].bit_size != 0) && (a[i].gate != 0)){
            numberOfGates++;
        }

    }

    for (i = 0; i <= size; i++){//Goes through the entire global array and looks for info on each element/gate
        if(a[i].bit_size != 0){
            if(a[i].gate != 0){                                                    //format for every other gate
                fprintf(fp, "%s" "%i ", wire, i);//prints off first part of nested let statement
                strcpy(getfuncSymbol, printSynchronousFunctionSymbol(a[i].gate));//copies the string from the given gate in the global array and stores it in getfuncSymbol
                fprintf(fp, "%s", getfuncSymbol);//Prints off the gate function symbol to the SMT file

                for(j = 0; j < a[i].num_inputs; j++){//This prints off the inputs for the number of inputs to the SMT file on the same line as the let statement
                    if(j == (a[i].num_inputs - 1)){                                //choose proper format if last input or not
                            fprintf(fp, "%s" "%i", wire2, a[i].wire_in[j]);
                        }
                        else{
                            fprintf(fp, "%s" "%i ", wire2, a[i].wire_in[j]);
                        }
                    }
                    numberOfGates--;    //keeps track of the number of gates so it knows when to close

                    if(numberOfGates == 0){//When the count of the number of gates is 0 print off the closing parentheses
                        fprintf(fp, "%s" "\n", closing2);
                        exit = 0;
                    }
                    else{//If it isn't done then close the current function and start a new line
                        fprintf(fp, "%s" "\n", closing1);
                    }
            }
    }
}
    fclose(fp);//Close the file
}


void generateProperties (GATE_IO *a, int size)

{
    int i;
    char implies[] = "(implies(and ";
    char wire[] = "wire";
    char ncl_wire[] = "ncl_wire";
    char opening[] = "(=";
    char closing[] = "))";
    char closing2[] = ")";
    char space[] = "             ";
    char not[] = "(not ncl_wire";


    FILE *fp;//Creates a file pointer used for writing the SMT statements for the given netlist and inputs list
    fp = fopen("SMT.txt", "a");//This opens the output text file SMT.txt.  It appends to the file with "a"

    if (fp == NULL)//File open exception
    {
        printf("Cannot open file \n");
        exit;
    }

    fprintf(fp, "\n%s", implies);

    for (i = 0; i <= size; i++){
        if(a[i].bit_size != 0){
            fprintf(fp, "%s " "%s" "%d " "%s" "%d" "%s\n", opening, ncl_wire, a[i].wire_in[1], not, a[i].wire_in[0], closing);
            fprintf(fp, "%s", space);
            fprintf(fp, "%s " "%s" "%d " "%s" "%d" "%s\n", opening, ncl_wire, a[i].wire_in[1], wire, i, closing2);
            fprintf(fp, "%s", space);
        }
    }

    fclose(fp);//Close the file
}
#endif

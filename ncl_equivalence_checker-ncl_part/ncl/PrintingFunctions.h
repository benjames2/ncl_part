#ifndef PRINTING_FUNCTIONS_H
#define PRINTING_FUNCTIONS_H
#include <stdint.h>

const char *printGateType(int a){
    char str1[20];
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

const char *printFunctionSymbol(int a){
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
///*
void printArrayStruct(GATE_IO *a, int size){

    int i;
    int b;
    char gateName[20];
    for(i = 0; i < size; i++){

        if(a[i].bit_size != 0){                              //Printing format for inputs
            strcpy(gateName, printGateType(a[i].gate));
            printf("Gate Type: %s | Bit Size: %d", gateName, a[i].bit_size); //Printing format for all entries in the gate storage

            if(a[i].gate == 0){
                printf(" | Wire: %d |", i);
            }

            if(a[i].gate != 0){                             //Printing format for each gate
                printf(" Output: %d | Number of Inputs: %d |", a[i].wire_out, a[i].num_inputs);
            }

            if(a[i].gate != 0){
                printf(" Inputs:");

                for(b = 0; b < a[i].num_inputs; b++){
                    printf(" %d,", a[i].wire_in[b]);

                }
            }
            printf("\n\n");
        }
    }

}

void printSmt(GATE_IO *a, int size)
{
    int i, j;
    int exit = 1;
    int numberOfGates = 0;
    int maxOutputIndex = 0;
    char def[] = "(define-fun wire";                //Declaring an array of strings for declaring the variables
    char bitvec[] = "(_ BitVec";
    char cs[] = "cs_";
    char closing[] = "))";
    char wire[] = "(let ((wire";
    char wire2[] = "wire";
    char getfuncSymbol[12];

    FILE *fp;
    fp = fopen("SMT.txt", "a");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        exit;
    }

    fprintf(fp, "\n\n\n");

    for(i = 0; i < size; i++){
        if((a[i].bit_size != 0) && (a[i].gate != 0)){
            numberOfGates++;
            maxOutputIndex = i;
        }

    }
    printf("This is maxOutputIndex: %i\n\n", maxOutputIndex);
    for(i = 0; i <= MAX_SIZE; i++){                         //Goes through all the gate storage and look for inputs to be declared
        if(a[i].bit_size != 0){                       //looks for gate storage that actually holds something
            if(a[i].gate == 0){                      //looks for the inputs
                fprintf(fp, "%s" "%i" "%s" "%i" "%s", def, i, bitvec, a[i].bit_size, closing);
                fprintf(fp, "\n");
            }
        }
    }

    fprintf(fp,"\n");
    for (i = 0; i <= MAX_SIZE; i++){
        if(a[i].bit_size != 0){
            if(a[i].gate != 0){                                                    //format for every other gate
                fprintf(fp, "%s" "%i ", wire, i);
                strcpy(getfuncSymbol, printFunctionSymbol(a[i].gate));
                fprintf(fp, "%s", getfuncSymbol);
                fprintf(fp,"%s" "%i ", cs, a[i].wire_out);

                for(j = 0; j < a[i].num_inputs; j++){
                    if(j == (a[i].num_inputs - 1)){                                //choose proper format if last input or not
                            fprintf(fp, "%s" "%i", wire2, a[i].wire_in[j]);
                        }
                        else{
                            fprintf(fp, "%s" "%i ", wire2, a[i].wire_in[j]);
                        }
                    }
                    numberOfGates--;    //keeps track of the number of gates so it knows when to close

                    if(numberOfGates == 0){
                        fprintf(fp, "))))\n\n\n");
                        exit = 0;
                    }
                    else{
                        fprintf(fp, "))\n");
                    }
            }
    }
}
    fclose(fp);
}

#endif

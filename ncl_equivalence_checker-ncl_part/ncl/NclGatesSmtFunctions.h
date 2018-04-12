//This header file is used to print off the possible NCL SMT functions we can use in our equivalence theorem to our output SMT text file


#ifndef NCL_GATES_SMT_FUNCTIONS_H
#define NCL_GATES_SMT_FUNCTIONS_H
#include <stdint.h>

void PrintNclGatesSmtFunctions()
{
    FILE *fptr, *fp; //Creates two file pointers.  fptr is used for reading the SMT NCL functions file and fp is used to write the text to a file
    char c;

    // Opens NCL SMT Functions file and reads in the text
    fptr = fopen("SMT_functions_NCL_Gates.txt", "r");

    if (fptr == NULL)//File open exception
    {
        printf("Cannot open file \n");
        exit(0);
    }

    //Opens the SMT output text file to write the NCL SMT functions
    fp = fopen("SMT.txt", "w");
    if (fp == NULL) //File open exception
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr); //Gets the next character from a stream of characters from the pointer fptr.
                    //The current character is stored in the variable c

    //This loop does the reading of the SMT Functions text file and writes to the output SMT text file.
    //This loop executes until the file is finished being read (EOF).
    while (c != EOF)
    {
        //print to file
        fprintf (fp, "%c", c);//Writes the current value of c to file
        c = fgetc(fptr);//Gets the next character value of the SMT Functions file
    }

    fprintf (fp, "\n");
    fclose(fptr);//Close file pointers
    fclose(fp);
    return 0;
}
#endif

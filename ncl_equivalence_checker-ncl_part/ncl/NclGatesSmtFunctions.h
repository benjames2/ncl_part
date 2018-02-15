#ifndef NCL_GATES_SMT_FUNCTIONS_H
#define NCL_GATES_SMT_FUNCTIONS_H
#include <stdint.h>

void PrintNclGatesSmtFunctions()
{
    FILE *fptr, *fp;
    char c;

    // Open file to read from
    fptr = fopen("SMT_functions_NCL_Gates.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    //Open file to write to
    fp = fopen("SMT.txt", "w");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        //print to file
        fprintf (fp, "%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    fclose(fp);
    return 0;
}
#endif

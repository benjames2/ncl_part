//This Header file reads in the netlist and inputs list for a given circuit design and sorts the information

//Inputs list is used for declaring the inputs of the circuits for the equivalence theorem
//Netlist is used for identifying the gates and other information needed, in order

//Inputs List Format: GATE_TYPE BIT_VECTOR_SIZE INPUT(S)
//Netlist Format:
#ifndef READ_NETLIST_AND_INPUT_H
#define READ_NETLIST_AND_INPUT_H
#include <stdint.h>
#define MAX_SIZE 1000 //Sets global variable MAX_SIZE to 1000 for gateStorage

GATE_IO gateStorage[MAX_SIZE]; //Array of type GATE_IO used to hold info about each gate (structures)

//This function reads in the input list text file and organizes the information for each input
void readInputList(char *filename){

    int i = 0;
    int numOfInputs = 0;
    FILE *fp;  //fp is a pointer used for reading the inputs list file
    char *token; //Character pointer that points at each element of the text file
    uint16_t *input_number = (uint16_t *) malloc(sizeof(uint16_t));  //This allocates 16 bits of memory for reading the inputs


    int gateType;   //Variable for gate identifier
    int bitSize;  //Variable used for bitvector size
    int input_num; //Variable used for number of inputs

    int z = 0;

    fp = fopen(filename, "r"); //Opens the inputs list

    if (fp == NULL) //File open error exception
        exit(EXIT_FAILURE);

    char line[256];//Array that contains the characters of the inputs list.
                   //Each line will get 256 possible characters it can store.


    //While loop does the reading of the inputs list, line by line, for the size of the array line
    while (fgets(line, sizeof(line), fp)) {  //while(fgets(array, sizeof(array), filepointer)

        z = 0;  //Counter variable for token variable to select an element of each line of the text file
        printf("%s\n", line);  //prints off each line of the inputs list text file first
        token = strtok(line, " "); //Creates a variable token that breaks apart elements of the text file by a space


        while (token) {  //While loop done when token is not equal to null

              if (z == 0){
                gateType = atoi(token);  //converts the character from the text file to an integer and assigns it to gateType
                printf("GATETYPE is: %d\n", gateType);  //Prints gateType number
              }
              else if (z == 1){
                bitSize = atoi(token);  //converts the character from the text file to an integer and assigns it to bitSize
                printf("BITSIZE is: %d\n", bitSize);  //Prints bitSize number
              }
              else if ( z > 1){ //This reads the inputs from the inputs list
                  input_num = atoi(token); //converts character from text file to an integer and assigns it to be one of the inputs
                  input_number[i] = input_num;  //Stores the input into an array input_number
                  i++;  //increments array to place input in the next location
                  printf("INPUT WIRE: %i\n", input_num);  //Prints off each input to the console
              }

            z++; //increments the element the character pointer token will read
            token = strtok(NULL, " "); //Delimits the lines by a space
        }
        numOfInputs = i;
        for(i = 0; i < numOfInputs; i++){
            gateStorage[input_number[i]] = InitializeGateLogic(gateType, 1, bitSize, -1, -1, 0);
        }
        i = 0;

        printf("\n");

    }
    fclose(fp);

    if (line)
        free(line);

}

void readNetlist(char *filename){

    FILE * fp;
    char * token;

    int input;
    int numOfInputs;
    int output;
    int gateType;
    int bitSize;
    int z = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        z = 0;
        numOfInputs = 0;
        uint16_t *getwire_in = (uint16_t *) malloc(sizeof(uint16_t));
        printf("%s\n", line);
        token = strtok(line, " ");

        while (token) {

              if (z == 0){
                gateType = atoi(token);
                printf("GATETYPE is: %d\n", gateType);
              }
              else if (z == 1){
                bitSize = atoi(token);
                printf("BITSIZE is: %d\n", bitSize);
              }
              else if (z == 2){
                output = atoi(token);
                printf("OUTPUT is: %d\n", output);
              }
              else if (z > 2){
                input = atoi(token);
                getwire_in[numOfInputs] = input;
                numOfInputs++;
                printf("INPUT%d is: %d\n", numOfInputs, input);
              }

            z++;
            token = strtok(NULL, " ");
        }
        printf("NUMBER OF INPUTS: %i\n", numOfInputs);
        gateStorage[output] = InitializeGateLogic(gateType, numOfInputs, bitSize, getwire_in, output, 0);
        printf("\n");

    }

    fclose(fp);

    if (line)
        free(line);
}
#endif

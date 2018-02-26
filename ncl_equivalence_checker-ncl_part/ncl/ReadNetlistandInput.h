//This Header file reads in the netlist and inputs list for a given circuit design and sorts the information

//Inputs list is used for declaring the inputs of the circuits for the equivalence theorem
//Netlist is used for identifying the gates and other information needed, in order

//Inputs List Format: GATE_TYPE BIT_VECTOR_SIZE INPUT(S)
//*NOTE: The gate type for the inputs list will be 0, which is a declaration

//Netlist Format: GATE_TYPE BIT_VECTOR_SIZE OUTPUT INPUT(S)

#ifndef READ_NETLIST_AND_INPUT_H
#define READ_NETLIST_AND_INPUT_H
#include <stdint.h>


GATE_IO gateStorage[MAX_SIZE]; //Array of type GATE_IO used to hold info about each gate (structures)

//This function reads in the input list text file and organizes the information for each input
void readInputList(char *filename){ //character pointer(array)

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
        token = strtok(line, " "); //Sets the character variable token to delimit elements of the text file by a space


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
            token = strtok(NULL, " "); //Delimits the lines by a space (NULL is used for the first argument)
        }
        numOfInputs = i;
        for(i = 0; i < numOfInputs; i++){//This is for input declarations
            gateStorage[input_number[i]] = InitializeGateLogic(gateType, 1, bitSize, -1, -1, 0);//Sets each input wire to be a declaration and bitsize
        }
        i = 0;

        printf("\n");

    }
    fclose(fp);//Closes the file

    if (line)
        free(line);

}

//This function reads in the netlist text file and organizes the information for each input
void readNetlist(char *filename){

    FILE * fp; //Creates a file pointer which will be used in reading the text from the netlist
    char * token;  //Creates a character pointer token, which will be used to identify elements of the text file

    int input; //Holds information on input of gate
    int numOfInputs;  //Counts the number of inputs
    int output; //Identifies the output of the gate
    int gateType; //Identifies the gate type of a given gate
    int bitSize; //Identifies bit vector size
    int z = 0;//Counter variable for token variable to select an element of each line of the text file

    fp = fopen(filename, "r");//Opens the text file containing the netlist and sets it to File pointer fp

    if (fp == NULL)//File open exception handler
        exit(EXIT_FAILURE);

    char line[256];  //Array that contains the characters of the inputs list.
                   //Each line will get 256 possible characters it can store.

     //While loop does the reading of the inputs list, line by line, for the size of the array line
    while (fgets(line, sizeof(line), fp)) {
        z = 0;
        numOfInputs = 0;
        uint16_t *getwire_in = (uint16_t *) malloc(sizeof(uint16_t));  //Allocates memory (16 bits) to store input wires
        printf("%s\n", line);//Prints off a string that contains the text from each line of the netlist
        token = strtok(line, " ");//Sets the character variable token to delimit elements of the text file by a space

        while (token) {//While token is equal to a value other than NULL

              if (z == 0){//Identifies the gate type of each line/gate, which is given by the first element
                gateType = atoi(token);//Converts the character from the text file to an integer value
                printf("GATETYPE is: %d\n", gateType);//Prints to the console the gatetype ID number
              }
              else if (z == 1){//Identifies the bitvector size of each line/gate.  This is given by the second element
                bitSize = atoi(token);
                printf("BITSIZE is: %d\n", bitSize);//Prints the bitvector size number to the console
              }
              else if (z == 2){//Identifies the output of each line/gate.  This is given by the third element
                output = atoi(token);
                printf("OUTPUT is: %d\n", output);//Prints the output wire number to the console
              }
              else if (z > 2){//Identifies the input(s) of each gate/line
                input = atoi(token);
                getwire_in[numOfInputs] = input;//Stores the input in an array for wires in
                numOfInputs++;//Counts the number of inputs
                printf("INPUT%d is: %d\n", numOfInputs, input);//Prints off the current number wire and its count
              }

            z++; //increments the element the character pointer token will read
            token = strtok(NULL, " ");//Sets the character variable token to delimit elements of the text file by a space
        }
        printf("NUMBER OF INPUTS: %i\n", numOfInputs);//Prints off the total number of inputs in each line of the file
        gateStorage[output] = InitializeGateLogic(gateType, numOfInputs, bitSize, getwire_in, output, 0);//Stores each value into a structure in our global structure array
        printf("\n");

    }

    fclose(fp);//Close the file

    if (line)//Done after each line is read into the program
        free(line);//Frees up the array that stores the characters of each line so that it can then store the next available line.
}
#endif

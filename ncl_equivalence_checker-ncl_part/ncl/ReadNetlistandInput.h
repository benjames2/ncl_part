#ifndef READ_NETLIST_AND_INPUT_H
#define READ_NETLIST_AND_INPUT_H
#include <stdint.h>
#define MAX_SIZE 1000

GATE_IO gateStorage[MAX_SIZE];
void readInputList(char *filename){

    int i = 0;
    int numOfInputs = 0;
    FILE *fp;
    char *token;
    uint16_t *input_number = (uint16_t *) malloc(sizeof(uint16_t));


    int gateType;
    int bitSize;
    int input_num;

    int z = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    char line[256];

    while (fgets(line, sizeof(line), fp)) {

        z = 0;
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
              else if ( z > 1){
                  input_num = atoi(token);
                  input_number[i] = input_num;
                  i++;
                  printf("INPUT WIRE: %i\n", input_num);
              }

            z++;
            token = strtok(NULL, " ");
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

//This header file will define the structures that will represent each gate from our netlist file
//Each gate has a type, bitsize, number of inputs, an indicator what is the input, and the output wires

#ifndef GATE_LOGIC_H
#define GATE_LOGIC_H
#include <stdint.h>
#define MAX_SIZE 1000 //Sets global variable MAX_SIZE to 1000 for gateStorage


//Declares an enumerated type GATE_LOGIC.
//Assigns an integer value to each gate type starting from DECLARE = 0 to DFF = 8
typedef enum
{
  DECLARE,
  AND_GATE,
  OR_GATE,
  NOT_GATE,
  NAND_GATE,
  NOR_GATE,
  XOR_GATE,
  XNOR_GATE,
  DFF_GATE
} GATE_LOGIC;

//Creates a Structure of type GATE_IO
//This defines the type of information that will be created for every
//gate that is read from the netlist
typedef struct
{
  GATE_LOGIC gate;  //gate is a variable of type GATE_LOGIC
  uint16_t bit_size; //Creates an unsigned 16-bit integer bitsize: Used for bitvector
  uint16_t num_inputs; //Creates num_inputs: used for number of inputs in gate
  uint16_t *wire_in;  //Creates an unsigned 16-B integer pointer.  Used to hold the address of the input wire
  uint16_t wire_out;  //wire_out: used for output wires in gate
  uint16_t flag;  //Creates a flag to identify if a gate has been declared.  Used for keeping the order of the circuit
} GATE_IO;

//This function stores the information for each structure (represents the gates)
//Creates a function InitializeGateLogic of type GATE_IO which uses variables from the structure as arguments.
//Each instance of a gate will be stored as a structure of this type.
GATE_IO InitializeGateLogic(GATE_LOGIC g, uint16_t num_in, uint16_t bitsize, uint16_t *wire_in, uint16_t wire_out, uint16_t flag)
{
  GATE_IO temp;
  temp.gate = g;
  temp.num_inputs = num_in;
  temp.bit_size = bitsize;
  temp.wire_in = wire_in;
  temp.wire_out = wire_out;
  temp.flag = flag;
  return temp;
}

void InitializeGateStorage(GATE_IO *gateStorage, int size)
{
    int i = 0;
    for (i = 0; i < size; i++){
        gateStorage[i] = InitializeGateLogic(0,0,0,0,0,0);
    }
}

#endif

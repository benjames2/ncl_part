#ifndef GATE_LOGIC_H
#define GATE_LOGIC_H
#include <stdint.h>

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

typedef struct
{
  GATE_LOGIC gate;
  uint16_t bit_size;
  uint16_t num_inputs;
  uint16_t *wire_in;
  uint16_t wire_out;
  uint16_t flag;
} GATE_IO;

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

#endif

// class CPU
// The 6502 CPU architecture and its operations are defined in this class
//
//
#include "cpu.h"

CPU::CPU() {
  instructionTable.fill(
      [this]() { this->NOP(); }); // for unknown opcodes, default to NOP
}

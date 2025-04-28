#ifndef CPU_H_
#define CPU_H_

#include <array>
#include <cstdint>
#include <functional>

class CPU {
private:
  uint8_t SP;
  uint16_t PC;
  void executeInstruction(uint8_t opcode);

  // all instructions listed in row order from
  // https://llx.com/Neil/a2/opcodes.html
  // and https://nesdev.org/wiki/CPU_unofficial_opcodes
  // we use ALL opcodes from the base 6502
  //
  // #i = immediate addr
  // a = absolute 16 bit addr
  // a,x abs x
  // a,y abs y
  // d = 8 bit zero page addr
  // d,x = zero page X
  // (d,x) = Indirect_X
  // (d),y = Indirect_Y

  // instruction functions
  // 0x00 to 0x1F
  void BRK();
  void ORA_IndirectX();
  // 0x02 undefined
  void SLO_IndirectX();

  // Instruction table
  std::array<std::function<void()>, 256> instructionTable;

public:
  // Constructor
  CPU();
};

#endif

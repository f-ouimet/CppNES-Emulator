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
  void NOP_ZP();
  void ORA_ZP();
  void ASL_ZP();
  void SLO_ZP();
  void PHP();
  void ORA_Immediate();
  void ASL();
  void ANC_Immediate();
  void NOP_Absolute();
  void ORA_Absolute();
  void ASL_Absolute();
  void SLO_Absolute();

  // 0x10 to 0x1F
  void BPL();
  void ORA_IndirectY();
  // empty
  void SLO_IndirectY();
  void NOP_ZPX();
  void ORA_ZPX();
  void ASL_ZPX();
  void SLO_ZPX();
  void CLC();
  void ORA_AbsoluteY();
  void SLO_AbsoluteY();
  void NOP_AbsoluteX();
  void ORA_AbsoluteX();
  void ASL_AbsoluteX();
  void SLO_AbsoluteX();

  // Instruction table
  std::array<std::function<void()>, 256> instructionTable;

public:
  // Constructor
  CPU();
};

#endif

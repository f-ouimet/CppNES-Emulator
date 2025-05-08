#ifndef CPU_H_
#define CPU_H_

#include <array>
#include <cstdint>
#include <functional>

class CPU {
private:
  uint16_t PC;
  uint16_t SP; // upper 8bits are fixed to 00000001

  uint8_t accumulator;
  uint8_t processorStatusReg;
  uint8_t xIndex;
  uint8_t yIndex;

  uint8_t mem[65535]; // address space 0x0000 to 0xFFFF

  // zero page goes from 0 to 00FF
  // system stack is 0100 to 01FF
  // Last 6 bytes are reserved
  // FFFA to FFFF is interrupt handler for A and B, power on reset for C and D,
  // BRK/Interrupt request handler E and F

  void executeInstruction(uint8_t opcode);
  // TODO:load rom in main or from CPU, where is ROM stored when execd?
  // void loadROM();

  // all instructions listed in row order from
  // https://llx.com/Neil/a2/opcodes.html
  // and https://nesdev.org/wiki/CPU_unofficial_opcodes
  // we use ALL opcodes from the base 6502
  //
  // https://www.nesdev.org/wiki/CPU_addressing_modes
  // #i or #v = immediate addr
  // a = absolute 16 bit addr
  // (a) = indirect
  // a,x abs x
  // a,y abs y
  // d = 8 bit zero page addr
  // d,x = zero page indexed X
  // d,y = Zero page indexed Y
  // (d,x) = Indirect_X  (indexed indirect)
  // (d),y = Indirect_Y  (indirect indexed)
  // A = accumulator
  // label = Relative

  // instruction functions
  // 0x00 to 0x1F
  void BRK();
  void ORA_IndirectX();
  void STP();
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
  // empty (STP)
  void SLO_IndirectY();
  void NOP_ZPX();
  void ORA_ZPX();
  void ASL_ZPX();
  void SLO_ZPX();
  void CLC();
  void ORA_AbsoluteY();
  void NOP();
  void SLO_AbsoluteY();
  void NOP_AbsoluteX();
  void ORA_AbsoluteX();
  void ASL_AbsoluteX();
  void SLO_AbsoluteX();

  // 0x20 to 0x2F
  void JSR_Absolute();
  void AND_IndirectX();
  // empty
  void RLA_IndirectX();
  void BIT_ZP();
  void AND_ZP();
  void ROL_ZP();
  void RLA_ZP();
  void PLP();
  void AND_Immediate();
  void ROL();
  // duplicate ANC_Immediate
  void BIT_Absolute();
  void AND_Absolute();
  void ROL_Absolute();
  void RLA_Absolute();
  // 0x30 to 0x3F
  void BMI();
  void AND_IndirectY();
  // empty
  void RLA_IndirectY();
  // duplicate NOP_ZPX
  void AND_ZPX();
  void ROL_ZPX();
  void RLA_ZPX();
  void SEC();
  void AND_AbsoluteY();
  // duped NOP
  void RLA_AbsoluteY();
  // duped NOP_AbsX
  void AND_AbsoluteX();
  void ROL_AbsoluteX();
  void RLA_AbsoluteX();
  //  0x40 to 0x4F
  void RTI();
  void EOR_IndirectX();
  // empty
  void SRE_IndirectX();
  // void NOP_ZP();
  void EOR_ZP();
  void LSR_ZP();
  void SRE_ZP();
  void PHA();
  void EOR_Immediate();
  void LSR();
  void ALR_Immediate();
  void JMP_Absolute();
  void EOR_Absolute();
  void LSR_Absolute();
  void SRE_Absolute();

  // 0x50 to 0x5F
  void BVC();
  void EOR_IndirectY();
  // undefined
  void SRE_IndirectY();
  // void NOP_ZPX();
  void EOR_ZPX();
  void LSR_ZPX();
  void SRE_ZPX();
  void CLI();
  void EOR_AbsoluteY();
  // void NOP();
  void SRE_AbsoluteY();
  // void NOP_AbsoluteX();
  void EOR_AbsoluteX();
  void LSR_AbsoluteX();
  void SRE_AbsoluteX();

  // 0x60 to 0x6F
  void RTS();
  void ADC_IndirectX();
  // undefined
  void RRA_IndirectX();
  // void NOP_ZP();
  void ADC_ZP();
  void ROR_ZP();
  void RRA_ZP();
  void PLA();
  void ADC_Immediate();
  void ROR();
  void ARR_Immediate();
  void JMP_Indirect();
  void ADC_Absolute();
  void ROR_Absolute();
  void RRA_Absolute();

  // 0x70 to 0x7F
  void BVS();
  void ADC_IndirectY();
  // undefined
  void RRA_IndirectY();
  // void NOP_ZPX();
  void ADC_ZPX();
  void ROR_ZPX();
  void RRA_ZPX();
  void SEI();
  void ADC_AbsoluteY();
  // void NOP();
  void RRA_AbsoluteY();
  // void NOP_AbsoluteX();
  void ADC_AbsoluteX();
  void ROR_AbsoluteX();
  void RRA_AbsoluteX();

  // 0x80 to 0x8F
  void NOP_Immediate();
  void STA_IndirectX();
  // void NOP_Immediate_2(); // same as 0x80 (undocumented), used for alias
  void SAX_IndirectX();
  void STY_ZP();
  void STA_ZP();
  void STX_ZP();
  void SAX_ZP();
  void DEY();
  // void NOP_Immediate_3(); // same as 0x89
  void TXA();
  void XAA_Immediate();
  void STY_Absolute();
  void STA_Absolute();
  void STX_Absolute();
  void SAX_Absolute();

  // 0x90 to 0x9F
  void BCC();
  void STA_IndirectY();
  // undefined
  void AHX_IndirectY();
  void STY_ZPX();
  void STA_ZPX();
  void STX_ZPY();
  void SAX_ZPY(); // unofficial
  void TYA();
  void STA_AbsoluteY();
  void TXS();
  void TAS_AbsoluteY();
  void SHY_AbsoluteX();
  void STA_AbsoluteX();
  void SHX_AbsoluteY();
  void AHX_AbsoluteY();

  // 0xA0 to 0xAF
  void LDY_Immediate();
  void LDA_IndirectX();
  void LDX_Immediate();
  void LAX_IndirectX();
  void LDY_ZP();
  void LDA_ZP();
  void LDX_ZP();
  void LAX_ZP();
  void TAY();
  void LDA_Immediate();
  void TAX();
  void LAX_Immediate();
  void LDY_Absolute();
  void LDA_Absolute();
  void LDX_Absolute();
  void LAX_Absolute();

  // 0xB0 to 0xBF
  void BCS();
  void LDA_IndirectY();
  // undefined
  void LAX_IndirectY();
  void LDY_ZPX();
  void LDA_ZPX();
  void LDX_ZPY();
  void LAX_ZPY();
  void CLV();
  void LDA_AbsoluteY();
  void TSX();
  void LAS_AbsoluteY();
  void LDY_AbsoluteX();
  void LDA_AbsoluteX();
  void LDX_AbsoluteY();
  void LAX_AbsoluteY();

  // 0xC0 to 0xCF
  void CPY_Immediate();
  void CMP_IndirectX();
  // undefined
  void DCP_IndirectX();
  void CPY_ZP();
  void CMP_ZP();
  void DEC_ZP();
  void DCP_ZP();
  void INY();
  void CMP_Immediate();
  void DEX();
  void AXS_Immediate();
  void CPY_Absolute();
  void CMP_Absolute();
  void DEC_Absolute();
  void DCP_Absolute();

  // 0xD0 to 0xDF
  void BNE();
  void CMP_IndirectY();
  // undefined
  void DCP_IndirectY();
  // void NOP_ZPX();
  void CMP_ZPX();
  void DEC_ZPX();
  void DCP_ZPX();
  void CLD();
  void CMP_AbsoluteY();
  // void NOP();
  void DCP_AbsoluteY();
  // void NOP_AbsoluteX();
  void CMP_AbsoluteX();
  void DEC_AbsoluteX();
  void DCP_AbsoluteX();

  // 0xE0 to 0xEF
  void CPX_Immediate();
  void SBC_IndirectX();
  // undefined
  void ISC_IndirectX();
  void CPX_ZP();
  void SBC_ZP();
  void INC_ZP();
  void ISC_ZP();
  void INX();
  void SBC_Immediate();
  // void NOP_Immediate();
  //  void SBC_Immediate_2(); // unofficial ALR/ISC style op
  void CPX_Absolute();
  void SBC_Absolute();
  void INC_Absolute();
  void ISC_Absolute();

  // 0xF0 to 0xFF
  void BEQ();
  void SBC_IndirectY();
  // undefined
  void ISC_IndirectY();
  // void NOP_ZPX();
  void SBC_ZPX();
  void INC_ZPX();
  void ISC_ZPX();
  void SED();
  void SBC_AbsoluteY();
  // void NOP();
  void ISC_AbsoluteY();
  // void NOP_AbsoluteX();
  void SBC_AbsoluteX();
  void INC_AbsoluteX();
  void ISC_AbsoluteX();

  // Instruction table
  std::array<std::function<void()>, 256> instructionTable;

public:
  // Constructor
  CPU();
};

#endif

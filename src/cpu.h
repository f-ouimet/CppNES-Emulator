#ifndef CPU_H_
#define CPU_H_

#include <array>
#include <cstdint>
#include <functional>

class CPU {
private:
  uint8_t accum;
  uint8_t xindex;
  uint8_t yindex;
  uint8_t flagp;
  uint8_t SP;
  uint16_t PC;
  void executeInstruction(uint8_t opcode);

  // all instructions listed in row order from
  // https://llx.com/Neil/a2/opcodes.html
  // we use the legal opcodes from the base 6502

  void BRK();
  void ORA_IndirectX();
  void ORA_ZeroPage();
  void ASL_ZeroPage();
  void PHP();
  void ORA_Immediate();
  void ASL_Accumulator();
  void ORA_Absolute();
  void ASL_Absolute();

  void BPL();
  void ORA_IndirectY();
  void ORA_ZeroPageX();
  void ASL_ZeroPageX();
  void CLC();
  void ORA_AbsoluteY();
  void ORA_AbsoluteX();
  void ASL_AbsoluteX();

  void JSR();
  void AND_IndirectX();
  void BIT_ZeroPage();
  void AND_ZeroPage();
  void ROL_ZeroPage();
  void PLP();
  void AND_Immediate();
  void ROL_Accumulator();
  void BIT_Absolute();
  void AND_Absolute();
  void ROL_Absolute();

  void BMI();
  void AND_IndirectY();
  void AND_ZeroPageX();
  void ROL_ZeroPageX();
  void SEC();
  void AND_AbsoluteY();
  void AND_AbsoluteX();
  void ROL_AbsoluteX();

  void RTI();
  void EOR_IndirectX();
  void EOR_ZeroPage();
  void LSR_ZeroPage();
  void PHA();
  void EOR_Immediate();
  void LSR_Accumulator();
  void JMP_Absolute();
  void EOR_Absolute();
  void LSR_Absolute();

  void BVC();
  void EOR_IndirectY();
  void EOR_ZeroPageX();
  void LSR_ZeroPageX();
  void CLI();
  void EOR_AbsoluteY();
  void EOR_AbsoluteX();
  void LSR_AbsoluteX();

  void RTS();
  void ADC_IndirectX();
  void ADC_ZeroPage();
  void ROR_ZeroPage();
  void PLA();
  void ADC_Immediate();
  void ROR_Accumulator();
  void JMP_Indirect();
  void ADC_Absolute();
  void ROR_Absolute();

  void BVS();
  void ADC_IndirectY();
  void ADC_ZeroPageX();
  void ROR_ZeroPageX();
  void SEI();
  void ADC_AbsoluteY();
  void ADC_AbsoluteX();
  void ROR_AbsoluteX();

  void STA_IndirectX();
  void STY_ZeroPage();
  void STA_ZeroPage();
  void STX_ZeroPage();
  void DEY();
  void TXA();
  void STY_Absolute();
  void STA_Absolute();
  void STX_Absolute();

  void BCC();
  void STA_IndirectY();
  void STY_ZeroPageX();
  void STA_ZeroPageX();
  void STX_ZeroPageY();
  void TYA();
  void STA_AbsoluteY();
  void TXS();
  void STA_AbsoluteX();

  void LDY_Immediate();
  void LDA_IndirectX();
  void LDX_Immediate();
  void LDY_ZeroPage();
  void LDA_ZeroPage();
  void LDX_ZeroPage();
  void TAY();
  void LDA_Immediate();
  void TAX();
  void LDY_Absolute();
  void LDA_Absolute();
  void LDX_Absolute();

  void BCS();
  void LDA_IndirectY();
  void LDY_ZeroPageX();
  void LDA_ZeroPageX();
  void LDX_ZeroPageY();
  void CLV();
  void LDA_AbsoluteY();
  void TSX();
  void LDY_AbsoluteX();
  void LDA_AbsoluteX();
  void LDX_AbsoluteY();

  void CPY_Immediate();
  void CMP_IndirectX();
  void CPY_ZeroPage();
  void CMP_ZeroPage();
  void DEC_ZeroPage();
  void INY();
  void CMP_Immediate();
  void DEX();
  void CPY_Absolute();
  void CMP_Absolute();
  void DEC_Absolute();

  void BNE();
  void CMP_IndirectY();
  void CMP_ZeroPageX();
  void DEC_ZeroPageX();
  void CLD();
  void CMP_AbsoluteY();
  void CMP_AbsoluteX();
  void DEC_AbsoluteX();

  void CPX_Immediate();
  void SBC_IndirectX();
  void CPX_ZeroPage();
  void SBC_ZeroPage();
  void INC_ZeroPage();
  void INX();
  void SBC_Immediate();
  void NOP();
  void CPX_Absolute();
  void SBC_Absolute();
  void INC_Absolute();

  void BEQ();
  void SBC_IndirectY();
  void SBC_ZeroPageX();
  void INC_ZeroPageX();
  void SED();
  void SBC_AbsoluteY();
  void SBC_AbsoluteX();
  void INC_AbsoluteX();

  // Instruction table
  std::array<std::function<void()>, 256> instructionTable;

public:
  // Constructor
  CPU();
};

#endif

// class CPU
// The 6502 CPU architecture and its operations are defined in this class
//
//
#include "cpu.h"

CPU::CPU() {
  instructionTable.fill(
      [this]() { this->NOP(); }); // for unknown opcodes, default to NOP
}

void CPU::executeInstruction(uint8_t opcode) { instructionTable[opcode](); }

void CPU::BRK() {}
void CPU::ORA_IndirectX() {}
void CPU::ORA_ZeroPage() {}
void CPU::ASL_ZeroPage() {}
void CPU::PHP() {}
void CPU::ORA_Immediate() {}
void CPU::ASL_Accumulator() {}
void CPU::ORA_Absolute() {}
void CPU::ASL_Absolute() {}

void CPU::BPL() {}
void CPU::ORA_IndirectY() {}
void CPU::ORA_ZeroPageX() {}
void CPU::ASL_ZeroPageX() {}
void CPU::CLC() {}
void CPU::ORA_AbsoluteY() {}
void CPU::ORA_AbsoluteX() {}
void CPU::ASL_AbsoluteX() {}

void CPU::JSR() {}
void CPU::AND_IndirectX() {}
void CPU::BIT_ZeroPage() {}
void CPU::AND_ZeroPage() {}
void CPU::ROL_ZeroPage() {}
void CPU::PLP() {}
void CPU::AND_Immediate() {}
void CPU::ROL_Accumulator() {}
void CPU::BIT_Absolute() {}
void CPU::AND_Absolute() {}
void CPU::ROL_Absolute() {}

void CPU::BMI() {}
void CPU::AND_IndirectY() {}
void CPU::AND_ZeroPageX() {}
void CPU::ROL_ZeroPageX() {}
void CPU::SEC() {}
void CPU::AND_AbsoluteY() {}
void CPU::AND_AbsoluteX() {}
void CPU::ROL_AbsoluteX() {}

void CPU::RTI() {}
void CPU::EOR_IndirectX() {}
void CPU::EOR_ZeroPage() {}
void CPU::LSR_ZeroPage() {}
void CPU::PHA() {}
void CPU::EOR_Immediate() {}
void CPU::LSR_Accumulator() {}
void CPU::JMP_Absolute() {}
void CPU::EOR_Absolute() {}
void CPU::LSR_Absolute() {}

void CPU::BVC() {}
void CPU::EOR_IndirectY() {}
void CPU::EOR_ZeroPageX() {}
void CPU::LSR_ZeroPageX() {}
void CPU::CLI() {}
void CPU::EOR_AbsoluteY() {}
void CPU::EOR_AbsoluteX() {}
void CPU::LSR_AbsoluteX() {}

void CPU::RTS() {}
void CPU::ADC_IndirectX() {}
void CPU::ADC_ZeroPage() {}
void CPU::ROR_ZeroPage() {}
void CPU::PLA() {}
void CPU::ADC_Immediate() {}
void CPU::ROR_Accumulator() {}
void CPU::JMP_Indirect() {}
void CPU::ADC_Absolute() {}
void CPU::ROR_Absolute() {}

void CPU::BVS() {}
void CPU::ADC_IndirectY() {}
void CPU::ADC_ZeroPageX() {}
void CPU::ROR_ZeroPageX() {}
void CPU::SEI() {}
void CPU::ADC_AbsoluteY() {}
void CPU::ADC_AbsoluteX() {}
void CPU::ROR_AbsoluteX() {}

void CPU::STA_IndirectX() {}
void CPU::STY_ZeroPage() {}
void CPU::STA_ZeroPage() {}
void CPU::STX_ZeroPage() {}
void CPU::DEY() {}
void CPU::TXA() {}
void CPU::STY_Absolute() {}
void CPU::STA_Absolute() {}
void CPU::STX_Absolute() {}

void CPU::BCC() {}
void CPU::STA_IndirectY() {}
void CPU::STY_ZeroPageX() {}
void CPU::STA_ZeroPageX() {}
void CPU::STX_ZeroPageY() {}
void CPU::TYA() {}
void CPU::STA_AbsoluteY() {}
void CPU::TXS() {}
void CPU::STA_AbsoluteX() {}

void CPU::LDY_Immediate() {}
void CPU::LDA_IndirectX() {}
void CPU::LDX_Immediate() {}
void CPU::LDY_ZeroPage() {}
void CPU::LDA_ZeroPage() {}
void CPU::LDX_ZeroPage() {}
void CPU::TAY() {}
void CPU::LDA_Immediate() {}
void CPU::TAX() {}
void CPU::LDY_Absolute() {}
void CPU::LDA_Absolute() {}
void CPU::LDX_Absolute() {}

void CPU::BCS() {}
void CPU::LDA_IndirectY() {}
void CPU::LDY_ZeroPageX() {}
void CPU::LDA_ZeroPageX() {}
void CPU::LDX_ZeroPageY() {}
void CPU::CLV() {}
void CPU::LDA_AbsoluteY() {}
void CPU::TSX() {}
void CPU::LDY_AbsoluteX() {}
void CPU::LDA_AbsoluteX() {}
void CPU::LDX_AbsoluteY() {}

void CPU::CPY_Immediate() {}
void CPU::CMP_IndirectX() {}
void CPU::CPY_ZeroPage() {}
void CPU::CMP_ZeroPage() {}
void CPU::DEC_ZeroPage() {}
void CPU::INY() {}
void CPU::CMP_Immediate() {}
void CPU::DEX() {}
void CPU::CPY_Absolute() {}
void CPU::CMP_Absolute() {}
void CPU::DEC_Absolute() {}

void CPU::BNE() {}
void CPU::CMP_IndirectY() {}
void CPU::CMP_ZeroPageX() {}
void CPU::DEC_ZeroPageX() {}
void CPU::CLD() {}
void CPU::CMP_AbsoluteY() {}
void CPU::CMP_AbsoluteX() {}
void CPU::DEC_AbsoluteX() {}

void CPU::CPX_Immediate() {}
void CPU::SBC_IndirectX() {}
void CPU::CPX_ZeroPage() {}
void CPU::SBC_ZeroPage() {}
void CPU::INC_ZeroPage() {}
void CPU::INX() {}
void CPU::SBC_Immediate() {}
void CPU::NOP() {}
void CPU::CPX_Absolute() {}
void CPU::SBC_Absolute() {}
void CPU::INC_Absolute() {}

void CPU::BEQ() {}
void CPU::SBC_IndirectY() {}
void CPU::SBC_ZeroPageX() {}
void CPU::INC_ZeroPageX() {}
void CPU::SED() {}
void CPU::SBC_AbsoluteY() {}
void CPU::SBC_AbsoluteX() {}
void CPU::INC_AbsoluteX() {}

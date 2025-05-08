// class CPU
// The 6502 CPU architecture and its operations are defined in this class
//
//
#include "cpu.h"

CPU::CPU() {
  instructionTable.fill(
      [this]() { this->NOP(); }); // for unknown opcodes, default to NOP
  // 0x00 to 0x0F : Checked Content
  instructionTable[0x00] = [this]() { this->BRK(); };
  instructionTable[0x01] = [this]() { this->ORA_IndirectX(); };
  instructionTable[0x02] = [this]() { this->STP(); };
  instructionTable[0x03] = [this]() { this->SLO_IndirectX(); };
  instructionTable[0x04] = [this]() { this->NOP_ZP(); };
  instructionTable[0x05] = [this]() { this->ORA_ZP(); };
  instructionTable[0x06] = [this]() { this->ASL_ZP(); };
  instructionTable[0x07] = [this]() { this->SLO_ZP(); };
  instructionTable[0x08] = [this]() { this->PHP(); };
  instructionTable[0x09] = [this]() { this->ORA_Immediate(); };
  instructionTable[0x0A] = [this]() { this->ASL(); };
  instructionTable[0x0B] = [this]() { this->ANC_Immediate(); };
  instructionTable[0x0C] = [this]() { this->NOP_Absolute(); };
  instructionTable[0x0D] = [this]() { this->ORA_Absolute(); };
  instructionTable[0x0E] = [this]() { this->ASL_Absolute(); };
  instructionTable[0x0F] = [this]() { this->SLO_Absolute(); };

  // 0x10 - 0x1F
  instructionTable[0x10] = [this]() { this->BPL(); };
  instructionTable[0x11] = [this]() { this->ORA_IndirectY(); };
  instructionTable[0x12] = [this]() { this->STP(); };
  instructionTable[0x13] = [this]() { this->SLO_IndirectY(); };
  instructionTable[0x14] = [this]() { this->NOP_ZPX(); };
  instructionTable[0x15] = [this]() { this->ORA_ZPX(); };
  instructionTable[0x16] = [this]() { this->ASL_ZPX(); };
  instructionTable[0x17] = [this]() { this->SLO_ZPX(); };
  instructionTable[0x18] = [this]() { this->CLC(); };
  instructionTable[0x19] = [this]() { this->ORA_AbsoluteY(); };
  instructionTable[0x1A] = [this]() { this->NOP(); };
  instructionTable[0x1B] = [this]() { this->SLO_AbsoluteY(); };
  instructionTable[0x1C] = [this]() { this->NOP_AbsoluteX(); };
  instructionTable[0x1D] = [this]() { this->ORA_AbsoluteX(); };
  instructionTable[0x1E] = [this]() { this->ASL_AbsoluteX(); };
  instructionTable[0x1F] = [this]() { this->SLO_AbsoluteX(); };

  // 0x20 - 0x2F
  instructionTable[0x20] = [this]() { this->JSR_Absolute(); };
  instructionTable[0x21] = [this]() { this->AND_IndirectX(); };
  instructionTable[0x22] = [this]() { this->NOP(); };
  instructionTable[0x23] = [this]() { this->RLA_IndirectX(); };
  instructionTable[0x24] = [this]() { this->BIT_ZP(); };
  instructionTable[0x25] = [this]() { this->AND_ZP(); };
  instructionTable[0x26] = [this]() { this->ROL_ZP(); };
  instructionTable[0x27] = [this]() { this->RLA_ZP(); };
  instructionTable[0x28] = [this]() { this->PLP(); };
  instructionTable[0x29] = [this]() { this->AND_Immediate(); };
  instructionTable[0x2A] = [this]() { this->ROL(); };
  instructionTable[0x2B] = [this]() { this->ANC_Immediate(); };
  instructionTable[0x2C] = [this]() { this->BIT_Absolute(); };
  instructionTable[0x2D] = [this]() { this->AND_Absolute(); };
  instructionTable[0x2E] = [this]() { this->ROL_Absolute(); };
  instructionTable[0x2F] = [this]() { this->RLA_Absolute(); };

  // 0x30 - 0x3F
  instructionTable[0x30] = [this]() { this->BMI(); };
  instructionTable[0x31] = [this]() { this->AND_IndirectY(); };
  instructionTable[0x32] = [this]() { this->NOP(); };
  instructionTable[0x33] = [this]() { this->RLA_IndirectY(); };
  instructionTable[0x34] = [this]() { this->NOP_ZPX(); };
  instructionTable[0x35] = [this]() { this->AND_ZPX(); };
  instructionTable[0x36] = [this]() { this->ROL_ZPX(); };
  instructionTable[0x37] = [this]() { this->RLA_ZPX(); };
  instructionTable[0x38] = [this]() { this->SEC(); };
  instructionTable[0x39] = [this]() { this->AND_AbsoluteY(); };
  instructionTable[0x3A] = [this]() { this->NOP(); };
  instructionTable[0x3B] = [this]() { this->RLA_AbsoluteY(); };
  instructionTable[0x3C] = [this]() { this->NOP_AbsoluteX(); };
  instructionTable[0x3D] = [this]() { this->AND_AbsoluteX(); };
  instructionTable[0x3E] = [this]() { this->ROL_AbsoluteX(); };
  instructionTable[0x3F] = [this]() { this->RLA_AbsoluteX(); };

  // 0x40 - 0x4F
  instructionTable[0x40] = [this]() { this->RTI(); };
  instructionTable[0x41] = [this]() { this->EOR_IndirectX(); };
  instructionTable[0x42] = [this]() { this->NOP(); };
  instructionTable[0x43] = [this]() { this->SRE_IndirectX(); };
  instructionTable[0x44] = [this]() { this->NOP_ZP(); };
  instructionTable[0x45] = [this]() { this->EOR_ZP(); };
  instructionTable[0x46] = [this]() { this->LSR_ZP(); };
  instructionTable[0x47] = [this]() { this->SRE_ZP(); };
  instructionTable[0x48] = [this]() { this->PHA(); };
  instructionTable[0x49] = [this]() { this->EOR_Immediate(); };
  instructionTable[0x4A] = [this]() { this->LSR(); };
  instructionTable[0x4B] = [this]() { this->ALR_Immediate(); };
  instructionTable[0x4C] = [this]() { this->JMP_Absolute(); };
  instructionTable[0x4D] = [this]() { this->EOR_Absolute(); };
  instructionTable[0x4E] = [this]() { this->LSR_Absolute(); };
  instructionTable[0x4F] = [this]() { this->SRE_Absolute(); };

  // 0x50 - 0x5F
  instructionTable[0x50] = [this]() { this->BVC(); };
  instructionTable[0x51] = [this]() { this->EOR_IndirectY(); };
  instructionTable[0x52] = [this]() { this->NOP(); };
  instructionTable[0x53] = [this]() { this->SRE_IndirectY(); };
  instructionTable[0x54] = [this]() { this->NOP_ZPX(); };
  instructionTable[0x55] = [this]() { this->EOR_ZPX(); };
  instructionTable[0x56] = [this]() { this->LSR_ZPX(); };
  instructionTable[0x57] = [this]() { this->SRE_ZPX(); };
  instructionTable[0x58] = [this]() { this->CLI(); };
  instructionTable[0x59] = [this]() { this->EOR_AbsoluteY(); };
  instructionTable[0x5A] = [this]() { this->NOP(); };
  instructionTable[0x5B] = [this]() { this->SRE_AbsoluteY(); };
  instructionTable[0x5C] = [this]() { this->NOP_AbsoluteX(); };
  instructionTable[0x5D] = [this]() { this->EOR_AbsoluteX(); };
  instructionTable[0x5E] = [this]() { this->LSR_AbsoluteX(); };
  instructionTable[0x5F] = [this]() { this->SRE_AbsoluteX(); };

  // 0x60 - 0x6F
  instructionTable[0x60] = [this]() { this->RTS(); };
  instructionTable[0x61] = [this]() { this->ADC_IndirectX(); };
  instructionTable[0x62] = [this]() { this->NOP(); };
  instructionTable[0x63] = [this]() { this->RRA_IndirectX(); };
  instructionTable[0x64] = [this]() { this->NOP_ZP(); };
  instructionTable[0x65] = [this]() { this->ADC_ZP(); };
  instructionTable[0x66] = [this]() { this->ROR_ZP(); };
  instructionTable[0x67] = [this]() { this->RRA_ZP(); };
  instructionTable[0x68] = [this]() { this->PLA(); };
  instructionTable[0x69] = [this]() { this->ADC_Immediate(); };
  instructionTable[0x6A] = [this]() { this->ROR(); };
  instructionTable[0x6B] = [this]() { this->ARR_Immediate(); };
  instructionTable[0x6C] = [this]() { this->JMP_Indirect(); };
  instructionTable[0x6D] = [this]() { this->ADC_Absolute(); };
  instructionTable[0x6E] = [this]() { this->ROR_Absolute(); };
  instructionTable[0x6F] = [this]() { this->RRA_Absolute(); };

  // 0x70 - 0x7F
  instructionTable[0x70] = [this]() { this->BVS(); };
  instructionTable[0x71] = [this]() { this->ADC_IndirectY(); };
  instructionTable[0x72] = [this]() { this->NOP(); };
  instructionTable[0x73] = [this]() { this->RRA_IndirectY(); };
  instructionTable[0x74] = [this]() { this->NOP_ZPX(); };
  instructionTable[0x75] = [this]() { this->ADC_ZPX(); };
  instructionTable[0x76] = [this]() { this->ROR_ZPX(); };
  instructionTable[0x77] = [this]() { this->RRA_ZPX(); };
  instructionTable[0x78] = [this]() { this->SEI(); };
  instructionTable[0x79] = [this]() { this->ADC_AbsoluteY(); };
  instructionTable[0x7A] = [this]() { this->NOP(); };
  instructionTable[0x7B] = [this]() { this->RRA_AbsoluteY(); };
  instructionTable[0x7C] = [this]() { this->NOP_AbsoluteX(); };
  instructionTable[0x7D] = [this]() { this->ADC_AbsoluteX(); };
  instructionTable[0x7E] = [this]() { this->ROR_AbsoluteX(); };
  instructionTable[0x7F] = [this]() { this->RRA_AbsoluteX(); };

  // 0x80 - 0x8F
  instructionTable[0x80] = [this]() { this->NOP_Immediate(); };
  instructionTable[0x81] = [this]() { this->STA_IndirectX(); };
  instructionTable[0x82] = [this]() { this->NOP(); };
  instructionTable[0x83] = [this]() { this->SAX_IndirectX(); };
  instructionTable[0x84] = [this]() { this->STY_ZP(); };
  instructionTable[0x85] = [this]() { this->STA_ZP(); };
  instructionTable[0x86] = [this]() { this->STX_ZP(); };
  instructionTable[0x87] = [this]() { this->SAX_ZP(); };
  instructionTable[0x88] = [this]() { this->DEY(); };
  instructionTable[0x89] = [this]() { this->NOP(); };
  instructionTable[0x8A] = [this]() { this->TXA(); };
  instructionTable[0x8B] = [this]() { this->XAA_Immediate(); };
  instructionTable[0x8C] = [this]() { this->STY_Absolute(); };
  instructionTable[0x8D] = [this]() { this->STA_Absolute(); };
  instructionTable[0x8E] = [this]() { this->STX_Absolute(); };
  instructionTable[0x8F] = [this]() { this->SAX_Absolute(); };

  // 0x90 - 0x9F
  instructionTable[0x90] = [this]() { this->BCC(); };
  instructionTable[0x91] = [this]() { this->STA_IndirectY(); };
  instructionTable[0x92] = [this]() { this->NOP(); };
  instructionTable[0x93] = [this]() { this->AHX_IndirectY(); };
  instructionTable[0x94] = [this]() { this->STY_ZPX(); };
  instructionTable[0x95] = [this]() { this->STA_ZPX(); };
  instructionTable[0x96] = [this]() { this->STX_ZPY(); };
  instructionTable[0x97] = [this]() { this->SAX_ZPY(); };
  instructionTable[0x98] = [this]() { this->TYA(); };
  instructionTable[0x99] = [this]() { this->STA_AbsoluteY(); };
  instructionTable[0x9A] = [this]() { this->TXS(); };
  instructionTable[0x9B] = [this]() { this->TAS_AbsoluteY(); };
  instructionTable[0x9C] = [this]() { this->SHY_AbsoluteX(); };
  instructionTable[0x9D] = [this]() { this->STA_AbsoluteX(); };
  instructionTable[0x9E] = [this]() { this->SHX_AbsoluteY(); };
  instructionTable[0x9F] = [this]() { this->AHX_AbsoluteY(); };

  // 0xA0 - 0xAF
  instructionTable[0xA0] = [this]() { this->LDY_Immediate(); };
  instructionTable[0xA1] = [this]() { this->LDA_IndirectX(); };
  instructionTable[0xA2] = [this]() { this->LDX_Immediate(); };
  instructionTable[0xA3] = [this]() { this->LAX_IndirectX(); };
  instructionTable[0xA4] = [this]() { this->LDY_ZP(); };
  instructionTable[0xA5] = [this]() { this->LDA_ZP(); };
  instructionTable[0xA6] = [this]() { this->LDX_ZP(); };
  instructionTable[0xA7] = [this]() { this->LAX_ZP(); };
  instructionTable[0xA8] = [this]() { this->TAY(); };
  instructionTable[0xA9] = [this]() { this->LDA_Immediate(); };
  instructionTable[0xAA] = [this]() { this->TAX(); };
  instructionTable[0xAB] = [this]() { this->LAX_Immediate(); };
  instructionTable[0xAC] = [this]() { this->LDY_Absolute(); };
  instructionTable[0xAD] = [this]() { this->LDA_Absolute(); };
  instructionTable[0xAE] = [this]() { this->LDX_Absolute(); };
  instructionTable[0xAF] = [this]() { this->LAX_Absolute(); };

  // 0xB0 - 0xBF
  instructionTable[0xB0] = [this]() { this->BCS(); };
  instructionTable[0xB1] = [this]() { this->LDA_IndirectY(); };
  instructionTable[0xB2] = [this]() { this->NOP(); };
  instructionTable[0xB3] = [this]() { this->LAX_IndirectY(); };
  instructionTable[0xB4] = [this]() { this->LDY_ZPX(); };
  instructionTable[0xB5] = [this]() { this->LDA_ZPX(); };
  instructionTable[0xB6] = [this]() { this->LDX_ZPY(); };
  instructionTable[0xB7] = [this]() { this->LAX_ZPY(); };
  instructionTable[0xB8] = [this]() { this->CLV(); };
  instructionTable[0xB9] = [this]() { this->LDA_AbsoluteY(); };
  instructionTable[0xBA] = [this]() { this->TSX(); };
  instructionTable[0xBB] = [this]() { this->LAS_AbsoluteY(); };
  instructionTable[0xBC] = [this]() { this->LDY_AbsoluteX(); };
  instructionTable[0xBD] = [this]() { this->LDA_AbsoluteX(); };
  instructionTable[0xBE] = [this]() { this->LDX_AbsoluteY(); };
  instructionTable[0xBF] = [this]() { this->LAX_AbsoluteY(); };

  // 0xC0 - 0xCF
  instructionTable[0xC0] = [this]() { this->CPY_Immediate(); };
  instructionTable[0xC1] = [this]() { this->CMP_IndirectX(); };
  instructionTable[0xC2] = [this]() { this->NOP(); };
  instructionTable[0xC3] = [this]() { this->DCP_IndirectX(); };
  instructionTable[0xC4] = [this]() { this->CPY_ZP(); };
  instructionTable[0xC5] = [this]() { this->CMP_ZP(); };
  instructionTable[0xC6] = [this]() { this->DEC_ZP(); };
  instructionTable[0xC7] = [this]() { this->DCP_ZP(); };
  instructionTable[0xC8] = [this]() { this->INY(); };
  instructionTable[0xC9] = [this]() { this->CMP_Immediate(); };
  instructionTable[0xCA] = [this]() { this->DEX(); };
  instructionTable[0xCB] = [this]() { this->AXS_Immediate(); };
  instructionTable[0xCC] = [this]() { this->CPY_Absolute(); };
  instructionTable[0xCD] = [this]() { this->CMP_Absolute(); };
  instructionTable[0xCE] = [this]() { this->DEC_Absolute(); };
  instructionTable[0xCF] = [this]() { this->DCP_Absolute(); };

  // 0xD0 - 0xDF
  instructionTable[0xD0] = [this]() { this->BNE(); };
  instructionTable[0xD1] = [this]() { this->CMP_IndirectY(); };
  instructionTable[0xD2] = [this]() { this->NOP(); };
  instructionTable[0xD3] = [this]() { this->DCP_IndirectY(); };
  instructionTable[0xD4] = [this]() { this->NOP_ZPX(); };
  instructionTable[0xD5] = [this]() { this->CMP_ZPX(); };
  instructionTable[0xD6] = [this]() { this->DEC_ZPX(); };
  instructionTable[0xD7] = [this]() { this->DCP_ZPX(); };
  instructionTable[0xD8] = [this]() { this->CLD(); };
  instructionTable[0xD9] = [this]() { this->CMP_AbsoluteY(); };
  instructionTable[0xDA] = [this]() { this->NOP(); };
  instructionTable[0xDB] = [this]() { this->DCP_AbsoluteY(); };
  instructionTable[0xDC] = [this]() { this->NOP_AbsoluteX(); };
  instructionTable[0xDD] = [this]() { this->CMP_AbsoluteX(); };
  instructionTable[0xDE] = [this]() { this->DEC_AbsoluteX(); };
  instructionTable[0xDF] = [this]() { this->DCP_AbsoluteX(); };

  // 0xE0 - 0xEF
  instructionTable[0xE0] = [this]() { this->CPX_Immediate(); };
  instructionTable[0xE1] = [this]() { this->SBC_IndirectX(); };
  instructionTable[0xE2] = [this]() { this->NOP(); };
  instructionTable[0xE3] = [this]() { this->ISC_IndirectX(); };
  instructionTable[0xE4] = [this]() { this->CPX_ZP(); };
  instructionTable[0xE5] = [this]() { this->SBC_ZP(); };
  instructionTable[0xE6] = [this]() { this->INC_ZP(); };
  instructionTable[0xE7] = [this]() { this->ISC_ZP(); };
  instructionTable[0xE8] = [this]() { this->INX(); };
  instructionTable[0xE9] = [this]() { this->SBC_Immediate(); };
  instructionTable[0xEA] = [this]() { this->NOP(); };
  instructionTable[0xEB] = [this]() { this->SBC_Immediate(); };
  instructionTable[0xEC] = [this]() { this->CPX_Absolute(); };
  instructionTable[0xED] = [this]() { this->SBC_Absolute(); };
  instructionTable[0xEE] = [this]() { this->INC_Absolute(); };
  instructionTable[0xEF] = [this]() { this->ISC_Absolute(); };

  // 0xF0 - 0xFF
  instructionTable[0xF0] = [this]() { this->BEQ(); };
  instructionTable[0xF1] = [this]() { this->SBC_IndirectY(); };
  instructionTable[0xF2] = [this]() { this->NOP(); };
  instructionTable[0xF3] = [this]() { this->ISC_IndirectY(); };
  instructionTable[0xF4] = [this]() { this->NOP_ZPX(); };
  instructionTable[0xF5] = [this]() { this->SBC_ZPX(); };
  instructionTable[0xF6] = [this]() { this->INC_ZPX(); };
  instructionTable[0xF7] = [this]() { this->ISC_ZPX(); };
  instructionTable[0xF8] = [this]() { this->SED(); };
  instructionTable[0xF9] = [this]() { this->SBC_AbsoluteY(); };
  instructionTable[0xFA] = [this]() { this->NOP(); };
  instructionTable[0xFB] = [this]() { this->ISC_AbsoluteY(); };
  instructionTable[0xFC] = [this]() { this->NOP_AbsoluteX(); };
  instructionTable[0xFD] = [this]() { this->SBC_AbsoluteX(); };
  instructionTable[0xFE] = [this]() { this->INC_AbsoluteX(); };
  instructionTable[0xFF] = [this]() { this->ISC_AbsoluteX(); };
}

void BRK() { return; }

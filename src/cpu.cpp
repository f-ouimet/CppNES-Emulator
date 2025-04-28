// class CPU
#include <bit>
#include <bitset>
#include <cstdlib>
#include <inttypes.h>

// The 6502 CPU and its operations are listed in this class
class CPU {
public:
  uint8_t accum;
  uint8_t xindex;
  uint8_t yindex;
  uint8_t flagp;
  uint8_t SP;
  uint16_t PC;

private:
};

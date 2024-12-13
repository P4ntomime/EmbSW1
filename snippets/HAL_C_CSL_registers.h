enum{csl_bit0  = 0x00000001, csl_bit1  = 0x00000002, csl_bit2 = 0x00000004,
     // ...
     csl_bit29 = 0x20000000, csl_bit30 = 0x40000000, csl_bit31 = 0x80000000};

static inline void csl_hwReg32SetBits(volatile uint32_t* reg, uint32_t bits) 
    {*reg |= bits;}
static inline void csl_hwReg316ClearBits(volatile uint16_t* reg, uint16_t bits)
    {*reg &= ~bits;}
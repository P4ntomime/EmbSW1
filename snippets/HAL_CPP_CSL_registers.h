enum{bit0  = 0x00000001, bit1  = 0x00000002, bit2 = 0x00000004,
     // ...
     bit29 = 0x20000000, bit30 = 0x40000000, bit31 = 0x80000000};

template<typename RegType>
class HwReg
{
  public:

    static void setBits(volatile RegType& reg, const RegType& bits)
      {*reg |= bits;}   // still inline
    static inline void clearBits(volatile RegType& reg, const RegType& bits)
      {*reg &= ~bits;}  // still inline
}
typedef volatile struct{
  uint32_t ctrl;
  uint32_t sel[2];
  uint32_t mux[2];
  uint32_t dir;
  uint32_t pud;} csl_PortCtrlRegs;

typedef volatile struct{
  const uint32_t dat;
  uint32_t set;
  uint32_t clear;
  uint32_t toggle;} csl_PortDataRegs;

typedef struct{
  csl_PortCtrlRegs* ctrl;
  csl_PortDataRegs* data;} csl_Port;

enum
{
  addrPortACtrlRegs = 0x00006F80,
  addrPortBCtrlRegs = 0x00006F90,
  addrPortADataRegs = 0x00006FC0,
  addrPortBDataRegs = 0x00006FC8
};

void csl_portInit(csl_Port* port, csl_PortId id, bool initSamplePeriod);



// pin definition
typedef struct{
  csl_Port port;
  uint32_t bit;} csl_Pin;

void csl_pinInit(csl_Pin* pin, csl_PinId id, csl_PinMux mux);

static inline bool csl_pinGet(const csl_Pin* pin)
  {return csl_hwReg32AreBitsSet(&(pin->port.data->dat), pin->bit);}
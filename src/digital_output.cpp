#include "ExVectrHAL/digital_output.hpp"

#include "stdint.h"


bool VCTR::HAL::DigitalOutput::writeByte(uint8_t byte, bool endTransfer) {
    return writeData(&byte, 1, endTransfer) == 1;
}
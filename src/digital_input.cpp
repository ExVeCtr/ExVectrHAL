#include "ExVectrHAL/digital_input.hpp"

#include "stdint.h"


bool VCTR::HAL::DigitalInput::readByte(uint8_t& byte, bool endTransfer) {
    return readData(&byte, 1, endTransfer) == 1;
}
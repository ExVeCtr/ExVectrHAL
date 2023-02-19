#include "ExVectrHAL/input.hpp"

#include "stdint.h"


bool VCTR::HAL::Input::readByte(uint8_t& byte, bool endTransfer) {
    return readData(&byte, 1, endTransfer) == 1;
}
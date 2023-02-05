#include "ExVectrHAL/input.hpp"

#include "stdint.h"


bool VCTR::HAL::Input::readByte(uint8_t& byte) {
    return readData(&byte, 1) == 1;
}
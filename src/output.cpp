#include "ExVectrHAL/output.hpp"

#include "stdint.h"


bool VCTR::HAL::Output::writeByte(uint8_t byte) {
    return writeData(&byte, 1) == 1;
}
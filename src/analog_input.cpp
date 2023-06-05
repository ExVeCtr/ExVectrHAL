#include "ExVectrHAL/analog_input.hpp"

#include "stdint.h"


bool VCTR::HAL::AnalogInput::readValue(float& value) {
    return readValue(&value, 1) == 1;
}
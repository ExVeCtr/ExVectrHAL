#include "ExVectrHAL/analog_output.hpp"

#include "stdint.h"


bool VCTR::HAL::AnalogOutput::writeValue(float value) {
    return writeValue(&value, 1) == 1;
}
#include "stdint.h"

#include "ExVectrHAL/pin_dac.hpp"

namespace VCTR
{

    namespace HAL
    {

        PinDAC::PinDAC(int32_t pin) : pin_(pin) {}

        int32_t PinDAC::getPin()
        {
            return pin_;
        }

    };

}
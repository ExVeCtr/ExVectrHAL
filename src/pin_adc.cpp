#include "stdint.h"

#include "ExVectrHAL/pin_adc.hpp"

namespace VCTR
{

    namespace HAL
    {

        PinADC::PinADC(int32_t pin) : pin_(pin) {}

        int32_t PinADC::getPin()
        {
            return pin_;
        }

    };

}
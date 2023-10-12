#include "stdint.h"

#include "ExVectrHAL/pin_gpio.hpp"

namespace VCTR
{

    namespace HAL
    {

        PinGPIO::PinGPIO(int32_t pin) : pin_(pin) {}

        int32_t PinGPIO::getPin()
        {
            return pin_;
        }

    };

}
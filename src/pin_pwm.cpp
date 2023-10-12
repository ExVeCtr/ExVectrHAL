#include "stdint.h"

#include "ExVectrHAL/pin_pwm.hpp"

namespace VCTR
{

    namespace HAL
    {

        PinPWM::PinPWM(int32_t pin) : pin_(pin) {}

        int32_t PinPWM::getPin()
        {
            return pin_;
        }

    };

}
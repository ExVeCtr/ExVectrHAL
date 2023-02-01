#ifndef EXVECTRHAL_PINPWM_H
#define EXVECTRHAL_PINPWM_H

#include "stdint.h"


namespace VCTR
{

namespace Interface
{

    /**
     * @brief Interface for GPIO pins.
    */
    class HAL_PinPWM
    {
    public:

        virtual ~HAL_PinPWM() {}


        /**
         * Initialises PWM output.
         */
        virtual void init() = 0;

        /**
         * Enables or disables PWM output.
         * @param enable Enable or disable. Defaults to true.
         */
        virtual void enable(bool enable = true) = 0;

        /**
         * @returns Which pin this controls.
         */
        virtual uint32_t getPin() = 0;

        /**
         * Sets pin value. From 0 to 1.
         * @param value Which value to set pin to.
         */
        virtual void setPinValue(float value) = 0;

        /**
         * @returns current pin value. 0 to 1.
         */
        virtual float getPinValue() = 0;

        /**
         * Sets pwm frequency. From 0 to 1.
         * @param value Which frequency [Hz] to set PWM to.
         */
        virtual void setPinFrequency(uint32_t value) = 0;

        /**
         * @returns current PWM Frequency.
         */
        virtual uint32_t getPinFrequency() = 0;

    };

    
}

}

#endif
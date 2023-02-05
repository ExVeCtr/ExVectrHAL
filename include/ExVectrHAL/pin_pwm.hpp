#ifndef EXVECTRHAL_PINPWM_H
#define EXVECTRHAL_PINPWM_H

#include "stdint.h"


namespace VCTR
{

namespace HAL
{

    /**
     * @brief Interface for PWM pins.
    */
    class PinPWM
    {
    public:

        virtual ~PinPWM() {}

        /**
         * Initialises PWM output.
         * @param pin Which pin to control.
         */
        virtual void init(int32_t pin) = 0;

        /**
         * @returns Which pin this controls.
         */
        virtual int32_t getPin() = 0;

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
         * Sets pwm frequency.
         * @param value Which frequency [Hz] to set PWM to.
         */
        virtual void setPinFrequency(float value) = 0;

        /**
         * @returns current PWM Frequency.
         */
        virtual float getPinFrequency() = 0;

        /**
         * Sets pwm resolution.
         * @param value Which resolution [bits] to set PWM to.
         */
        virtual void setPinResolution(uint32_t value) = 0;

        /**
         * @returns current PWM resolution.
         */
        virtual uint32_t getPinResolution() = 0;

    };

    
}

}

#endif
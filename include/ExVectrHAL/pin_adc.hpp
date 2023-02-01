#ifndef EXVECTRHAL_PINADC_H
#define EXVECTRHAL_PINADC_H

#include "stdint.h"


namespace VCTR
{

namespace Interface
{

    /**
     * @brief Interface for any type of analog input. Usually ADCs.
    */
    class HAL_PinADC
    {
    public:

        virtual ~HAL_PinADC() {}

        /**
         * Initialises ADC input.
         * @param pin Which pin for input.
         */
        virtual void init(int32_t pin) = 0;

        /**
         * @returns Which pin used as input.
         */
        virtual int32_t getPin() = 0;

        /**
         * @returns current pin input. 0 to 1.
         */
        virtual float getPinValue() = 0;

        /**
         * Sets pin resolution. Will not affect input values.
         * @param value Which resolution the ADC will use.
         */
        virtual void setPinResolution(uint32_t value) = 0;

        /**
         * @returns current adc resolution.
         */
        virtual uint32_t setPinResolution() = 0;

    };

    
}

}

#endif
#ifndef EXVECTRHAL_PINDAC_H
#define EXVECTRPINDAC_H

#include "stdint.h"


namespace VCTR
{

namespace HAL
{

    /**
     * @brief Interface for any type of analog output. Usually DACs.
    */
    class PinDAC
    {
    public:

        virtual ~PinDAC() {}

        /**
         * Initialises DAC output.
         * @param pin Which pin for input.
         */
        virtual void init(int32_t pin) = 0;

        /**
         * @returns Which pin used as output.
         */
        virtual int32_t getPin() = 0;

        /**
         * Sets the output value from 0 to 1.
         * @param value Analog value
        */
        virtual void setPinValue(float value) = 0;

        /**
         * Sets pin resolution. Will not affect output values.
         * @param value Which resolution the DAC will use.
         */
        virtual void setPinResolution(uint32_t value) = 0;

        /**
         * @returns current DAC resolution.
         */
        virtual uint32_t setPinResolution() = 0;

    };

    
}

}

#endif
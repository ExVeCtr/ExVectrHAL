#ifndef EXVECTRHAL_PINADC_H
#define EXVECTRHAL_PINADC_H

#include "stdint.h"

namespace VCTR
{

    namespace HAL
    {

        /**
         * @brief Interface for any type of analog input. Usually ADCs.
         */
        class PinADC
        {
        protected:
            int32_t pin_;

        public:
            PinADC(int32_t pin);

            virtual ~PinADC() {}

            /**
             * Initialises ADC input.
             */
            virtual void init() = 0;

            /**
             * @returns current pin input.
             */
            virtual int32_t getPinValue() = 0;

            /**
             * Sets pin resolution.
             * @param value Which resolution the ADC will use.
             */
            virtual void setPinResolution(uint32_t value) = 0;

            /**
             * @returns current adc resolution.
             */
            virtual uint32_t getPinResolution() = 0;

            /**
             * @returns Which pin used as input.
             */
            virtual int32_t getPin();
        };

    }

}

#endif
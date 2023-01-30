#ifndef EXVECTRHAL_PINGPIO_H
#define EXVECTRHAL_PINGPIO_H

#include "stdint.h"


namespace VCTR
{

/**
 * Sets GPIO to be either input of output.
 */
enum class GPIO_IOMODE_t {
    NONE = 0, //Signals some error or that the state has not been set yet
    INPUT = 1,
    OUTPUT = 2,
};

namespace Interface
{

    /**
     * @brief Interface for GPIO pins.
    */
    class HAL_PinGPIO
    {
    public:

        virtual ~HAL_PinGPIO() {}

        /**
         * Initialises GPIO.
         */
        virtual void init() = 0;

        /**
         * @returns Which pin this controls.
         */
        virtual uint32_t getPin() = 0;

        /**
         * Sets pin value.
         * @param value Which value to set pin to.
         */
        virtual void setPinValue(bool value) = 0;

        /**
         * @returns current pin value.
         */
        virtual bool getPinValue() = 0;

        /**
         * Sets pin to given mode. Input/output.
         * @param mode Which mode to set pin to.
         */
        virtual void setPinMode(GPIO_IOMODE_t mode) = 0;

        /**
         * @returns current pin mode.
         */
        virtual GPIO_IOMODE_t getPinMode() = 0;

        /**
         * Sets pin to use given pullup or pulldown resistor or to remove.
         * 1 is pullup, 0 none, -1 pulldown.
         * @param pull Which pull mode to set pin to.
         */
        virtual void setPinPull(int pull) = 0;

        /**
         * 1 is pullup, 0 none, -1 pulldown.
         * @returns current pin pullmode.
         */
        virtual int getPinPull() = 0;

    };

    
}

}

#endif
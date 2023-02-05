#ifndef EXVECTRHAL_PINGPIO_H
#define EXVECTRHAL_PINGPIO_H

#include "stdint.h"


namespace VCTR
{

/**
 * Sets GPIO to be either input of output.
 */
enum class GPIO_IOMODE_t {
    IOMODE_NONE = 0, //Signals some error or that the state has not been set yet
    IOMODE_INPUT = 1,
    IOMODE_OUTPUT = 2,
};

/**
 * Sets GPIO pin to have input pullup or pulldown. 
 */
enum class GPIO_PULL_t {
    PULL_NONE = 0, //Signals some error or that the state has not been set yet
    PULL_UP = 1,
    PULL_DOWN = 2,
};

namespace HAL
{

    /**
     * @brief Interface for GPIO pins.
    */
    class PinGPIO
    {
    public:

        virtual ~PinGPIO() {}

        /**
         * Initialises GPIO.
         * @param pin Which pin to control.
         */
        virtual void init(int32_t pin, GPIO_IOMODE_t mode) = 0;

        /**
         * @returns Which pin this controls.
         */
        virtual int32_t getPin() = 0;

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
        virtual void setPinPull(GPIO_PULL_t pull) = 0;

        /**
         * 1 is pullup, 0 none, -1 pulldown.
         * @returns current pin pullmode.
         */
        virtual GPIO_PULL_t getPinPull() = 0;

    };

    
}

}

#endif
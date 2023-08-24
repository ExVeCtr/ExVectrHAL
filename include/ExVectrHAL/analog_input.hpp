#ifndef EXVECTRHAL_ANALOGINPUT_H
#define EXVECTRHAL_ANALOGINPUT_H

#include "stddef.h"
#include "stdint.h"

#include "io_types.hpp"
#include "io_params.hpp"


namespace VCTR
{

namespace HAL
{

    /**
     * @brief Interface class for input stuff, mainly digital communication.
    */
    class AnalogInput
    {
    private:
    public:

        virtual ~AnalogInput() {}; //Virtual because this will be inhereted from.

        /**
         * @brief Gets the type of input this is.
         * @return IO_TYPE_t enum.
         */
        virtual HAL::IO_TYPE_t getInputType() const = 0;

        /**
         * @brief Changes given parameter. 
         * @param param What parameter to change.
         * @param value What to change parameter to.
         * @return True if successfull and parameter is supported.
         */
        virtual bool setInputParam(HAL::IO_PARAM_t param, int32_t value) = 0;

        /**
         * @returns the number of values available to read at the moment.
        */
        virtual size_t readable() = 0;

        /**
         * @brief Reads the data and places it into the given data pointer.
         * @param value Pointer to where to place read data.
         * @param size Max number of values to place into value buffer.
         * 
         * @return number of values actually read and placed into data pointer.
        */
        virtual size_t readValue(float* values, size_t size) = 0;

        /**
         * @brief reads a single value. 
         * @param value Reference to the value to receive the read value.
         * @returns true if successfull, false otherwise
        */
        virtual bool readValue(float& value);

    };


}   

}

#endif
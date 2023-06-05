#ifndef EXVECTRHAL_ANALOGOUTPUT_H
#define EXVECTRHAL_ANALOGOUTPUT_H

#include "stdint.h"
#include "stddef.h"

#include "io_types.hpp"
#include "io_params.hpp"


namespace VCTR
{

namespace HAL
{

    /**
     * @brief Interface class for output stuff, mainly digital communication.
    */
    class AnalogOutput
    {
    private:
    public:

        virtual ~AnalogOutput() {}; //Virtual because this will be inhereted from

        /**
         * @brief Gets the type of bus this is.
         * @return IO_TYPE_t enum.
         */
        virtual HAL::IO_TYPE_t getOutputType() const = 0;

        /**
         * @brief Changes given parameter. 
         * @param param What parameter to change.
         * @param value What to change parameter to.
         * @return True if successfull and parameter is supported.
         */
        virtual bool setOutputParam(HAL::IO_PARAM_t param, int32_t value) = 0;

        /**
         * @returns number of values that can be written at the moment. -1 means no limit to data size.
        */
        virtual int32_t writable() = 0;

        /**
         * @brief Writes the values from values pointer.
         * @param values Pointer to data.
         * @param size Number of value to output.
         * 
         * @return number of values actually written.
        */
        virtual size_t writeValue(const float* values, size_t size) = 0;

        /**
         * @brief writes a single value. 
         * @param value Value to be written to output.
         * @returns true if successfull, false otherwise
        */
        virtual bool writeValue(float value);

    };


}   

}

#endif
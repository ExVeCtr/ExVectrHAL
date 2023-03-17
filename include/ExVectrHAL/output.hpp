#ifndef EXVECTRHAL_OUTPUT_H
#define EXVECTRHAL_OUTPUT_H

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
    class Output
    {
    private:
    public:

        virtual ~Output() {}; //Virtual because this will be inhereted from

        /**
         * @brief Gets the type of bus this is.
         * @return IO_TYPE_t enum.
         */
        virtual IO_TYPE_t getOutputType() const = 0;

        /**
         * @brief Changes given parameter. 
         * @param param What parameter to change.
         * @param value What to change parameter to.
         * @return True if successfull and parameter is supported.
         */
        virtual bool setOutputParam(IO_PARAM_t param, int32_t value) = 0;

        /**
         * @returns number of bytes that can be written. -1 means no limit to data size.
        */
        virtual int32_t writable() = 0;

        /**
         * @brief Writes the data from data pointer.
         * @param data Pointer to data.
         * @param bytes Number of bytes to output.
         * @param endTransfer Set to false if doing mulitple writes. Last write should have endTransfer set to true.
         * 
         * @return number of bytes actually written.
        */
        virtual size_t writeData(const void* data, size_t size, bool endTransfer = true) = 0;

        /**
         * @brief writes a single byte. 
         * @param byte Byte to be written to output.
         * @param endTransfer Set to false if doing mulitple writes. Last write should have endTransfer set to true.
         * @returns true if successfull, false otherwise
        */
        bool writeByte(uint8_t byte, bool endTransfer = true);

    };


}   

}

#endif
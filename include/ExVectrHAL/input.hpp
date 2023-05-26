#ifndef EXVECTRHAL_INPUT_H
#define EXVECTRHAL_INPUT_H

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
    class Input
    {
    private:
    public:

        virtual ~Input() {}; //Virtual because this will be inhereted from.

        /**
         * @brief Gets the type of bus this is.
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
         * @returns the number of bytes available to read at the moment. Or 1 or 0 for boolean.
        */
        virtual size_t readable() = 0;

        /**
         * @brief Reads the data and places it into the given data pointer.
         * @param data Pointer to where to place read data.
         * @param bytes Number of bytes to read. Will be limited to this number.
         * @param endTransfer Set to false if doing mulitple reads. Last read should have endTransfer set to true.
         * 
         * @return number of bytes actually read and placed into data pointer.
        */
        virtual size_t readData(void* data, size_t size, bool endTransfer = true) = 0;

        /**
         * @brief reads a single byte. 
         * @param byte Reference to the byte to receive the read byte.
         * @param endTransfer Set to false if doing mulitple reads. Last read should have endTransfer set to true.
         * @returns true if successfull, false otherwise
        */
        bool readByte(uint8_t& byte, bool endTransfer = true);

    };


}   

}

#endif
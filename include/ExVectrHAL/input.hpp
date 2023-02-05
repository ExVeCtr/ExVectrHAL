#ifndef EXVECTRHAL_INPUT_H
#define EXVECTRHAL_INPUT_H

#include "stddef.h"
#include "stdint.h"


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

        virtual ~Input() {}; //Virtual because this will be inhereted from

        /**
         * @returns the number of bytes available to read. Or 1 or 0 for boolean.
        */
        virtual size_t readable() = 0;

        /**
         * @brief Reads the data and places it into the given data pointer.
         * @param data Pointer to where to place read data.
         * @param bytes Number of bytes to read. Will be limited to this number.
         * 
         * @return number of bytes actually read and placed into data pointer.
        */
        virtual size_t readData(void* data, size_t size) = 0;

        /**
         * @brief reads a single byte. 
         * @param byte Reference to the byte to receive the read byte.
         * @returns true if successfull, false otherwise
        */
        bool readByte(uint8_t& byte);

    };


}   

}

#endif
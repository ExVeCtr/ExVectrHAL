#ifndef EXVECTRHAL_OUTPUT_H
#define EXVECTRHAL_OUTPUT_H

#include "stdint.h"


namespace VCTR
{

namespace Interface
{

    /**
     * @brief Interface class for output stuff, mainly digital communication.
    */
    class HAL_Output
    {
    private:
    public:

        virtual ~HAL_Output() {}; //Virtual because this will be inhereted from

        /**
         * @returns number of bytes that can be written. Usually implemented as boolean with 1 or 0.
        */
        virtual size_t writable() = 0;

        /**
         * @brief Writes the data from data pointer.
         * @param data Pointer to data.
         * @param bytes Number of bytes to output.
         * 
         * @return number of bytes actually written.
        */
        virtual size_t writeData(const void* data, size_t size) = 0;

        /**
         * @brief writes a single byte. 
         * @param byte Reference to the byte to receive the write byte.
         * @returns true if successfull, false otherwise
        */
        bool writeByte(uint8_t& byte) {
            return writeData(&byte, 1) == 1;
        }

    };


}   

}

#endif
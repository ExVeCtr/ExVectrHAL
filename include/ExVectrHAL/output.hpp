#ifndef EXVECTRHAL_OUTPUT_H
#define EXVECTRHAL_OUTPUT_H

#include "stdint.h"
#include "stddef.h"


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
         * @returns number of bytes that can be written. -1 means no limit to data size.
        */
        virtual int32_t writable() = 0;

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
         * @param byte Byte to be written to output.
         * @returns true if successfull, false otherwise
        */
        bool writeByte(uint8_t byte);

    };


}   

}

#endif
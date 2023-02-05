#ifndef EXVECTRHAL_IO_H
#define EXVECTRHAL_IO_H

#include "stdint.h"
#include "stddef.h"

#include "input.hpp"
#include "output.hpp"


namespace VCTR
{

namespace HAL
{
    	
    /**
     * @brief   Abstract class for any type of IO. Implements a few useful functions. 
     *          All bus types like I2C, SPI, CAN etc. should use this interface. Even a wireless network datalink layer.
    */
    class IO: public Input, public Output
    {
    public:

        virtual ~IO() {}

        /**
         * @brief writes bytes then reads bytes to IO. Usefull for stuff like I2C communications with sensors.
         * @param writeBuf Pointer to data to write.
         * @param readBuf Pointer to data to read to.
         * @param writeSize Number of bytes to write.
         * @param readSize Number of bytes to read.
         * 
         * @return true if writing and reading was successfull.
        */
        virtual bool writeRead(const void* writeBuf, void* readBuf, size_t writeSize, size_t readSize) {

            size_t numWrite = writeData(writeBuf, writeSize);
            size_t numRead = readData(readBuf, readSize);

            return numWrite == writeSize && numRead == readSize;

        }

    };

    
}

}

#endif
#ifndef EXVECTRHAL_BUSDEVICE_H
#define EXVECTRHAL_BUSDEVICE_H

#include "stdint.h"
#include "stddef.h"

#include "io_types.hpp"
#include "io_params.hpp"

#include "digital_io.hpp"


namespace VCTR
{

namespace HAL
{

    /**
     * @brief Implements helping functions for devices connected to a bus.
    */
    class BusDevice
    {
    protected:
        DigitalIO *ioBus_ = nullptr;

        bool verifyWrite_ = false;

        uint8_t spiRWBit_ = 0;
        bool invertRWBit_ = false;

    public:

        BusDevice();

        /**
         * @brief Standard constructor.
         * @param ioBus Input/Output bus the device is connected to.
         * @param spiRWBit Bit to set to 1 when writing to the device and 0 when reading from the device.
         * @param invertRWBit If false then the spiRWBit will be set to 1 when reading and 0 when writing. If true then the opposite.
         * @param verifyWrite If true then after writting a byte to the device it will read it back and compare it to the original value. If they are not the same then the write is considered failed.
         */
        BusDevice(DigitalIO &ioBus, uint8_t spiRWBit = 0, bool invertRWBit = false, bool verifyWrite = false);

        /**
         * @brief Writes the given byte to the given register.
         * @param reg Register to write to.
         * @param byte Byte to write.
         * @return true if successful, false otherwise. Will return false if verifyWrite_ is true and the read back value is not the same as the written value.
         */
        bool writeReg(uint8_t reg, uint8_t byte);

        /**
         * @brief Writes the given bytes to the given register.
         * @param reg Register to write to.
         * @param bytes Pointer to bytes to write.
         * @param length Number of bytes to write.
         * @return true if successful, false otherwise. Will return false if verifyWrite_ is true and the read back value is not the same as the written value.
         */
        bool writeReg(uint8_t reg, uint8_t *bytes, size_t length);

        /**
         * @brief Reads a byte from the given register.
         * @param reg Register to read from.
         * @param byte Pointer to byte to read into.
         * @return true if successful, false otherwise.
         */
        bool readReg(uint8_t reg, uint8_t *byte);

        /**
         * @brief Reads bytes from the given register.
         * @param reg Register to read from.
         * @param bytes Pointer to bytes to read into.
         * @param length Number of bytes to read.
         * @return true if successful, false otherwise.
         */
        bool readReg(uint8_t reg, uint8_t *bytes, size_t length);

    };
    


}   

}

#endif
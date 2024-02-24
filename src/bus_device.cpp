#include "stdint.h"

#include "ExVectrCore/print.hpp"

#include "ExVectrHAL/bus_device.hpp"

namespace VCTR
{

    namespace HAL
    {

        BusDevice::BusDevice()
        {
            ioBus_ = nullptr;
        }

        BusDevice::BusDevice(DigitalIO &ioBus, int spiRWBit, bool invertRWBit, bool verifyWrite)
        {
            ioBus_ = &ioBus;
            spiRWBit_ = spiRWBit;
            invertRWBit_ = invertRWBit;
            verifyWrite_ = verifyWrite;
        }

        bool BusDevice::writeReg(uint8_t reg, uint8_t byte, bool verifyWrite)
        {
            return writeReg(reg, &byte, 1, verifyWrite);
        }

        bool BusDevice::writeReg(uint8_t reg, const uint8_t *bytes, size_t length, bool verifyWrite)
        {

            if (ioBus_ == nullptr)
            {
                LOG_MSG("ioBus is a nullptr. Give the constructor the iobus connected with the sensor!\n");
                return false;
            }

            uint8_t command = reg;

            if (spiRWBit_ >= 0) {

                if (invertRWBit_)
                {
                    command |= (1 << spiRWBit_);
                }
                else
                {
                    command &= (~(1 << spiRWBit_));
                }

            }

            if (!ioBus_->writeByte(reg, false))
            {
                LOG_MSG("failed to write command byte!\n");
                return false;
            }

            if (!ioBus_->writeData(bytes, length))
            {
                LOG_MSG("failed to write data bytes!\n");
                return false;
            }

            if (verifyWrite_ || verifyWrite)
            {
                uint8_t readByte = 0;
                if (!readReg(reg, &readByte))
                {
                    LOG_MSG("failed to read back written byte for verification!\n");
                    return false;
                }
                if (readByte != bytes[0])
                {
                    LOG_MSG("verification read back byte does not match written byte!\n");
                    return false;
                }
            }

            return true;
        }

        bool BusDevice::readReg(uint8_t reg, uint8_t *bytes, size_t length)
        {

            if (ioBus_ == nullptr)
            {
                LOG_MSG("ioBus is a nullptr. Give the constructor the iobus connected with the sensor!\n");
                return false;
            }

            uint8_t command = reg;
            if (ioBus_->getOutputType() == HAL::IO_TYPE_t::BUS_SPI)
            {
                if (invertRWBit_)
                {
                    command &= (~(1 << spiRWBit_));
                }
                else
                {
                    command |= (1 << spiRWBit_);
                }
            }

            if (!ioBus_->writeByte(command, false))
            {
                LOG_MSG("failed to write command byte!\n");
                return false;
            }

            if (!ioBus_->readData(bytes, length))
            {
                LOG_MSG("failed to read data bytes!\n");
                return false;
            }

            return true;
        }

    }

}
#include "stdint.h"

#include "ExVectrCore/print.hpp"

#include "ExVectrHAL/bus_device.hpp"


namespace VCTR
{

namespace HAL
{

    BusDevice::BusDevice() {
        ioBus_ = nullptr;
    }

    BusDevice::BusDevice(DigitalIO &ioBus, uint8_t spiRWBit, bool invertRWBit, bool verifyWrite) {
        ioBus_ = &ioBus;
        spiRWBit_ = spiRWBit;
        invertRWBit_ = invertRWBit;
        verifyWrite_ = verifyWrite;
    }

    bool BusDevice::writeReg(uint8_t reg, uint8_t byte) {
        return writeReg(reg, &byte, 1);
    }

    bool BusDevice::writeReg(uint8_t reg, uint8_t *bytes, size_t length) {

        if (ioBus_ == nullptr) {
            Core::printE("BusDevice writeReg(): ioBus is a nullptr. Give the constructor the iobus connected with the sensor!\n");
            return false;
        }

        uint8_t command = reg;
        if (invertRWBit_) {
            command |= (1 << spiRWBit_);
        } else {
            command &= (~(1 << spiRWBit_));
        }

        if (ioBus_->writeByte(command, false)) {
            Core::printE("BusDevice writeReg(): failed to write command byte!\n");
            return false;
        }

        if (ioBus_->writeData(bytes, length)) {
            Core::printE("BusDevice writeReg(): failed to write data bytes!\n");
            return false;
        }

        if (verifyWrite_) {
            uint8_t readByte = 0;
            if (readReg(reg, &readByte)) {
                Core::printE("BusDevice writeReg(): failed to read back written byte for verification!\n");
                return false;
            }
            if (readByte != *bytes) {
                Core::printE("BusDevice writeReg(): verification read back byte does not match written byte!\n");
                return false;
            }
        }

        return true;

    }

    bool BusDevice::readReg(uint8_t reg, uint8_t *byte) {
        return readReg(reg, byte, 1);
    }

    bool BusDevice::readReg(uint8_t reg, uint8_t *bytes, size_t length) {   

        if (ioBus_ == nullptr) {
            Core::printE("BusDevice readReg(): ioBus is a nullptr. Give the constructor the iobus connected with the sensor!\n");
            return false;
        }

        uint8_t command = reg;
        if (invertRWBit_) {
            command &= (~(1 << spiRWBit_));
        } else {
            command |= (1 << spiRWBit_);
        }

        if (ioBus_->writeByte(command, false)) {
            Core::printE("BusDevice readReg(): failed to write command byte!\n");
            return false;
        }

        if (ioBus_->readData(bytes, length)) {
            Core::printE("BusDevice readReg(): failed to read data bytes!\n");
            return false;
        }

        return true;

    }

}   

}
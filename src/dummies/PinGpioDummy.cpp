#include "ExVectrHAL/dummies/PinGpioDummy.hpp"

using namespace VCTR::Platform;

PinGPIODummy::PinGPIODummy(int32_t pin) : HAL::PinGPIO(pin) {}

void PinGPIODummy::init(HAL::GPIO_IOMODE_t mode) {
  ioMode_ = mode;
  pinPull_ = HAL::GPIO_PULL_t::PULL_NONE;
}

int32_t PinGPIODummy::getPin() { return pin_; }

void PinGPIODummy::setPinValue(bool value) {
  if (ioMode_ != HAL::GPIO_IOMODE_t::IOMODE_OUTPUT)
    return;
  if (currentValue_ != value) {
    currentValue_ = value;
  }
}

bool PinGPIODummy::getPinValue() { return currentValue_; }

void PinGPIODummy::setPinMode(HAL::GPIO_IOMODE_t mode) { ioMode_ = mode; }

VCTR::HAL::GPIO_IOMODE_t PinGPIODummy::getPinMode() { return ioMode_; }

void PinGPIODummy::setPinPull(HAL::GPIO_PULL_t pull) {}

VCTR::HAL::GPIO_PULL_t PinGPIODummy::getPinPull() { return pinPull_; }

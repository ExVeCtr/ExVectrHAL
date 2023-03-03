#ifndef EXVECTRHAL_BUSTYPES_H
#define EXVECTRHAL_BUSTYPES_H

namespace VCTR
{

    namespace HAL
    {
        enum class BUS_TYPE_t {
            BUS_OTHER = 0,
            BUS_I2C,
            BUS_SPI,
            BUS_UART,
            BUS_CAN
        };
    }

}

#endif
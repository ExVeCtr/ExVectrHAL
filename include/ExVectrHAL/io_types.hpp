#ifndef EXVECTRHAL_IOTYPES_H
#define EXVECTRHAL_IOTYPES_H

namespace VCTR
{

    namespace HAL
    {

        /**
         * @brief IO types. Type of IO e.g. SPI, I2C UART etc.
         */
        enum class IO_TYPE_t
        {
            BUS_OTHER = 0,
            BUS_I2C,
            BUS_SPI,
            BUS_UART,
            BUS_CAN
        };
    }

}

#endif
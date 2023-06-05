#ifndef EXVECTRHAL_IOPARAMS_H
#define EXVECTRHAL_IOPARAMS_H

namespace VCTR
{

    namespace HAL
    {

        /**
         * @brief IO parameter types. Used to set IO parameters.
         */
        enum class IO_PARAM_t
        {
            /// Usually frequency of bus. But could be baud in uart etc.
            SPEED = 0,
            /// SPI mode.
            SPI_MODE,
            /// SPI (Maybe other types too?) Most significant bit first if param true. Least sig. first if param false.
            MSB_FIRST,
            /// Max voltage of output for a 1.
            VOLTAGE_MAX,
            /// Min voltage of output for a 0.
            VOLTAGE_MIN
        };
    }

}

#endif
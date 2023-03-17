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
            PARAM_SPEED = 0,
            /// SPI mode.
            PARAM_SPIMODE,
            /// SPI (Maybe other types too?) Most significant bit first if param true. Least sig. first if param false.
            PARAM_MSBFIRST
        };
    }

}

#endif
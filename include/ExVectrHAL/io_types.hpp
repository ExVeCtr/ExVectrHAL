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
            BUS_I2C = 0,
            BUS_SPI,
            BUS_UART,
            BUS_CAN,
            //Topic used as base. Usually for testing using topicIO in ExVectrNetwork.
            TOPIC,
            //Used to signify unkown types. Anything equal or greater than this is ok other type
            OTHER //KEEP AT END.
        };
    }

}

#endif
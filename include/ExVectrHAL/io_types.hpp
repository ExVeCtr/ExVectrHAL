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
            ANALOG_PWM_O,
            ANALOG_PWM_I,
            ANALOG_DAC,
            ANALOG_ADC,
            ANALOG_HBRIDGE,
            ANALOG_TOUCH,
            DIGITAL_I,
            DIGITAL_O,
            // Topic used as base. Usually for testing using topicIO in ExVectrNetwork.
            TOPIC,
            // Used to signify unknown/special types. Anything equal or greater than this is some other type
            OTHER // KEEP AT END.
        };
    }

}

#endif
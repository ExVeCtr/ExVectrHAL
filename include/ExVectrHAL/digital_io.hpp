#ifndef EXVECTRHAL_DIGITALIO_H
#define EXVECTRHAL_DIGITALIO_H

#include "stdint.h"
#include "stddef.h"

#include "io_types.hpp"
#include "io_params.hpp"

#include "digital_input.hpp"
#include "digital_output.hpp"


namespace VCTR
{

namespace HAL
{

    /**
     * @brief Interface class for a digital IO.
    */
    class DigitalIO: public DigitalInput, public DigitalOutput
    {
    private:
    public:

        virtual ~DigitalIO() {}; //Virtual because this will be inhereted from

    };


}   

}

#endif
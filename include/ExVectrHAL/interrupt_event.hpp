#ifndef EXVECTRHAL_INTERRUPTEVENT_HPP
#define EXVECTRHAL_INTERRUPTEVENT_HPP

#include "stdint.h"

namespace VCTR
{

    namespace HAL
    {

        /**
         * @brief Interface for any kind of interrupt event. E.g. pin interrupt, timer interrupt etc.
         */
        class InterruptEvent
        {
        protected:
           

        public:

            virtual ~InterruptEvent() {}

            virtual void trigger() = 0;

        };

    }

}

#endif
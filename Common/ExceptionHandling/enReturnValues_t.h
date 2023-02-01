#ifndef _EN_RETURN_VALUES_T_
#define _EN_RETURN_VALUES_T_

#include "../Basic/cBasicTypes.h"

using namespace Common::Basic;

namespace Common{
    namespace ExceptionHandling{
        /**
         * @brief Enumeration of return values
         * 
         */
        typedef enum class enReturnValues: std::uint8_t{
            enReturnValues_ErrUnknown = CONST_ZEROU,
            enReturnValues_InputInconsistent,
            enReturnValues_SuccessWithNoValue,
            enReturnValues_SuccessNormal,
            enReturnValues_ErrInvalid,
        }enReturnValues_t;
    }
}

#endif /* _EN_RETURN_VALUES_T_ */

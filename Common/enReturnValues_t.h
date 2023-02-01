#ifndef _EN_RETURN_VALUES_T_
#define _EN_RETURN_VALUES_T_

#include "../Basic/cBasic.h"

namespace Common{
    typedef enum enReturnValues: std::uint8_t{
        enReturnValues_ErrUnknown = CONST_ZEROU,
        enReturnValues_InputInconsistent,
        enReturnValues_SuccessWithNoValue,
        enReturnValues_SuccessNormal,
        enReturnValues_ErrInvalid,
    }enReturnValues_t;
}

#endif /* _EN_RETURN_VALUES_T_ */

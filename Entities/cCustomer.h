#ifndef _C_CUSTOMER_H_
#define _C_CUSTOMER_H_

#include <string>

#include "../Common/Basic/cBasicTypes.h"

namespace Entities{
    /**
     * @brief Class implementation for customer
     * 
     */
    class cCustomer
    {
    public:
        /**
        * @brief Construct a new Customer object
        * 
        */
        cCustomer();
        /**
        * @brief Construct a new Customer object
        * 
        * @param i_strName 
        */
        cCustomer(const std::string& i_strName);

    private:
        /**
        * @brief String variable for customer name
        * 
        */
        std::string m_strName;
    };
}

#endif /* _C_CUSTOMER_H_ */
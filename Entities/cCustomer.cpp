#include "cCustomer.h"

using Entities::cCustomer;

cCustomer::cCustomer(){
    m_strName = CONST_EMPTY_STRING;
}

cCustomer::cCustomer(const std::string& i_strName){
    m_strName = i_strName;
}
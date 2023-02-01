#include "cCard.h"

using Entities::cCard;

cCard::cCard(){
    m_strNumber = CONST_EMPTY_STRING;
}

cCard::cCard(const std::string& i_strNumber, cAccount& i_oAccount){
    m_strNumber = i_strNumber;
    m_oAccount  = i_oAccount;
}

const cAccount cCard::getAccount(){
    return m_oAccount;
}

bool cCard::isBankCard(){
    std::string str = m_strNumber.substr(CONST_ZEROU,CONST_TWOU);
    return  str == BANK_CODE;
}
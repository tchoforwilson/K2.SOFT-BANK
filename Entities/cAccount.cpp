#include "cAccount.h"

using Entities::cAccount;

cAccount::cAccount(){
    m_u64Balance = CONST_ZEROU;
    m_strPin = CONST_EMPTY_STRING;
    m_strBiometric = CONST_EMPTY_STRING;
}

cAccount::cAccount(const std::string& i_strAccountNumber,const std::uint64_t& i_u64Balance, const std::string& i_strPin, const std::string i_strBiometric, const cCustomer& i_oCustomer)
{
    m_strAccountNumber = i_strAccountNumber;
    m_u64Balance = i_u64Balance;
    m_strPin = i_strPin;
    m_strBiometric = i_strBiometric;
    m_oCustomer = i_oCustomer;
}

const std::string cAccount::getAccountNumber(void) const{
    return m_strAccountNumber;
}

const std::uint64_t cAccount::getBalance(void) const{
    return m_u64Balance;
}

bool cAccount::isValidPin(const std::string& i_strPin){
    return m_strPin == i_strPin;
}

bool cAccount::isValidBiometric(const std::string& i_strBiometric)
{
    return m_strBiometric == i_strBiometric;
}

enReturnValues_t cAccount::withdraw(const std::uint64_t& i_d64Amount){
    enReturnValues_t eRetVal = enReturnValues_t::enReturnValues_ErrUnknown;
    if(i_d64Amount < CONST_ZEROU){
        eRetVal = enReturnValues_t::enReturnValues_InputInconsistent;
    }
    if(i_d64Amount > m_u64Balance){
        eRetVal = enReturnValues_t::enReturnValues_SuccessWithNoValue;
    }
    if(eRetVal == enReturnValues_t::enReturnValues_ErrUnknown){
        m_u64Balance-=i_d64Amount;
        eRetVal = enReturnValues_t::enReturnValues_SuccessNormal;
    }
    return eRetVal;
}
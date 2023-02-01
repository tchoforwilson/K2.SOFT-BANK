#ifndef _C_ACCOUNT_H_
#define _C_ACCOUNT_H_

#include <string>

#include "./../Common/Basic/cBasicTypes.h"
#include "./../Common/ExceptionHandling/enReturnValues_t.h"
#include "cCustomer.h"

using Entities::cCustomer;
using Common::ExceptionHandling::enReturnValues_t;
using namespace Common::Basic;

namespace Entities{

  /**
   * @brief Class implementation of Bank account in application
   * 
   */
  class cAccount
  {
  public:
    /**
    * @brief Construct a new c Account object
    * 
    */
      cAccount();
      /**
      * @brief Construct a new Account object
      * 
      * @param i_strAccountNumber 
      * @param i_u64Balance 
      * @param i_strPin 
      * @param i_strBiometric 
      * @param i_oCustomer 
      */
      cAccount(const std::string& i_strAccountNumber, const std::uint64_t& i_u64Balance, const std::string& i_strPin, const std::string i_strBiometric, const cCustomer& i_oCustomer);
      /**
      * @brief Get the Account Number object
      * 
      * @return const std::string 
      */
      const std::string getAccountNumber(void) const; 
      /**
      * @brief Get the Balance object
      * 
      * @return const std::uint64_t 
      */
      const std::uint64_t getBalance(void) const;
      /**
      * @brief Check if the provided account pin is valid,
      * compare the i_strPin parameter with the class m_strPin variable
      * 
      * @param i_strPin 
      * @return true  if the are the same
      * @return false if the are different
      */
      bool isValidPin(const std::string& i_strPin);
      /**
      * @brief Check if the provided biometric input is valid,
      compare the provided i_strBiometric with the class i_strBiometric
      * 
      * @param i_strBiometric 
      * @return true  if they are the same
      * @return false if they are different
      */
      bool isValidBiometric(const std::string& i_strBiometric);
      /**
      * @brief withdraw money from account balance, the i_s64Amount
      provided is deducted from the account m_u64Balance
      * 
      * @param i_s64Amount 
      * @return enReturnValues_t 
        -enReturnValues_InputInconsistent: if i_s64Amount provided is less than or equal zero
        -enReturnValues_SuccessWithNoValue: if the amount provided is greater than the balance
        -enReturnValues_SuccessNormal: if the withdrawal was successful
      */
      enReturnValues_t withdraw(const std::uint64_t& i_s64Amount);
  private:
      /**
      * @brief account number variable
      * To uniquely identify each account
      */
      std::string m_strAccountNumber;
      /**
      * @brief Account balance variable
      * serve as a the amount of money found in an account 
      * 
      */
      std::uint64_t m_u64Balance;
      /**
      * @brief Account pin variable
      * 
      */
      std::string m_strPin;
      /**
      * @brief Account biometric variable
      * 
      */
      std::string m_strBiometric;
      /**
      * @brief Account holder (customer)
      * The customer who owns the account
      */
      cCustomer m_oCustomer;
  };
}

#endif /* _C_ACCOUNT_H_ */
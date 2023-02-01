#ifndef _C_cCard_H_
#define _C_cCard_H_

#include <string>

#include "../Common/Basic/cBasicTypes.h"
#include "../Configurations/SoftConfig.h"
#include "cAccount.h"

using namespace Configurations;
using namespace Common::Basic;
using Entities::cAccount;

namespace Entities{

    /**
     * @brief Class implementation for user bank card
     * 
     */
    class cCard
    {
    public:
    /**
        * @brief Construct a new cCard object
        * 
        */
        cCard();
        /**
        * @brief Construct a new cCard object
        * 
        * @param i_strNumber -> cCard number
        * @param i_oAccount -> cCard account
        */
        cCard(const std::string& i_strNumber, cAccount& i_oAccount);

        /**
        * @brief Get the Account object
        * 
        * @return const Account 
        */
        const cAccount getAccount();

        /**
        * @brief Method to check if a given cCard belongs to the bank,
        * this is done by verifying that the cCard number begins with "K2"
        * 
        * @return true if cCard number begins with "k2"
        * @return false if cCard number doesn't begins with "k2"
        */
        bool isBankCard();

    private:
        /**
        * @brief Variable for cCard number, uniquely identifier one
        * cCard from the other, a K2.SOFT bank cCard begins with "K2"
        * 
        */
        std::string m_strNumber;

        /**
        * @brief TVariable for cCard account.
        * he account to which the cCard access,
        * 
        */
        cAccount m_oAccount;
    };
}

#endif /* _C_cCard_H_ */
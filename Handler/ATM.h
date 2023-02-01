#ifndef _C_ATM_H_
#define _C_ATM_H_

#include <string>
#include <exception>
#include <sstream>

#include "./../Configurations/SoftConfig.h"
#include "./../Common/Basic/cBasicTypes.h"
#include "./../Entities/cAccount.h"

using Entities::cAccount;
using Common::ExceptionHandling::enReturnValues_t;

namespace Handler{
    namespace ATM
    {

        /**
        * @brief Method to check if withdrawal attempt is three(3) times
        * 
        * @param i_u8Count counter
        * @return true withdrawal attempt is 3 times
        * @return false withdrawal attempt is not yet 3 times
        */
        bool isCount(const std::uint8_t& i_u8Count){
            return i_u8Count == CONST_THREEU;
        }
        
        /**
        * @brief ATM method to initiate withdrawal from account
        * 
        * @param i_oAccount  -> Account where withdrawal is initiated 
        * @param i_strType -> Login method for withdrawal (PIN/BIOMETRIC)
        */
        void doWithDrawal(cAccount& i_oAccount,const std::string& i_strType)
        {
            std::string i_strCode;
            std::uint8_t i_u8Count;
            std::ostringstream ss;

            ss << "Enter " << i_strType << " : ";
            if(i_strType == TYPE_PIN){
                while(!i_oAccount.isValidPin(i_strCode) && !isCount(i_u8Count)){
                    std::cout << ss.str();
                    std::cin >> i_strCode;
                    i_u8Count++;
                    if(!i_oAccount.isValidPin(i_strCode) && !isCount(i_u8Count)){
                        std::cout << "Invalid PIN, Try again!!!" << std::endl;
                    }
                } 
            }
            if(i_strType == TYPE_BIO){
                while(!i_oAccount.isValidBiometric(i_strCode) && !isCount(i_u8Count)){
                    std::cout << ss.str();
                    std::cin >> i_strCode; 
                    i_u8Count++;
                    if(!i_oAccount.isValidBiometric(i_strCode) && !isCount(i_u8Count)){
                        std::cout << "Invalid Biometric, Try again!!!" << std::endl;
                    }
                }
            }
            if(isCount(i_u8Count)){
                std::cout << "Card swallowed" << std::endl;
                exit(0);
            }
            std::cout << "\n\n";
            std::cout << "========================" << std::endl;
            enReturnValues_t eRetVal = enReturnValues_t::enReturnValues_ErrUnknown;
            while(eRetVal != enReturnValues_t::enReturnValues_SuccessNormal)
            {
                try{
                    double d64Amount;
                    std::cout << "Enter amount to withdraw: " << std::endl;
                    std::cin >> d64Amount;

                    eRetVal = i_oAccount.withdraw(d64Amount);

                    if(eRetVal == enReturnValues_t::enReturnValues_InputInconsistent) 
                        std::cout << "Invalid input negative amount: " << d64Amount << std::endl;
                    if(eRetVal == enReturnValues_t::enReturnValues_SuccessWithNoValue)
                        std::cout << "Insufficient funds: Balance " << i_oAccount.getBalance() << std::endl;
                }catch(std::exception& e){
                    std::cout << "Something went wrong!!!" << std::endl;
                    exit(0);
                }
            }
            std::cout << "\n";
            std::cout << "===============================" << std::endl;
            std::cout << "*********SUCCESSFUL************"<< std::endl;
            std::cout << "===============================" << std::endl;
            std::cout << "New Balance: " << i_oAccount.getBalance() << std::endl;
        }

    };
}

#endif /* _C_ATM_H_ */
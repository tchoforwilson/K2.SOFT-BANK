#include <iostream>
#include <string>
#include <map>
#include <exception>

#include "Common/Basic/cBasicTypes.h"
#include "Common/ExceptionHandling/enReturnValues_t.h"

#include "Entities/cCustomer.h"
#include "Entities/cAccount.h"
#include "Entities/cCard.h"

#include "Handler/ATM.h"

using namespace Common::Basic;
using namespace Entities;
using namespace Handler::ATM;
using Common::ExceptionHandling::enReturnValues_t;


int main(){
    cCustomer customers[3] = {cCustomer("Mary James"), cCustomer("Annie Gray"), cCustomer("Jackie Brown")};
    cAccount accounts[3] = {cAccount("0001",5000000, "1234","1001",customers[0]),cAccount("0002",8000000, "2478","1101",customers[1]),cAccount("0003",2000000, "1357","1011",customers[2])};
    std::map<std::string, cCard> cards = {std::make_pair("K2A8900",cCard("K2A8900",accounts[0])), std::make_pair("MK9012",cCard("MK9012",accounts[1])),std::make_pair("K2A3401",cCard("K2A3401",accounts[2]))};

    std::string strNumber;
    std::cout << "======================================" << std::endl;
    std::cout << "*************K2.SOFT BANK*************" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Enter Card Number:";
    std:: cin >> strNumber;
    try{
        cCard oCard = cards.at(strNumber);
        cAccount oAccount = oCard.getAccount();
        if(oCard.isBankCard())
        {
            int u8Ans = CONST_ZEROU;
            while((u8Ans != 1 ) && (u8Ans != 2)){
                std::cout << "========================" << std::endl;
                std::cout << "*********LOGIN**********" << std::endl;
                std::cout << "========================" << std::endl;
                std::cout << "1. PIN" << std::endl;
                std::cout << "2. Biometric" << std::endl;
                std::cin >> u8Ans;
            }
            std::cout << "\n\n";
            std::cout << "======================================" << std::endl;
            switch(u8Ans){
                case CONST_ONEU:
                    doWithDrawal(oAccount,TYPE_PIN);
                break;
                case CONST_TWOU:
                    doWithDrawal(oAccount,TYPE_BIO);
                break;
                default:
                    std::cout << "Choose Login method" << std::endl;
            }
        }else{
            doWithDrawal(oAccount,TYPE_PIN);
        }
    }catch(std::exception& e){
        std::cout << "Invalid card!!!" << std::endl;
        std::cout << e.what() << std::endl;
    }
    return 0;
}
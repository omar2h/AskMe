/*
 * login_handler.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "login_handler.hpp"
#include "database_manager.hpp"

std::pair<User, bool> Login_handler::login()
{
    DbManager DB;
    std::pair<User, bool> userLoginPair;

    std::cout << "Please enter UserName and Password: ";
    std::cin >> userLoginPair.first.username >> userLoginPair.first.password;

    userLoginPair = DB.usersDb.get_user_login(userLoginPair.first);
    std::cout << "*******" << userLoginPair.first.username << '\n';
    return userLoginPair;
}

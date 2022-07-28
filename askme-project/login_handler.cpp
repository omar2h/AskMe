/*
 * login_handler.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

/* ****** includes ******** */
#include "login_handler.hpp"
#include "database_manager.hpp"

bool Login_handler::login(User &user)
{
    DbManager DB;
    std::string username, password;
    std::pair<User, bool> userLoginPair;

    std::cout << "Please enter UserName and Password: ";
    std::cin >> username >> password;

    userLoginPair = DB.usersDb.get_user_login(username, password);
    if (userLoginPair.second)
    {
        user = userLoginPair.first;
        return 1;
    }
    return 0;
}

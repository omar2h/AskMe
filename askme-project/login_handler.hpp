/*
 * login_handler.hpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#ifndef LOGIN_HANDLER_HPP_
#define LOGIN_HANDLER_HPP_
#include "user.hpp"

#include <iostream>
#include <utility>

struct Login_handler
{
    std::pair<User, bool> login();
    int user_exists(User user);
};




#endif /* LOGIN_HANDLER_HPP_ */

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
    /**
     * logs in user
     *
     * @param non
     * @return pair of user and whether successfully logged in or not
     */
    std::pair<User, bool> login();
};

#endif /* LOGIN_HANDLER_HPP_ */

/*
 * login_handler.hpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#ifndef LOGIN_HANDLER_HPP_
#define LOGIN_HANDLER_HPP_
#include "user.hpp"

/* ****** includes ******** */
#include <iostream>
#include <utility>

struct Login_handler
{
    /**
     * logs in user
     *
     * @param non
     * @return bool indicating successful login or not
     */
    bool login(User &);
};

#endif /* LOGIN_HANDLER_HPP_ */

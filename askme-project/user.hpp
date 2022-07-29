/*
 * user.hpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#ifndef USER_HPP_
#define USER_HPP_

#include <string>

struct User
{
    /* id, username, password, allow anon questions bool */
    int id;
    std::string username, password;
    bool allowAnonQs;
};

#endif /* USER_HPP_ */

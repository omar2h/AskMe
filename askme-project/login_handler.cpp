/*
 * login_handler.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "login_handler.hpp"

#include <fstream>
#include <sstream>

std::pair<User, bool> Login_handler::user_exists(User user)
{
    int id;
    std::string username, password;
    bool allowAnonQs;

    std::pair<User, bool> userExistPair;
    userExistPair.second = 0;
    std::string path = "users.txt";
    std::fstream file_handler(path.c_str());

    if (file_handler.fail())
    {
        std::cout << "\n -------- Can't open file -----------\n\n";
        return userExistPair;
    }

    std::string line;

    while (getline(file_handler, line))
    {
        std::stringstream iss(line);
        iss >> id >> username >> password >> allowAnonQs;

        if (user.username == username && user.password == password)
        {
            userExistPair.first = user;
            userExistPair.first.id = id, userExistPair.first.allowAnonQs = allowAnonQs;
            userExistPair.second = 1;
            return userExistPair;
        }
    }
    return userExistPair;
}

std::pair<User, bool> Login_handler::login()
{
    std::pair<User, bool> userLoginPair;

    std::cout << "Please enter UserName and Password: ";
    std::cin >> userLoginPair.first.username >> userLoginPair.first.password;

    userLoginPair = user_exists(userLoginPair.first);
    return userLoginPair;
}

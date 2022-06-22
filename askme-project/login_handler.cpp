/*
 * login_handler.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */


#include "login_handler.hpp"

#include <fstream>
#include <sstream>

int Login_handler::user_exists(User user)
{
	int id;
	std::string username, password;
	std::string path = "users.txt";
	std::fstream file_handler(path.c_str());

    if (file_handler.fail())
    {
    	std::cout << "\n -------- Can't open file -----------\n\n";
        return -1;
    }

    std::string line;

    while (getline(file_handler, line))
    {
    	std::stringstream iss(line);
        iss >> id >> username >> password;

        if (user.username == username && user.password == password)
            return id;
    }
    return -1;
}

std::pair<User, bool> Login_handler::login()
{
    std::pair<User, bool> userBool;
    userBool.second = 1;

    std::cout << "Please enter UserName and Password: ";
    std::cin >> userBool.first.username >> userBool.first.password;

    int id = user_exists(userBool.first);
    if (id != -1){
    	userBool.first.id = id;
        return userBool;
    }
    else
    {
        userBool.second = 0;
        return userBool;
    }
}


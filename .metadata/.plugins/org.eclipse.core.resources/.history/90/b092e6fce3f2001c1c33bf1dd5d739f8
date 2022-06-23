/*
 * signup_handler.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */
#include "signup_handler.hpp"
#include "user.hpp"
#include "database_manager.hpp"
#include <iostream>

bool Signup_handler::signup()
{
	User user;
	DbManager DB;
	std::string username, password;
	char ans;

	std::cout << "Please enter UserName and Password: ";
	std::cin >> user.username >> user.password;
	do
	{
		std::cout << "Allow anonymous questions? (y/n): ";
		std::cin >> ans;

	} while (ans != 'y' && ans != 'n');

	user.allowAnonQs = ans == 'y' ? 1 : 0;

	if (DB.usersDb.add_user(user))
	{
		std::cout << "\n---------------- Signed Up Successfully ------------- \n\n";
		return 1;
	}

	return 0;
}

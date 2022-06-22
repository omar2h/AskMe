/*
 * users_db.cpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#include "users_db.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

int UsersDb::generate_id()
{
	std::string path = "users.txt";
	std::fstream file_handler(path.c_str());

	if (file_handler.fail())
	{
		std::cout << "\n -------- Can't open file -----------\n\n";
		return 0;
	}

	std::string line;
	std::string idStr;
	int count = 1;
	if (file_handler.peek() == std::ifstream::traits_type::eof())
		return count;

	while (getline(file_handler, line))
	{
		std::istringstream iss(line);
		std::getline(iss, idStr, ',');
	}
	return stoi(idStr) + 1;
}

std::pair<User, bool> UsersDb::get_user(int id)
{
	User user;
	std::pair<User, bool> userPair;
	userPair.second = 0;

	std::string path = "users.txt";
	std::fstream file_handler(path.c_str());

	if (file_handler.fail())
	{
		std::cout << "\n -------- Can't open file -----------\n\n";
		return userPair;
	}

	std::string line;
	std::string idStr, allowAnonQsStr;
	while (getline(file_handler, line))
	{
		std::stringstream iss(line);
		std::getline(iss, idStr, ',');
		std::getline(iss, user.username, ',');
		std::getline(iss, user.password, ',');
		std::getline(iss, allowAnonQsStr, ',');

		if (stoi(idStr) == id)
		{
			user.id = stoi(idStr);
			user.allowAnonQs = stoi(allowAnonQsStr);
			userPair.first = user;
			userPair.second = 1;
			return userPair;
		}
	}
	return userPair;
}

std::pair<User, bool> UsersDb::get_user_login(User &user)
{
	std::string username, password;

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

	while (std::getline(file_handler, line))
	{
		std::string idStr, allowAnonQsStr;
		std::istringstream iss(line);

		std::getline(iss, idStr, ',');
		std::getline(iss, username, ',');
		std::getline(iss, password, ',');
		std::getline(iss, allowAnonQsStr, ',');

		if (user.username == username && user.password == password)
		{
			user.id = stoi(idStr);
			user.allowAnonQs = stoi(allowAnonQsStr);
			userExistPair.first = user;
			userExistPair.second = 1;
			return userExistPair;
		}
	}
	return userExistPair;
}

bool UsersDb::add_user(User user)
{
	user.id = generate_id();
	std::ofstream fout("users.txt", std::ios_base::app);

	if (fout.fail())
	{
		std::cout << "Can't open file\n";
		return 0;
	}

	fout << user.id << ',' << user.username << ',' << user.password << ',' << user.allowAnonQs << '\n';
	return 1;
}

void UsersDb::print()
{

	std::string path = "users.txt";
	std::fstream file_handler(path.c_str());

	if (file_handler.fail())
	{
		std::cout << "\n -------- Can't open file -----------\n\n";
		return;
	}

	std::string line;
	std::string idStr, allowAnonQsStr, username, password;

	while (getline(file_handler, line))
	{
		std::stringstream iss(line);
		std::getline(iss, idStr, ',');
		std::getline(iss, username, ',');
		std::getline(iss, password, ',');
		std::getline(iss, allowAnonQsStr, ',');
		std::cout << "ID: " << idStr << "\tUserName: " << username << '\n';
	}

	std::cout << '\n';
}

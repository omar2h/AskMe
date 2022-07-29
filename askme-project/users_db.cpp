/*
 * users_db.cpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#include "users_db.hpp"
#include "database_manager.hpp"

std::pair<User, bool> UsersDb::get_user(const int id)
{
	User user;
	DbManager dbManager;
	std::pair<User, bool> userPair;
	userPair.second = 0;

	const std::string path = USERSTXT_PATH;
	std::vector<std::string> lines;
	dbManager.read_file_lines(path, lines);

	for (auto &line : lines)
	{
		std::vector<std::string> v;
		dbManager.split_line_toVector(line, v, DELIMITER);

		if (stoi(v[ID]) == id)
		{
			user.id = stoi(v[ID]);
			user.allowAnonQs = stoi(v[ALLOW_ANON_Q]);
			userPair.first = user;
			userPair.second = 1;
			return userPair;
		}
	}
	return userPair;
}

std::pair<User, bool> UsersDb::get_user_login(std::string username, std::string password)
{
	DbManager dbManager;
	std::pair<User, bool> userExistPair;

	userExistPair.second = 0;
	const std::string path = USERSTXT_PATH;
	std::vector<std::string> lines;
	dbManager.read_file_lines(path, lines);

	for (auto &line : lines)
	{
		std::vector<std::string> v;
		dbManager.split_line_toVector(line, v, DELIMITER);

		if (username == v[USERNAME] && password == v[PASSWORD])
		{
			userExistPair.first.id = stoi(v[ID]);
			userExistPair.first.allowAnonQs = stoi(v[ALLOW_ANON_Q]);
			userExistPair.second = 1;
			return userExistPair;
		}
	}
	return userExistPair;
}

bool UsersDb::add_user(User &user)
{
	DbManager dbManager;
	user.id = dbManager.generate_id(USERSTXT_PATH);
	std::vector<std::string> lines;
	std::string line = std::to_string(user.id) + DELIMITER + user.username + DELIMITER + user.password + DELIMITER + std::to_string(user.allowAnonQs) + '\n';
	lines.push_back(line);
	return dbManager.write_file_lines(USERSTXT_PATH, lines, true);
}

void UsersDb::print()
{
	DbManager dbManager;
	const std::string path = "users.txt";
	std::vector<std::string> lines;
	dbManager.read_file_lines(path, lines);

	for (auto &line : lines)
	{
		std::vector<std::string> v;
		dbManager.split_line_toVector(line, v, DELIMITER);
		std::cout << "ID: " << v[ID] << "\tUserName: " << v[USERNAME] << '\n';
	}
	std::cout << '\n';
}

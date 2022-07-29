/*
 * database_manager.cpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

/* ****** includes ******** */
#include "database_manager.hpp"

#include <fstream>
#include <sstream>

void DbManager::read_file_lines(std::string path, std::vector<std::string> &lines)
{
	std::fstream file_handler(path.c_str());
	if (file_handler.fail())
	{
		std::cout << "\n -------- Can't open file -----------\n\n";
		return;
	}

	std::string line;
	/* check if file is empty */
	if (file_handler.peek() == std::ifstream::traits_type::eof())
	{
		file_handler.close();
		return;
	}

	while (getline(file_handler, line))
	{
		if (line.size() == 0)
			continue;
		lines.push_back(line);
	}

	file_handler.close();
}

bool DbManager::write_file_lines(std::string path, std::vector<std::string> &lines, bool append = true)
{
	auto status = std::ios::in | std::ios::out | std::ios::app;

	if (!append)
		status = std::ios::in | std::ios::out | std::ios::trunc; // overwrite

	std::fstream file_handler(path.c_str(), status);

	if (file_handler.fail())
	{
		std::cout << "\n\nERROR: Can't open the file\n\n";
		return false;
	}
	for (auto line : lines)
		file_handler << line << "\n";

	file_handler.close();
	return true;
}

void DbManager::split_line_toVector(std::string line, std::vector<std::string> &v, const std::string del)
{
	int pos = 0;
	std::string substr;
	while ((pos = (int)line.find(del)) != -1)
	{
		substr = line.substr(0, pos);
		v.push_back(substr);
		line.erase(0, pos + (int)del.size());
	}
	v.push_back(line);
}

int DbManager::generate_id(const std::string path)
{
	std::vector<std::string> lines;
	read_file_lines(path, lines);

	std::vector<std::string> v;
	const int linesSize = (int)lines.size();
	if (linesSize)
	{
		split_line_toVector(lines[linesSize - 1], v, DELIMITER);
		return stoi(v[ID]) + 1;
	}
	return 1;
}

bool DbManager::check_user_exist(User &user)
{
	/* pair to store user and bool whether exists or not */
	std::pair<User, bool> uPair = usersDb.get_user(user.id);
	if (uPair.second)
	{
		user = uPair.first;
		return 1;
	}
	return 0;
}

bool DbManager::check_user_has_q(const int qId, const int uId)
{
	/* pair to store question and bool whether exist or not */
	std::pair<Question, bool> qPair = questionsDb.get_question(qId);
	if (!qPair.second)
		return 0;
	/* check if q toId is the same as user id signifying user received question*/
	if (qPair.first.toId != uId)
		return 0;
	return 1;
}

bool DbManager::check_user_from_to_q(const int qId, const int uId)
{
	std::pair<Question, bool> qPair = questionsDb.get_question(qId);
	if (!qPair.second)
		return 0;
	/* if question toId or fromId as user id */
	if (qPair.first.toId == uId || qPair.first.fromId == uId)
		return 1;
	return 0;
}

std::map<int, std::vector<Question>> DbManager::get_all_Qs_to_user(const int uId, std::map<int, std::vector<Question>> &mp)
{
	mp = questionsDb.get_to_user(uId);
	return mp;
}

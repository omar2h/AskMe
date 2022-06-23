/*
 * question_db.cpp
 *
 *  Created on: Jun 23, 2022
 *      Author: omarh
 */

#include "questions_db.hpp"

#include <fstream>
#include <sstream>

int QuestionsDb::generate_id()
{
	std::string path = "questions.txt";
	std::fstream file_handler(path.c_str());

	if (file_handler.fail())
	{
		std::cout << "\n -------- Can't open file -----------\n\n";
		return 0;
	}

	std::string line;
	std::string idStr;

	if (file_handler.peek() == std::ifstream::traits_type::eof())
		return 1;

	while (getline(file_handler, line))
	{
		std::istringstream iss(line);
		std::getline(iss, idStr, ',');
		std::cout << idStr << '\n';
	}
	return stoi(idStr) + 1;
}

bool QuestionsDb::add_question(Question &q)
{
	q.id = generate_id();
	std::ofstream fout("questions.txt", std::ios_base::app);

	if (fout.fail())
	{
		std::cout << "Can't open file\n";
		return 0;
	}

	fout << q.id << ',' << q.threadId << ',' << q.fromId << ',' << q.toId << ',' << q.answered << ',' << q.text << ',' << q.ans << '\n';
	return 1;
}

std::pair<Question, bool> QuestionsDb::get_question(const int id)
{
	Question q;
	std::pair<Question, bool> qPair;
	qPair.second = 0;

	std::string path = "questions.txt";
	std::fstream file_handler(path.c_str());

	if (file_handler.fail())
	{
		std::cout << "\n -------- Can't open file -----------\n\n";
		return qPair;
	}

	std::string line;
	std::string idStr, thrdStr, toStr, fromStr, ansdStr;
	while (getline(file_handler, line))
	{
		std::stringstream iss(line);
		std::getline(iss, idStr, ',');
		std::getline(iss, thrdStr, ',');
		std::getline(iss, fromStr, ',');
		std::getline(iss, toStr, ',');
		std::getline(iss, ansdStr, ',');
		std::getline(iss, q.text, ',');
		std::getline(iss, q.ans, ',');

		if (stoi(idStr) == id)
		{
			q.id = stoi(idStr);
			q.threadId = stoi(thrdStr);
			q.toId = stoi(toStr);
			q.fromId = stoi(fromStr);
			q.answered = stoi(ansdStr);
			qPair.first = q;
			qPair.second = 1;
			return qPair;
		}
	}
	return qPair;
}
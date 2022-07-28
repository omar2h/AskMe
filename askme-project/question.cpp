/*
 * question.cpp
 *
 *  Created on: Jun 25, 2022
 *      Author: omarh
 */

#include "question.hpp"

/* 1- initialize empty string space */
/* 2- for loop to increment space with spaces */
/* 3- if space.size() more than 2 add 2 spaces to align children. for readability */
/* 4- print for anon or not */
void Question::print_child(int spaces)
{
	std::string space = "";
	for (int i = 0; i < spaces; i++)
		space += " ";
	if ((int)space.size() > 2)
		space += "  ";
	if (anon)
	{
		std::cout << space << "|\n";
		std::cout << space << "==";
		std::cout << "Question(id:" << id << "): " << text << '\n';
		std::cout << space << "  Answer: " << ans << '\n';
	}
	else
	{
		std::cout << space << "|\n";
		std::cout << space << "==";
		std::cout << "Question(id:" << id << ") from user(id:" << fromId << "): " << text << '\n';
		std::cout << space << "  Answer: " << ans << '\n';
	}
}

/* 1- print first item in vector as a child */
/* 2- check for following items in vector if any print as child and increase spaces by 2 */
/* 3- check for each child if it has children then print 'em */
void print_children(std::vector<Question> qv, std::map<int, std::vector<Question>> &mp, int spaces)
{
	qv[0].print_child(spaces);
	for (int i = 1; i < (int)qv.size(); i++)
	{
		qv[i].print_child(spaces + 2);
		if (mp[qv[i].id].size() > 1)
			print_children(mp[qv[i].id], mp, spaces - 2);
	}
}

void Question::print() const
{
	if (anon)
	{
		std::cout << "Question(id:" << id << "): " << text << '\n';
		std::cout << "Answer: " << ans << '\n';
	}
	else
	{
		std::cout << "Question(id:" << id << ") from user(id:" << fromId << "): " << text << '\n';
		std::cout << "Answer: " << ans << '\n';
	}
}

void Question::print_asked() const
{
	if (anon)
	{
		std::cout << "Question(id:" << id << ") to user(id:" << toId << "): " << text << "\n";
		std::cout << "Answer: " << ans << "\n";
	}
	else
	{
		std::cout << "Question(id:" << id << ") !AQ to user(id:" << toId << "): " << text << "\n";
		std::cout << "Answer: " << ans << "\n";
	}
}

void Question::print_feed() const
{
	if (threadId != -1)
	{
		std::cout << "Parent(id: " << threadId << ") ";
	}

	std::cout << "Question(id:" << id << ") ";
	if (!anon)
	{
		std::cout << "from user(id:" << fromId << ") ";
	}

	std::cout << "to user(id:" << toId << "): " << text << "\n";
	std::cout << "Answer: " << ans << "\n";
}

/*
 * database_manager.cpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

/* ****** includes ******** */
#include "database_manager.hpp"

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

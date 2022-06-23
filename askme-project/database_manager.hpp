/*
 * database_manager.hpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#ifndef DATABASE_MANAGER_HPP_
#define DATABASE_MANAGER_HPP_

#include "questions_db.hpp"
#include "users_db.hpp"

struct DbManager
{
	UsersDb usersDb;
	QuestionsDb questionsDb;

	bool check_user_has_q(const int, const int);
	bool check_user_exist(User &);
};

#endif /* DATABASE_MANAGER_HPP_ */

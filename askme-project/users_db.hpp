/*
 * users_db.hpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#ifndef USERS_DB_HPP_
#define USERS_DB_HPP_

#include "user.hpp"

struct UsersDb
{
	/**
	 * generate id for new user
	 *
	 * @param non
	 * @return new id
	 */
	int generate_id();

	/**
	 * get user from db
	 *
	 * @param user id
	 * @return pair of user and bool if user is found via id
	 */
	std::pair<User, bool> get_user(int id);

	/**
	 * save user to db
	 *
	 * @param user to save
	 * @return bool whether user is saved or not
	 */
	bool add_user(User);

	/**
	 * get user from db using username and password
	 *
	 * @param User having username and password
	 * @return pair of user and bool if user is found via username and password
	 */
	std::pair<User, bool> get_user_login(User &);

	/**
	 * print all users id and username
	 *
	 * @param non
	 * @return non
	 */
	void print();
};

#endif /* USERS_DB_HPP_ */
/*
 * database_manager.hpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#ifndef DATABASE_MANAGER_HPP_
#define DATABASE_MANAGER_HPP_

/* ****** includes ******** */
#include "questions_db.hpp"
#include "users_db.hpp"
#include <iostream>
#include <vector>
#include <map>

#define DELIMITER ","
struct DbManager
{
	/* struct to handle user db */
	UsersDb usersDb;
	/* struct to handle questions db */
	QuestionsDb questionsDb;

	/**
	 * read file line by line and save in vector
	 *
	 * @param string path, vector
	 * @return void
	 */
	void read_file_lines(std::string path, std::vector<std::string> &lines);
	/**
	 * write lines in file from vector
	 *
	 * @param string path, vector lines, bool append
	 * @return bool
	 */
	bool write_file_lines(std::string path, std::vector<std::string> &lines, bool append);
	/**
	 * split at delimiter and push to vector
	 *
	 * @param string line, vector string, string delimiter
	 * @return void
	 */
	void split_line_toVector(std::string line, std::vector<std::string> &v, const std::string del);
	/**
	 * generate new id
	 *
	 * @param string path
	 * @return int
	 */
	int generate_id(const std::string);

	/**
	 * check whether user received this question or not
	 *
	 * @param question id, user id
	 * @return bool
	 */
	bool check_user_has_q(const int, const int);

	/**
	 * check whether user asked or received this question
	 *
	 * @param question id, user id
	 * @return bool
	 */
	bool check_user_from_to_q(const int qId, const int uId);

	/**
	 * check whether user exists or not using the id
	 *
	 * @param User sent by reference
	 * @return bool
	 */
	bool check_user_exist(User &);

	/**
	 * get all questions received to user and store in map
	 *
	 * @param user id, map
	 * @return map
	 */
	std::map<int, std::vector<Question>> get_all_Qs_to_user(const int uId, std::map<int, std::vector<Question>> &);
};

#endif /* DATABASE_MANAGER_HPP_ */

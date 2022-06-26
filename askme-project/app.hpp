/*
 * app.hpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#ifndef APP_HPP_
#define APP_HPP_
#include "user.hpp"

#include <iostream>

struct App
{
	/**
	 * Main app run function
	 *
	 * @param non
	 * @return non
	 */
	void run();

	/**
	 * run main menu
	 *
	 * @param Logged in user
	 * @return non
	 */
	void main_menu(User &);

	/**
	 * verify login user input choice at login menu choice between 1-3
	 *
	 * @param user choice
	 * @return whether choice is correct or not
	 */
	bool verify_login_choice(int);

	/**
	 * verify main menu user input choice between 1-8
	 *
	 * @param user choice
	 * @return whether choice is correct or not
	 */
	bool verify_main_choice(int);

	/**
	 * prompt user to enter question text
	 *
	 * @param non
	 * @return question text
	 */
	std::string ask_new_q();

	/**
	 * ask question
	 *
	 * @param non
	 * @return non
	 */
	void ask(User);

	void print_questions_received(int);

	/**
	 * display list of system users
	 *
	 * @param non
	 * @return non
	 */
	void list_users();
};

#endif /* APP_HPP_ */

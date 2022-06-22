/*
 * app.hpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#ifndef APP_HPP_
#define APP_HPP_

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
};

#endif /* APP_HPP_ */

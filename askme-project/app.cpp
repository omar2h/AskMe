/*
 * app.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "app.hpp"
#include "menu.hpp"
#include "user.hpp"
#include "login_handler.hpp"
#include "signup_handler.hpp"
#include "error.hpp"

#include <iostream>
#include <vector>
#include <utility>

bool App::verify_login_choice(int choice)
{
	if (choice < 1 && choice > 3)
	{
		return 0;
	}
	return 1;
}

bool App::verify_main_choice(int choice)
{
	if (choice < 1 && choice > 8)
		return 0;
	return 1;
}

void App::run()
{
	int choice;
	User user;
	Menu menu;
	Login_handler login_handler;
	Signup_handler signup_handler;
	std::pair<User, bool> userLoginPair;
	Error error;

	while (1)
	{
		while (1)
		{
			choice = menu.menu_login();

			if (!verify_login_choice(choice))
			{
				error.print(1);
				continue;
			}

			if (choice == 1)
			{
				userLoginPair = login_handler.login();
				if (userLoginPair.second)
				{
					user = userLoginPair.first;
					std::cout << "-------------- Logged In Successfully -------------\n\n";
					break;
				}
				else
					error.print(2);
			}

			else if (choice == 2)
			{
				if (!signup_handler.signup())
					continue;
			}
			else if (choice == 3)
				exit(0);
		}

		while (1)
		{
			choice = menu.menu_main();
			if (!verify_main_choice(choice))
			{
				error.print(1);
				continue;
			}

			if (choice == 1)
			{
				// 1 print questions received
			}

			else if (choice == 2)
			{
				// 2 print questions i asked
			}
			else if (choice == 3)
			{
				// 3 answer questions
			}
			else if (choice == 4)
			{
				// 4 delete question
			}
			else if (choice == 5)
			{
				// 5 ask question
			}
			else if (choice == 6)
			{
				// 6 list system users
			}
			else if (choice == 7)
			{
				// 7 feed
			}
			else if (choice == 8)
			{
				// 8: Logout
				break;
			}
		}
	}
}

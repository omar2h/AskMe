/*
 * app.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "app.hpp"
#include "menu.hpp"
#include "user.hpp"
#include "question.hpp"
#include "login_handler.hpp"
#include "signup_handler.hpp"
#include "database_manager.hpp"
#include "error.hpp"

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>

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

std::string App::ask_new_q()
{
	std::string q;
	std::cout << "Enter Your Question: ";
	std::getline(std::cin, q);
	return q;
}

void App::ask(User user)
{
	Question q;
	std::pair<User, bool> userPair;
	Error error;
	DbManager DB;
	int id;
	while (1)
	{
		std::cout << "Enter User ID You Want to Ask or -1 to cancel:  ";
		std::cin >> id;
		if (id == -1)
			return;

		userPair = DB.usersDb.get_user(id);
		if (userPair.second)
			break;
		error.print(3);
	}

	if (!userPair.first.allowAnonQs)
		std::cout << "Note: This User doesn't Allow Anonymous Questions\n";
	int qId;
	std::cout << "Enter question thread ID or -1 to Ask a New Question: ";
	std::cin >> qId;
	if (qId == -1)
		q.text = ask_new_q(), q.threadId = -1;
	else
	{
		// qId_exist();
	}
}

void App::list_users()
{
	DbManager DB;
	DB.usersDb.print();
}

void App::main_menu(User user)
{
	Menu menu;
	Error error;
	int choice;

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
			// 5: ask question
			ask(user);
		}
		else if (choice == 6)
		{
			// 6: list system users
			list_users();
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
					std::cout << "\n-------------- Logged In Successfully -------------\n\n";
					main_menu(user);
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
	}
}

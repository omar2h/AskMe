/*
 * menu.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "menu.hpp"

int Menu::menu_login()
{
    const std::string menuList = "Menu: \n"
                                 "\t1: Login\n"
                                 "\t2: Sign up\n"
                                 "\t3: Exit\n\n"
                                 "Please enter a number (1 - 3): ";

    return get_choice(menuList);
}

int Menu::menu_main()
{
    const std::string menuList = "Menu: \n"
                                 "\t1: Print Questions Received\n"
                                 "\t2: Print Questions I Asked\n"
                                 "\t3: Answer Questions\n"
                                 "\t4: Delete Questions\n"
                                 "\t5: Ask Questions\n"
                                 "\t6: List System Users\n"
                                 "\t7: Feed\n"
                                 "\t8: Logout\n\n"
                                 "Please enter a number (1 - 8): ";

    return get_choice(menuList);
}

void Menu::print(const std::string menuList)
{
    std::cout << menuList;
}

int Menu::get_choice(const std::string menuList)
{
    int choice;
    print(menuList);
    std::cin >> choice;
    return choice;
}

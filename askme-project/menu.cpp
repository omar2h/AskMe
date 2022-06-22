/*
 * menu.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "menu.hpp"

void Menu::print(std::string menuList)
{
    std::cout << menuList;
}

int Menu::get_choice(std::string menuList)
{
    int choice;
    print(menuList);
    std::cin >> choice;
    return choice;
}



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

 int App::menu_login()
 {
     Menu menu;
     const std::string menuList = "Menu: \n"
                             "\t1: Login\n"
                             "\t2: Sign up\n"
                             "\t3: Exit\n\n"
                             "Please enter a number (1 - 3): ";

     return menu.get_choice(menuList);
 }

void App::run()
{
     int choice;
     User user;
     Login_handler login_handler;
     Signup_handler signup_handler;
     std::pair<User, bool> userLoginPair;
     Error error;

     while (1)
     {
         choice = menu_login();

         if (!verify_login_choice(choice))
         {
             error.print(1);
             continue;
         }

         if (choice == 1)
         {
             userLoginPair = login_handler.login();
             if (userLoginPair.second){
                 user = userLoginPair.first;
                 std::cout<<"-------------- Logged In Successfully -------------\n\n";
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



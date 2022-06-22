/*
 * signup_handler.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "signup_handler.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

int Signup_handler::generate_id(){
	std::string path = "users.txt";
	std::fstream file_handler(path.c_str());

	if (file_handler.fail())
	{
		std::cout << "\n -------- Can't open file -----------\n\n";
		return 0;
	}

	std::string line;
	int count = 1;
	while (getline(file_handler, line))
	{
		std::stringstream iss(line);
		count++;
	}

	return count;
}

bool Signup_handler::signup()
{
	int id;
    std::string username, password;

    std::cout << "Please enter UserName and Password: ";
    std::cin >> username >> password;
    id = generate_id();
    std::ofstream fout("users.txt", std::ios_base::app);

    if (fout.fail())
    {
    	std::cout << "Can't open file\n";
        return 0;
    }

    fout << id << ' ' << username << ' ' << password<<'\n';
    std::cout<<"\n---------------- Signed Up Successfully ------------- \n\n";

    return 1;
}



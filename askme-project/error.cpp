/*
 * error.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "error.hpp"

#include<iostream>

void Error::print(int c){
	if(c==1)
		std::cout << "---------- Invalid choice -----------\n\n";
	else if(c==2)
		std::cout<<"---------- Wrong UserName/Password ------------\n\n";
}



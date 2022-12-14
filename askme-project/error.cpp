/*
 * error.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: omarh
 */

#include "error.hpp"

#include <iostream>

void Error::print(const int c) const
{
	if (c == 1)
		std::cout << "\n---------- Invalid choice -----------\n\n";
	else if (c == 2)
		std::cout << "\n---------- Wrong UserName/Password ------------\n\n";
	else if (c == 3)
		std::cout << "\n---------- User ID doesn't seem to exist ------------\n\n";
	else if (c == 4)
		std::cout << "\n---------- Question ID doesn't seem to exist for this user ------------\n\n";
}

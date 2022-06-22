/*
 * question.hpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#ifndef QUESTION_HPP_
#define QUESTION_HPP_

#include <iostream>

struct Question
{
	int id, threadId, fromId, toId;
	bool answered;
	std::string text;
};

#endif /* QUESTION_HPP_ */

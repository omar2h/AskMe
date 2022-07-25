/*
 * question.hpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#ifndef QUESTION_HPP_
#define QUESTION_HPP_

#include <iostream>
#include <vector>
#include <map>

struct Question
{
	int id, threadId, fromId, toId;
	bool anon, answered;
	std::string text, ans = "";

	bool has_children() const;
	void print() const;
	void print_child(int);
	void print_asked() const;
	void print_feed() const;
};

void print_children(std::vector<Question>, std::map<int, std::vector<Question>> &, int);

#endif /* QUESTION_HPP_ */

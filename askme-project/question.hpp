/*
 * question.hpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#ifndef QUESTION_HPP_
#define QUESTION_HPP_

/* ****** includes ******** */
#include <iostream>
#include <vector>
#include <map>

struct Question
{
	/* id, threadId, fromId, toId, anonymous question?, answered?, question text, answer text */
	int id, threadId, fromId, toId;
	bool anon, answered;
	std::string text, ans = "";

	/**
	 * print question child
	 *
	 * @param number of spaces
	 * @return void
	 */
	void print_child(int);
	/**
	 * check if question has children
	 *
	 * @param non
	 * @return bool
	 */
	bool has_children() const;
	/**
	 * print question
	 *
	 * @param non
	 * @return void
	 */
	void print() const;
	/**
	 * print question in asked format
	 *
	 * @param non
	 * @return void
	 */
	void print_asked() const;
	/**
	 * print question in feed format (with answer)
	 *
	 * @param non
	 * @return void
	 */
	void print_feed() const;
};

/**
 * print question children
 *
 * @param vector of questions, map of id, vector of questions
 * @return void
 */
void print_children(std::vector<Question>, std::map<int, std::vector<Question>> &, int);

#endif /* QUESTION_HPP_ */

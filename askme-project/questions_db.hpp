/*
 * questions_db.hpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#ifndef QUESTIONS_DB_HPP_
#define QUESTIONS_DB_HPP_

#include "question.hpp"

struct QuestionsDb
{
	int generate_id();
	std::pair<Question, bool> get_question(const int);
	bool add_question(Question &);
	void print();
};

#endif /* QUESTIONS_DB_HPP_ */

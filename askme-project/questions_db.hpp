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
	Question get_question(int id);
	void print();
};

#endif /* QUESTIONS_DB_HPP_ */

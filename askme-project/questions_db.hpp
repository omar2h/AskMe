/*
 * questions_db.hpp
 *
 *  Created on: Jun 22, 2022
 *      Author: omarh
 */

#ifndef QUESTIONS_DB_HPP_
#define QUESTIONS_DB_HPP_

#include "question.hpp"
#include <vector>
#include <map>

struct QuestionsDb
{
	int generate_id();
	std::map<int, std::vector<Question>> get_to_user(const int);
	bool get_questions_from_user(const int, std::vector<Question> &);
	std::pair<Question, bool> get_question(const int);
	bool add_question(Question &);
	void delete_q(const int qId);
	void update_answer(const Question &);
	void print(const Question &);
	std::vector<Question> feed();
};

#endif /* QUESTIONS_DB_HPP_ */

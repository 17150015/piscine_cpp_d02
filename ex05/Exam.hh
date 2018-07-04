#ifndef EXAM_H_
#define EXAM_H_

#include <string>
#include <iostream>

class Exam
{
	public:
	Exam(bool *);
	~Exam();
	void (Exam::*kobayashiMaru)(int);
	void	start(int);
	bool	isCheating();
	static bool cheat;
};

#endif

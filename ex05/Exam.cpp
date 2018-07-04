#include <iostream>
#include <string>
#include "Exam.hh"

bool Exam::cheat = false;

Exam::Exam(bool *toto)
{
	this->cheat = *toto;
}

Exam::~Exam()
{
}

void	Exam::start(int nbr)
{
	std::cout << "[The exam is starting]" << std::endl;
	std::cout << nbr << " Klingon vessels appeared out of nowhere." << std::endl;
	std::cout << "they are fully armed and shielded" << std::endl;
	if (this->cheat == false)
		std::cout << "This exam is hard... you lost again." << std::endl;
	if (this->cheat == true)
		std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
}

bool	Exam::isCheating()
{
	return this->cheat;
}

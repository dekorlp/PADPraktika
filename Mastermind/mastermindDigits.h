/////////////////////////////////////////////////////////////////////////////
// Name:	  mastermindDigits
// Purpose:	  mastermind ruleset and guess
// Author:	  Dennis Koehler
// Created:	  2016-04-12
/////////////////////////////////////////////////////////////////////////////



#ifndef MASTERMINDDIGITS_H
#define MASTERMINDDIGITS_H

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class MastermindDigits
{
	private:
		unsigned int* digits;
		bool usedColors[6];
	public:
		MastermindDigits();
		MastermindDigits(unsigned int digits);
		MastermindDigits(const MastermindDigits& toMastermindDigits);
		const MastermindDigits& MastermindDigits::operator=(const MastermindDigits& right);
		void makeDigitsToGuess();
		unsigned int locationRight(MastermindDigits mastermindDigits);
		unsigned int locationWrong(MastermindDigits mastermindDigits);
		operator unsigned int() const;

		~MastermindDigits();
};

#endif // MASTERMINDDIGITS_H
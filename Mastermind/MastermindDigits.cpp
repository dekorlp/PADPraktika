#include "mastermindDigits.h"

MastermindDigits::MastermindDigits()
{
	this->digits = new unsigned int[4];

	for (int i = 0; i < 6; i++)
	{
		this->usedColors[i] = 0;
	}
}

MastermindDigits::MastermindDigits(unsigned int digits)
{
	if ((digits < 1111 || digits > 6666))
	{
		throw ("digits are out of Range");
	}

	this->digits = new unsigned int[4];

	if ((digits >= 1111 && digits <= 6666))
	{ 
		for (int i = 3; i >= 0; i--)
		{
			this->digits[i] = digits % 10;
			digits /= 10;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		this->usedColors[i] = 0;
	}
}

MastermindDigits::MastermindDigits(const MastermindDigits& toCopy)
	: digits(new unsigned int [4])
{
	digits = toCopy.digits;

}

const MastermindDigits& MastermindDigits::operator=(const MastermindDigits& right)
{

	if (&right != this)
	{
		if (digits != right.digits)
		{
			delete[] this->digits;
			this->digits = new unsigned int[4];
			this->digits = right.digits;
		}
	}
	return *this;
}


void MastermindDigits::makeDigitsToGuess()
{
	default_random_engine engine(static_cast<unsigned int> (time(nullptr)));
	uniform_int_distribution<unsigned int> randomInt(1, 6);

	for (int i = 0; i < 4; i++)
	{
		this->digits[i] = randomInt(engine);
	}
}

unsigned int MastermindDigits::locationRight(MastermindDigits mastermindDigits)
{
	unsigned int iLocationRight = 0;
	for (int i = 0; i < 4; i++)
	{
		if (digits[i] == mastermindDigits.digits[i])
		{
			usedColors[mastermindDigits.digits[i] - 1] = true;
			iLocationRight++;
		}
	}


	return iLocationRight;
}

unsigned int MastermindDigits::locationWrong(MastermindDigits mastermindDigits)
{
	unsigned int iLocationWrong = 0;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (this->digits[i] == mastermindDigits.digits[j] 
				&& i != j
				&& usedColors[mastermindDigits.digits[j] - 1] != true)
			{
				usedColors[mastermindDigits.digits[j]-1] = true;
				iLocationWrong++;
				break;
			}
		}
	}

	return iLocationWrong;
}

MastermindDigits::operator unsigned int() const
{
	int number = 0;
	int factor = 1;
	for (int i = 3; i >= 0; i--)
	{ 
		number += digits[i] * factor;
		factor *= 10;
	}
	return number;
}

MastermindDigits::~MastermindDigits()
{
	delete[] this->digits;
	this->digits = NULL;
}
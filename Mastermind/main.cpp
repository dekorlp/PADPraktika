#include <iostream>
#include "mastermindDigits.h"

#define COUNT_OF_ROUNDS 10

using namespace std;

void executeGame(MastermindDigits mastermindDigits);
void runtimeTest();

int main()
{
	MastermindDigits *mastermindDigits = NULL;
	char gameMode = 'a';
	unsigned int referenceNumber = 0;

	// game application menu and game while

	do
	{
		cout << "(S)pielen - (T)esten: - (L)aufzeittest - (B)eenden: ";
		cin >> gameMode;
		
		
		switch (gameMode)
		{
			case 's': case 'S':
				mastermindDigits = new MastermindDigits();
				mastermindDigits->makeDigitsToGuess();
				cout << "Es wurden vier Zufallszahlen durch den Computer gewaehlt!" << endl << endl;
				executeGame(*mastermindDigits);
				break;
			case 't': case 'T':
				cout << "Testzahl eingeben: ";
				cin >> referenceNumber;
				cout << endl << endl;
				mastermindDigits = new MastermindDigits(referenceNumber);
				executeGame(*mastermindDigits);
				break;
			case 'l': case 'L':
				runtimeTest();
				break;
			default:
				cout << "Dieser Befehl ist unbekannt!" << endl << endl;
				break;
		}
	} while (gameMode != 'b' && gameMode != 'B');

	return 0;
}

void runtimeTest()
{
	
}


void executeGame(MastermindDigits mastermindDigits)
{
	bool gameGotten = false;

	unsigned int iTry;
	for (int i = 0; (i < COUNT_OF_ROUNDS && gameGotten != true); i++)
	{
		cout << i + 1 << ". Versuch:";
		cin >> iTry;
		if (mastermindDigits.locationRight(iTry) == 4)
		{
			gameGotten = true;
		}
		else
		{
			cout << mastermindDigits.locationRight(iTry) << " an der richtigen Stelle." << endl;
			cout << mastermindDigits.locationWrong(iTry) << " passende Farben." << endl;
		}
		cout << endl << endl;
	}

	if (gameGotten)
	{
		cout << "Gewonnen!!!" << endl << endl << endl;
	}
	else
	{
		cout << "Verloren!!!" << endl << endl << endl;
	}
}



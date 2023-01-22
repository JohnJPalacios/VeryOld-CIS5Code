//Palacios_ch5_5, aka "change counter."
//This small application computes the number of a given coin in a user provided number of cents from 1 to 99 cents.
//John Palacios
//03-26-2013

#include<iostream>
using namespace std;

const int QTR = 25;	//This is the number of pennies in a quarter.
const int DME = 10;	//This is the number of pennies in a dime.

void compute_coins(int coin_value, int& num, int& amount_left);
//precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
//postcondition: num has been set equal to the maximum number
//of coins of denomination coin_value cents that can be obtained
//from amount_left. Additionaly, amount_left has beeen decreased
//by the value of coins, that is, decreased by num * coind_value.

int main()
{
	int quarters;	//This will be the number of quarters in the change.
	int dimes;		//This will be the number of dimes in the change.
	int pennies;	//This will be the number of pennies in the change.
	int change;		//number of cents entered by user, then working change remaining to be calculated.
	char answer;	//Holds the user's reply either 'y' or 'n'.

	//Prompts the user for input, then computes the change, and offers another computation.
	do
	{
		do
		{
		cout << "Please enter the number of cents (from 1 to 99) you wish to make change for.\n";
		cin >> change;
		}while(change < 0 || change > 99);

		compute_coins(QTR, quarters, change);
		compute_coins(DME, dimes, change);
		pennies = change;

		if (quarters != 1)
		{
			cout << quarters << " quarters\n";
		}
		else
		{
			cout << quarters << " quarter\n";
		}
		if (dimes != 1)
		{
			cout << dimes << " dimes\n";
		}
		else
		{
			cout << dimes << " dime\n";
		}
		if (pennies != 1)
		{
			cout << pennies << " pennies\n";
		}
		else
		{
			cout << pennies << " penny\n";
		}

		cout << "Would you like to perform another computation?\n"
			 << "type \'Y\' for yes, or \'n\' for no.\n";
		cin >> answer;

	}while (answer == 'Y' || answer == 'y');

	return 0;

}

void compute_coins(int coin_value, int& num, int& amount_left)
	{
		num = amount_left / coin_value;
		amount_left = amount_left % coin_value;
	}
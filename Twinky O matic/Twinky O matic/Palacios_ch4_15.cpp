//Palacios_ch4_15 aka "Twinky O matic"
//This simple application simulates the display of a deep fried twinky vending machine.
//John Palacios
//03-22-2013


#include<iostream>
using namespace std;

const double COST = 3.5; //This is the cost of one deep fried twinky.

double getCoins();
//getCoins prompts the user for a denomination, and then passes the 
//denomination choice to getCoinValue.

double getCoinValue(int choice);
//int choice is accepted as an int from 1 to 4.
//returns the double $ value of choice.

//Prompt the user to enter denomination choice. Display the remaining balance untill
//totalSofar > COST, and change if any.
int main()
{
	double totalSofar = 0; //Accumulates the total value of denominations entered by user.

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Welcome to Twinky O Matic, \'The Deep-fried twinky vending machine!\'\n"
		 << "The price for a delectible deep-fried twinky is only $" << COST << " today.\n"
		 << "To purchase a delicious deep-fried twinky, please enter a denomination listed below.\n";
	do
	{
		totalSofar += getCoins();
		cout << "$" << totalSofar << endl;
	}while (totalSofar < COST);

	cout << "Thank you! Enjoy your deep-fried twinky.\n";

	if (totalSofar > COST)
	cout << "Your change is $" << totalSofar - COST << endl;

	return 0;
}

double getCoins()
{
	int coin; //Holds the choice the user makes from the menue below.

	//Prompt the user to make a menu choice untill a valid entry is made.
	do
	{
	cout << "enter 1 for dollar\n"
		 << "enter 2 for quarter\n"
		 << "enter 3 for dime and\n"
		 << "enter 4 for nickel\n";
	cin >> coin;
	}while ((coin != 1) && (coin != 2) && (coin != 3) && (coin != 4));

return getCoinValue (coin);
}

double getCoinValue (int choice)
{
	double coinValue; //Holds the value of the validated user choice.


	//Sets coinValue to the denomination value for the choice.
	switch (choice)
	{
		case 1: coinValue = 1.0;
			break;
		case 2: coinValue = 0.25;
			break;
		case 3: coinValue = 0.1;
			break;
		case 4: coinValue = 0.05;
			break;
	}

return coinValue;
}
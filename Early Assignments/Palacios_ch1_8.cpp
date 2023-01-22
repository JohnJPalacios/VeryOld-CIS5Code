//Common Cents
//This program accepts an integer number of coins, and outputs an integer number of cents.
//John Palacios
//02-26-2013

#include<iostream>
using namespace std;
int main()
{

int quarters = 0;	//This variable will contain the number of quarters.
int dimes = 0;		//This variable will contain the number of dimes.
int nickels = 0;	//This variable will contain the number of nickles.
					//All of these variables are initialy set to zero to prevent garbage answers.
cout << "Welcome to \"Common Cents\" This lightweight application will help find the total number of cents ammong a number of common coins.\n";
cout << "Please enter the number of quarters.\n";

cin >> quarters;	//The user sets variable quarters to an integer.

cout << "Thank you. Please enter the number of dimes.\n";

cin >> dimes;		//The user sets variable dimes to an integer.

cout << "Thank you. Please enter the number of nickels.\n";

cin >> nickels;		//The user sets the varable nickels to an integer.

int qCents = quarters * 25;					//The new variable qCents holds the number of quarters in cents, thus "qCents"
int dCents = dimes * 10;					//The new variable dCents holds the number of dimes in cents, thus "dCents"
int nCents = nickels * 5;					//The new variable nCents holds the number of nickels in cents, thus "nCents"
int sumCents = qCents + dCents + nCents;	//The sum of pennies in quarters, dimes, and nickels is held in "sumCents"
cout << "\nThank you. you have " << sumCents << " cents.\n"; //displays the total number of cents for the user.

return 0;
}
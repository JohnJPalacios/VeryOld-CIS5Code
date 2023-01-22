//Sum and product
//This program accepts two integer inputs from the user, and then computes the sum of these numbers, and the product of these numbers.
//Programmer: John Palacios
//02-26-2013

#include<iostream>
using namespace std;

int main()
{
	int numOne = 0;	//numOne is the first of the user supplied data. Set to zero as contingency against unexpected data.
	int numTwo = 0;	//numTwo is the second of the user supplied data. It is also set to zero untill populated with appropriate data.
	int sum = 0;	//This variable will not be used untill both numOne and numTwo are set by the user; it will be the sum of numOne
					//numTwo.
	int product = 0;//This variable will hold the integer that is the product of numOne and numTwo.

	cout << "Welcome to \"Sum and product.\" This lightweight application will give you both\n";
	cout << "The sum and the product of two number that you provide. Pretty nifty huh?\n";
	cout << "Please type the first number, and then press enter.\n";
	//This friendly and verbose user prompt is necessary to explain how to use this application to the user.

	cin >> numOne;
	//The user types an integer, which is stored in numOne for later use.

	cout << "Thank you. Please enter the second number.\n";

	cin >> numTwo;
	//The user types an integer, which is stored in numTwo for later use.

	sum = numOne + numTwo;		//the sum of numOne and numTwo are now calculated and held in variable sum.
	product = numOne * numTwo;	//The product of numOne and numTwo are now calculated and held in varable product.

	cout << "Thank you. Now let's see those results...\n";
	cout << "The sum of " << numOne << " and " << numTwo << " is\n"; //This redisplays the contents of numOne and numTwo for the user.
	cout << sum << ".\n";											//Displays the new contents of sum.
	cout << "The product of " << numOne << " and " << numTwo << " is\n";
	cout << product << ".\n";										//Displays the new contents of product.
	cout << "Good bye.\n";											//Displays a briefe farewell to the user.
	
	return 0;
}

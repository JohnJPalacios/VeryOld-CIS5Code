//Palacios_Final.cpp aka... I can't think of a name for this one.
//This application presents the user with a list of options to create and save a list
//of psuedo random factors of five between 5 and 100, or load thier own list, or sort
//aformentioned values, or display afformentioned values. The files NumberArray.cpp
//and NumberArray.h must be in the current directory.
//Programmer: John Palacios.
//06-01-2013

#include<iostream>
#include<cctype>
#include "Palacios_Final_NumberArray.h"
using namespace std;

void displayMenu();
//precondition: none.
//postcondition: a menu of five choices are displayed to the screen for the user.

int getChoice();
//precondition: none.
//postcondition: getChoice returns an int value corresponding to user input, if no int.
//value corresponds to user input, ask the user for input untill an int is entered.

int main()
{
	NumberArray test;	//new instance of NumberArray called test.
	int num;			//Abitrary variable which holds user data for magnitude 
						//and seed choices.
	int choice;			//processed user data indicating selection from below
						//switch statement.
	
	cout << "Welcome! This application provides the user several options\n"
		<< "to create or interact with a set of numbers.\n"
		<< "Please make a selection from the list below, thank you.\n\n";

	do
	{
		displayMenu();
		choice = getChoice();
		
		switch (choice)
		{
		case 1:
			cout << "How many elements will be in this random array?\n";
			cin >> num;
			test.setMag(num);
			cout << "What number would you like to use as a 'seed' value?\n";
			cin >> num;
			test.setSeed(num);
			test.genArray();
			test.saveArray();
			break;

		case 2:
			test.loadArray();
			break;

		case 3:
			test.sortArray();
			break;

		case 4:
			test.displayArray();
			break;
			
		case 5:
			cout << "Exiting program...\n";
			break;

		default:
			cout << "Error: That input was not anticipated, please try again.\n"
				<< "Choices are 1, 2, 3, 4, or 5.\n";
		}


	}while(choice != 5);

	cout << "Thank you for using my application. Good bye.\n";

	return 0;
}

void displayMenu()
{
	cout << "Enter 1 to CREATE an array of random elements and SAVE array to a file.\n"
		<< "Enter 2 to LOAD an array from a file.\n"
		<< "Enter 3 to SORT current array.\n"
		<< "Enter 4 to DISPLAY current array.\n"
		<< "Enter 5 to EXIT program.\n";
}

int getChoice()
{
	char input;		//raw unvalidated user input.
	int choice;		//corresponding integer value to validated user input... hopefully.

	do
	{
	cin >> input;
	if(!isdigit(input))
		cout << "Error: That is not a valid choice; please try again.\n";
	else
		choice = input - 48;
	}while(!isdigit(input));

	return choice;
}
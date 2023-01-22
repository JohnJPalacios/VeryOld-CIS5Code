//Palacios_ch10_11.cpp aka "Fuel Calculator"
//This program tests the Odometer class, which keeps track of miles driven, 
//and fule consumed on a number of consecutive trips.
//John Palacios
//05-14-2013

#include<iostream>
using namespace std;

class Odometer
{
private:
	double milesDriven;
	double mpg;

public:
	Odometer();
	//Constructor, initializes milesDriven and mpg to 0.0.

	void reset();
	//Precondition: object of class Odometer initialized.
	//Postcondition: private member milesDriven set to 0.0.

	void setMpg(double newMpg);
	//Precondition: object of class Odometer initialized.
	//Postcondition: private member mpg = newMpg if newMpg > 0.

	void addMiles(double miles);
	//precondition: object of class Odometer initialized.
	//Postcondition: milesDriven increased by miles if miles is positive intager.

	double getGallons();
	//Precondition: milesDriven and mpg > 0.
	//Postcondition: getGallons evaluates to double gallons of gassoline consumed.
};

int main()
{
	int itteration;
	double legMiles;
	double fuelEfficiency;
	double fuelConsumed;
	char command;

	cout << "Welcome to the Fuel Calculator app!\n\n"
		<< "This program will calculate the fuel used durrng a multi leg trip\n"
		<< "and allow you to calculate fuel used for multiple trips.\n\n";
	do
	{
		Odometer roadTrip;
		cout << "please enter the fuel efficiency of the vehichle that you will be driving\n"
			<< "on this trip. For example; if you were driving a 1995 Ford Taurus SE, you might\n"
			<< "type something like '16.5' and then press enter.\n";
		cin >> fuelEfficiency;
		roadTrip.setMpg(fuelEfficiency);
		cout << "Thank you. Please enter the number of miles driven for the first leg of\n"
			<< "the trip.\n";
		cin >> legMiles;
		roadTrip.addMiles(legMiles);
		cout << "Is there another leg to your trip? if so, type 'y'\n";
		cin >> command;
		if (command == 'y')
		{
			do
			{
				cout << "Please enter the number of miles driven for the next leg of the" 
					<< " trip.\n";
				cin >> legMiles;
				roadTrip.addMiles(legMiles);
				cout << "Is there another leg of this trip?\n";
				cin >> command;
			}while(command == 'y');
		}
		fuelConsumed = roadTrip.getGallons();
		cout << "That trip used " << fuelConsumed << " gallons of gasoline.\n"
			<< "Would you like to calculate fuel used for another trip?\n"
			<< "If so, type 'y', then press enter.\n";
		cin >> command;
	}while(command == 'y');

	cout << "Thank you for using the Fuel Calculator app. Good bye.\n\n";

	return 0;
}

Odometer::Odometer()
{
	milesDriven = 0.0;
	mpg = 0.0;
}

void Odometer::reset()
{
	milesDriven = 0.0;
}

void Odometer::setMpg(double newMpg)
{
	if(newMpg > 0)
		mpg = newMpg;
}

void Odometer::addMiles(double miles)
{
	if(miles > 0)
		milesDriven += miles;
}

double Odometer::getGallons()
{
	return milesDriven / mpg;
}
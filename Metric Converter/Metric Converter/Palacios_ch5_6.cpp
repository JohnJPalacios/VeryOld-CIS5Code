//Palacios_ch5_6 aka "Metric converter."
//This simple console application converts user input feet and inches into meters and centimiters.
//John Palacios
//03-26-2013

#include<iostream>
using namespace std;

const double METERS_PER_FOOT = 0.3048;		//Meters per foot: necessary to perform conversion.
const double CENTIMETERS_PER_METER = 100;	//Centimeters per meter.
const double INCHES_PER_FOOT = 12;			//inches per foot.

void getInput(int &feet, int &inches);
//Prompts user for input, validates and then reads in user input.
//sets feet and inches to user supplied input.

void convertValues(int feet, int inches, int &meters, int &centimeters);
//Precondition: feet and inches set to integer values by user input.
//postcondition: meters and centimeters set to equivelent values * user input.
//convertValues will compute the metric equivelent to user defined feet and 
//inches, then set meters and centimeters to those equivelents.

void displayResults(int feet, int inches, int meters, int centimeters);
//displayResults displays user input feet and inches and the computed informaion
//meters and centimeters to the screen in a nice format.

int main()
{
	int feet;				//User input.
	int inches;				//User input.
	int meters;				//Computed value.
	int centimeters;		//Computed value.
	char answer = 'n';		//User reply to repeat calculation.

	cout << "Welcome to \'Metric Converter\' 0.0.1 light edition.\n"
		 << "This program will convert a number of feet and inches\n"
		 << " into a number of meters and centimeters.\n";
	do
	{
		cout << "First, type the number of whole feet to convert, \n"
			 << "Then type the number of whole inches to convert. \n"
			 << "The program will automaticaly calculate the approximate\n"
			 << "number of meters and centimeters to your measurement.\n"
			 << endl;

		getInput(feet, inches);
		convertValues(feet, inches, meters, centimeters);
		displayResults(feet, inches, meters, centimeters);

		cout << "Would you like to perform another calculation?\n"
			 << "type \'y\' for yes, or type \'n\' to quit.\n";

		cin >> answer;

	}while (answer == 'Y' || answer == 'y');

	cout << "Thank you for using \'Metric Converter\' 0.0.1 light edition.\n"
		 << "Good bye."
		 << endl;

	return 0;

}

void getInput(int &feet, int &inches)
{
	int input = 0;	//User input to be validated before setting variables.
	int equivFeet;  //Holds equivelent foot value of inches if more than twelve inches.

	//Prompt the user for input while value less than zero, set feet and inch values.
	//Linear distance is always positive.
	do
	{
		cout << "Please enter a whole number of feet: \n";
		cin >> input;

	}while (input < 0);

	feet = input;
	input = 0;

	
	do
	{
		cout << "Please enter a whole number of inches: \n";
		cin >> input;

	}while (input < 0);
	
	//Pre-convert extra inches into feet.
	if (input >= 12)
	{
		equivFeet = input / static_cast<int>(INCHES_PER_FOOT);
		feet += equivFeet;
		input = input - equivFeet * INCHES_PER_FOOT;
	}

	inches = input;
	input = 0;

	return;
}

void convertValues(int feet, int inches, int &meters, int &centimeters)
{
	double feetDbl;
	double meterDbl;

	feetDbl = feet + inches / INCHES_PER_FOOT;
	meterDbl = feetDbl * METERS_PER_FOOT;
	meters = meterDbl;
	centimeters = (meterDbl - meters) * CENTIMETERS_PER_METER;

	return;
}

void displayResults(int feet, int inches, int meters, int centimeters)
{
	cout << "You entered: \n";

	//check for plural agreement.
	if (feet != 1)
		cout << feet << " feet.\n";
	else
		cout << feet << " foot.\n";


	if (inches != 1)
		cout << inches << " inches.\n";
	else
		cout << inches << " inch.\n";

	cout << "Which is approximately equivelent to: \n";

	if (meters != 1)
		cout << meters << " meters.\n";
	else
		cout << meters << " meter.\n";


	if (centimeters != 1)
		cout << centimeters << " centimeters.\n";
	else
		cout << centimeters << " centimeter.\n";

	return;
}

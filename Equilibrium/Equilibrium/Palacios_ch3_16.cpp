//Palacios_ch3_16 aka "Equilibrium"
//This simple application will find the temparature in Fahrenheit
//that is the same as Celsius.
//John Palacios
//03-12-13

#include<iostream>
using namespace std;

int main()
{
	int fahTemp = 0;		//The temperature in degrees Celsius. 
	int celTemp = 100;		//The temperature in degrees Fahrenheit.
	
	//perform conversion from celsius to fahrenheit and set the temps untill fahTemp and celTemp are equal.
	for (int fahrenheit = 0, celsius = 100; celTemp != fahTemp; celsius --)
	{
		fahrenheit = ((9 * celsius)/5) + 32;
		cout << celsius << " " << fahrenheit << endl;
		fahTemp = fahrenheit;
		celTemp = celsius;
	}

	//Display the temps which are equal.
	cout << "The temperature " << fahTemp << " degrees fahrenheit is"
		 << " equal to " << celTemp << " degrees celsius.\n";

	return 0;

}
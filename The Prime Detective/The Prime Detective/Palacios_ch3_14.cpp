//Palacios_ch2_14 aka "The Prime Detective"
//Prints all prime numbers between 3 and 100.
//John Palacios
//02-08-2013

#include<iostream>
using namespace std;

int main()
{
	int num = 3;		//counting number for each step of the process.
	int div = 2;		//divisor used to check num for primality.
	bool prime = false;	//prime is true when num % div is never 0.
	
	//Itterate through all values between 3 and 100 to look for prime numbers.
	//each itteration branches between the possible results of num % div.
	while (num < 101)
	{
		if (prime == true)
		{
			cout << num << endl;
			prime = false;
			num++;
			div = 2;
		}

		else if (num % div == 0)
		{
			num++;
			div = 2;
		}

		else if (div == num-1)
		{
			prime = true;
		}

		else
		{
			div++;
		}

	}

return 0;
}
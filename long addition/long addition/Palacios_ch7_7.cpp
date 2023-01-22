//Palacios_ch7_7.cpp, aka "long hand addition algorithym."
//accepts two positive integers that are less than 20 digits in length and adds them.
//John Palacios
//05-09-2013
#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;


const int MAX_RESULT_LENGTH = 20;	//the maximum number of digits in the sum.
const int MAX_INPUT_LENGTH = 20;	//the maximum number of digits allowed in the iinput.

void flushCin();
//precondition: input buffer has data.
//Postcondition: data in input buffer is consumed up to the newline character.

void getInput(int a1[], int& liu1, int a2[], int& liu2);
//asks the user for input, then populates a1[] and a2[]. liu1 and liu2 are the last indexies used for a1 and a2.
//postcondition: a1[] and a2[] are populated with liu1+1 and liu2+1 integers where liu(1 or 2) + 1 <=  cosnt MAX_INPUT_LENGTH.

void reverseOrder(int a[], int liu);
//precondition: a[] filled with MAX_INPUT_LENGTH elements of type int.
//postcondition: order of elements in a[] is reversed.

void addEm(int a1[], int liu1, int a2[], int liu2, int sum[], int& liuSum);
//precondition: a1[] and a2[] elements filled with ints of value < 10.
//postcondition: sum[] elements are filled with ints, each of which is the sum of a1[index] and the corresponding
//element of a2[index] where values in sum[] will be < 10, and sum[] may be longer than MAX_INPUT_LENGTH.

void printarr(int arr[], int liu);
//postcondition: elements up to liu of array arr[] printed out in succession to console.

void display(int add1[], int liu1, int add2[], int liu2, int sum[], int liuSum);
//Precondition: liu1, liu2, and liuSum are the last index used in add1[], add2[] and sum[] respectively.
//MAX_INPUT_LENGTH AND MAX_RESULT_LENGTH are global constants set with integer values representing expected size of 
//parametric arrays.
//postcondition: elements of add1 and add2 are printed to screen in MAX_INPUT_LENGTH space, one attop the other with
//an addition sign and dashed line to create the illusion of a virtical additon diagram with the elements of
//sum[] printed out after and equal sign in a space equal to MAX_RESULT_LENGTH.

int main()
{
	char answer;						//User reply to make another calculation.
	int first[MAX_INPUT_LENGTH] = {0};	//integer representation of input1[].
	int second[MAX_INPUT_LENGTH] = {0};	//integer representation of input2[].
	int lastIndex1 = 0;					//This is the number of elements filled with ints in first[].
	int lastIndex2 = 0;					//This is the number of elements filled with ints in second[].
	int sum[MAX_RESULT_LENGTH];			//This array will be populated with the result of f(x) 'addEm'.
	int lastIndexSum;					//This is the number of sum[] elements populated with ints by f(x) 'addEm'.

	cout << "  Welcome to 'long addition' 0.9.3. This program adds two positive numbers"
		<< "\nof up to " << MAX_INPUT_LENGTH << " digits in length for you!\n";

	do
	{
	getInput(first, lastIndex1, second, lastIndex2);
	reverseOrder(first, lastIndex1);
	reverseOrder(second, lastIndex2);
	addEm(first, lastIndex1, second, lastIndex2, sum, lastIndexSum);
	if(lastIndexSum + 1 >= MAX_RESULT_LENGTH)
	{
		cout << "Error: Integer overflow!\n";
		exit(1);
	}
	else
	{
	reverseOrder(first, lastIndex1);
	reverseOrder(second, lastIndex2);
	reverseOrder(sum, lastIndexSum);
	display(first, lastIndex1, second, lastIndex2,sum, lastIndexSum);
	}
	cout << "Would you like to use \"long addition\" to make another calculation?\n"
		<< "type 'y' to run again.\n";
	cin.get(answer);
	flushCin();
	}while(tolower(answer) == 'y');

return 0;
}

void flushCin()
{
	char nextChar;

	do
	{
		cin.get(nextChar);
	}while (nextChar != '\n');
}

void getInput(int a1[], int& liu1, int a2[], int& liu2)
{
	int index = 0;	//Counts the number of digits in the input array.
	char next;		//Each character in the input buffer will be held and considered using this handle.
	bool goodInput = true;

	cout << "Please type a positive number with less than " << MAX_INPUT_LENGTH << " digits, then press enter.\n";
	
	//Validates user data, then read input from buffer, populate a1 and a2 with user input data.
	do
	{
	cin.get(next);
	if (next == '-' || isdigit(next) == false)
	{
		goodInput = false;
		flushCin();
	}
	else
		goodInput = true;
	}while (goodInput == false);
	do
	{
		a1[index] = next - 48;
		index++;
		cin.get(next);
	}while((next != '\n') && (index < MAX_INPUT_LENGTH));
	liu1 = index - 1;
	index = 0;

	cout << "Please type a second positive number with less than " << MAX_INPUT_LENGTH << " digits, then press enter.\n";
	do
	{
	cin.get(next);
	if (next == '-' || isdigit(next) == false)
	{
		goodInput = false;
		flushCin();
	}
	else
		goodInput = true;
	}while (goodInput == false);
	do
	{
		a2[index] = next - 48;
		index++;
		cin.get(next);
	}while((next != '\n') && (index < MAX_INPUT_LENGTH));
	liu2 = index - 1;
	index = 0;
	cout << endl;

}

void reverseOrder(int a[], int liu)
{
	int temp;	//Holds the value to be swapped.
	
	for(int i = 0; i <= liu/2; i++)
	{
		temp = a[i];
		a[i] = a[liu - i];
		a[liu - i] = temp;
	}
}

void addEm(int a1[], int liu1, int a2[], int liu2, int sum[], int& liuSum)
{
	int carryOver = 0;	//If the result of an addition is greater than nine, this will be set to one.
	int max;			//The greatest of last indexies used between liu1 and liu2.

	if (liu1 > liu2)
		max = liu1;
	else
		max = liu2;

	for(int i = 0; i <= max; i++)
	{
		sum[i] = (a1[i] + a2[i] + carryOver)%10;
		carryOver = (a1[i] + a2[i] + carryOver)/10;
	}
	if(carryOver == 1 && max <= MAX_RESULT_LENGTH)
	{
		sum[max + 1] = carryOver;
		liuSum = max + 1;
	}
	if(carryOver == 0)
	liuSum = max;
}

void printarr(int arr[], int liu)
{
	for(int i = 0; i <= liu; i++)
		cout << arr[i];
	cout << endl;
}

void display(int add1[], int liu1, int add2[], int liu2, int sum[], int liuSum)
{
	//gives the resulting output a nice intuitve look.
		for(int i = 0; i <= ((MAX_INPUT_LENGTH - 1) - liu1); i++)
			cout << " ";
		printarr(add1, liu1);
		
		cout << "+";
		for(int i = 0; i <= ((MAX_INPUT_LENGTH - 2)- liu2); i++)
			cout << " ";
		printarr(add2, liu2);

		for(int i = 0; i <= (MAX_INPUT_LENGTH); i++)
			cout << "-";

		cout << "\n=";
		for(int i = 0; i <= ((MAX_RESULT_LENGTH - 2) - liuSum); i++)
			cout << " ";
		printarr(sum, liuSum);
}
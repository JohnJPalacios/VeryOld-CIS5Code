//Palacios_ch9_4.cpp, aka "Back talk."
//This program accepts a cstring, then returns the input in reverse order.
//John Palacios
//05-13-2013

#include<iostream>
#include<cstring>
using namespace std;

void backtalk(char input[]);
//precondition: input is a cstring object populated with user input.
//Postcondition: input is returned in reverse order.

int main()
{
	char input[100];

		cout << "Please type 100 characters or less to be reversed, then press enter.\n";
		cin.getline(input, 100);
		backtalk(input);
		cout << input << endl;
}

void backtalk(char input[])
{
	int size = strlen(input);			//number of used spaces in cstring input.
	char *front = input;				//pointer pointing at the first of the two index addresses.
	char *rear = &input[size - 1];		//pointer pointing at the last of the two index addresses.
	char temp;							//temporary memory location for first, while juggling values.

	for(int i = 0; i < size/2; i++)
	{
		temp = *front;
		*front = *rear;
		*rear = temp;
		front++;
		rear--;
	}
}
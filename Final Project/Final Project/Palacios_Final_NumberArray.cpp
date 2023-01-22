//Palacios_Final_NumberArray.cpp class implementation
//This is the class inplementation for the object created in main of Palacios_Final.cpp
//Programmer: John Palacios.
//06-01-2013

#include<iostream>
#include<fstream>
#include<cstdlib>
#include "Palacios_Final_NumberArray.h"
using namespace std;

//Implementation of class NumberArray.
NumberArray::NumberArray()
{
	int magnitude = 0;
	int randSeed = 0;
}

void NumberArray::setMag(int size)
{
	//Preventing over usage of free store memory, gaurding against unreferenced memory
	//and dangling pointers.
	if(magnitude > 0)
		recycleArray();

	if (size < 1)
	{
		magnitude = 1;
		cout << "There is now one element in this array.\n";
	}
	else
	{
		magnitude = size;
	}
}

void NumberArray::setSeed(int seed)
{
	randSeed = seed;
}

void NumberArray::genArray()
{
	randArray = new int[magnitude];
	srand(randSeed);
	int num;
	for(int i=0; i<magnitude; i++)
	{
		num = ((rand()%20)+1)*5;
		randArray[i] = num;
	}

}

void NumberArray::saveArray()
{

	ofstream saveFile;		//The output file stream variable.
	char fileName[65];		//The file name as entered by user.

	cout << "Please type a file name to save these values to (maximum 64 characters long):\n";
	cin >> fileName;
	cout << "Saving values to " << fileName << "...\n\n";
	saveFile.open(fileName);
	
	//Contingency for unavailability of memory.
	if(saveFile.fail())
	{
		cout << "Failure to open save file.";
		exit(1);
	}

	for(int i = 0; i < magnitude -1; i++)
		saveFile << randArray[i] << endl;
	saveFile << randArray[magnitude - 1];

	saveFile.close();
	
	cout << "Values successfully saved in " << fileName << ".\n";

}

void NumberArray::loadArray()
{
	ifstream targetFile;		//input file stream variable.
	char fileName[65];			//input file designated by user.
	int num;					//individual value from user specified input file.
	int size = 0;				//The number of values in the input file.

	cout << "Please type a file name to load values from (maximum 64 characters long):\n";
	cin >> fileName;
	cout << "loading values from " << fileName << "...\n\n";
	targetFile.open(fileName);
	if(targetFile.fail())
	{
		cout << "Failure to open target file.";
		exit(1);
	}
	
	//Checks the number of values contained in targetFile.
	while(targetFile >> num)
		size ++;

	targetFile.close();
	targetFile.clear();

	targetFile.open(fileName);
	if(targetFile.fail())
	{
		cout << "Failure to open target file upon second attempt.";
		exit(1);
	}
	
	setMag(size);
	randArray = new int[magnitude];
	
	targetFile >> num;
	for(int i=0; i<magnitude; i++)
	{
		randArray[i] = num;
		targetFile >> num;
	}

	targetFile.close();
	targetFile.clear();

	cout << "Values successfully loaded from " << fileName << ".\n";
}

void NumberArray::sortArray()
{
	if(magnitude < 1)
	{
		cout << "There are no values to sort yet, please load or create some.\n";
	}
	else
	{
    int lesserValueIndex;	//This will be the index of the lesser value in randArray.

    for (int i = 0; i < magnitude - 1; i++)
    {
        lesserValueIndex = positionLeast(i);
        interchange(randArray[i], randArray[lesserValueIndex]);
    }
	}
}

int NumberArray::positionLeast(int presentIndex)
{

	int min = randArray[presentIndex];	//smallest value of comparison.
	int	index = presentIndex;			//index of smallest value.

	for (int i = presentIndex + 1; i < magnitude; i++)
		if (randArray[i] < min)
		{
			min = randArray[i];
			index = i;
		}

		return index;
}

void NumberArray::interchange(int& v1, int& v2)
{
	int temp;		//Temporary variable to facilitate interchanging of v1 and v2.

	temp = v1;
	v1 = v2;
	v2 = temp;
}

void NumberArray::displayArray()
{
	if(magnitude < 1)
		cout << "There are no values to display yet. Please load or create some.\n";
	else
	{
	for(int i=0; i<magnitude - 1; i++)
		cout << randArray[i] << " | ";
	cout << randArray[magnitude - 1];
	cout << endl;
	}
}

void NumberArray::recycleArray()
{
	delete [] randArray;
	randArray = NULL;
}
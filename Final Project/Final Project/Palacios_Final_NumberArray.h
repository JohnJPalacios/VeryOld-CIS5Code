//Palacios_Final_NumberArray_HeaderFile.h
//This is the interface file for the NumberArray class used in Palacios_Final.cpp.
//Programmer: John Palacios.
//06-01-2013

class NumberArray
{
private:
	int *randArray;		//pointer handle for dynamic array of possibly psuedo random numbers.
	int magnitude;		//The "Magnitude" is the number of elements in initialized randArray.
	int randSeed;		//This is the number used to 'seed' the random number gen.

	void interchange(int& v1, int& v2);
	//Precondition: v1 and v2 are intager values.
	//postcondition: v1 now holds v2's value, and v2 now holds v1's value.

	int positionLeast(int presentIndex);
	//precondition: Object of class NumberArray has been initialized, private data member
	//randArray has been populated with int values, and presentIndex is an int value representing
	//an index of randArray.
	//postcondition: return first index which holds a value less than the value at presentIndex.

	void recycleArray();
	//Precondition: Object of class NumberArray has been initialized and randArray
	//has been generated/loaded from external file.
	//Postcondition: data member *randArray is deleted and grounded.

public:
	NumberArray();
	//Precondition: none.
	//Postcondition: an object of class NumberArray is initialized.

	void setMag(int size);
	//Precondition: Object of class NumberArray has been initialized.
	//Postcondition: private data member magnitude has been set to size.

	void setSeed(int seed);
	//Precondition: Object of class NumberArray has been initialized.
	//Postcondition: private data member randSeed has been set to seed.

	void genArray();
	//Precondition: Object of class NumberArray has been initialized, private data member
	//magnitude has been set to a positive int value and private data member randSeed has been
	//set to some int value.
	//Postcondition: Private data member randArray has magnitude elements filled with random multiples
	//of five from 5 to 100 generated with private data member randSeed as a seed value.

	void saveArray();
	//Precondition: Object of class NumberArray has been initialized and private data member
	//randArray points to some int array object.
	//Postcondition: element values of randArray are saved to saveFile, where saveFile is a file
	//name passed to the function, if no such file exists within the local directory, saveFile
	//is created in the local directory.

	void loadArray();
	//Precondition: Object of class NumberArray has been initialized, and targetFile exists
	//in the local directory.
	//Postcondition: randArray has elements populated with int values from targetFile.

	void sortArray();
	//precondition: Object of class NumberArray has been initialized, and private data member
	//randArray has been populated with int values.
	//postcondition: randArray's values have been rearanged so that the values are set from lowest
	//to highest.

	void displayArray();
	//Precondition: Object of class NumberArray has been initialized, and private data member
	//randArray has been populated with integer values.
	//Postcondition: vlaues stored in magnitude elements of randArray are printed to the console.

	
};
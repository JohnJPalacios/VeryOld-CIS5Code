//Palacios_ch6_9 aka "Fate diviner"
//This application computes overal grades.
//John Palacios
//04-17-2013

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;

void computeAverage(ifstream& input, ofstream& output);
//input is a file with a space seperated list of names followed by ten scores.
//computeAverage computes the average for those ten scores and stores these results
//in a file passed as output.

int main()
{
	ifstream input;
	ofstream output;
	
	//connects input to scores, and checks for success.
	input.open("scores.txt");
	if (input.fail())
	{
		cout << "Error at open input file, aborting process.\n";
		exit(1);
	}
	
	//connects or creates output file.
	output.open("grades.txt");

	do
	computeAverage(input, output);
	while (!input.eof());

	input.close();
	output.close();
	cout << "Process complete; end of program.\n";

	return 0;

}


void computeAverage(ifstream& input, ofstream& output)
{
	string name;
	int score;
	int total = 0;
	double average;

	//while (!input.eof())
	{
		input >> name;
		output << name << " ";
		input >> name;
		output << name << " ";

		for(int count = 1; count <= 10; count++)
		{
			input >> score;
			output << score << " ";
			total += score;
		}
		
		average = total/10.0;

		output.setf(ios::fixed);
		output.setf(ios::showpoint);
		output.precision(2);

		output << average << endl;
		//total = 0;

		return;
	}
}
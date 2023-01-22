//Palacios_ch9_13 aka "Babalonian to modern times"
//this small application will translate a time typed in at the console from 12 hour time to 24 hour time.
//John Palacios
//05-13-2013

#include<iostream>
#include<string>
using namespace std;

string convertToTwentyfourHour(string input);
//Precondition: input is a time with the format hh:mm am or hh:mm pm where the time may have one or two digit hours.
//postcondition: convertToTwentyfourHour returns a strying type time in 24 hour time hhmm.

int main()
{
	string input;		//User's input string.
	cout << "Please enter a time in the format of hh:mm am or hh:mm pm.\n";
	getline(cin, input);
	cout << "Your time of: " << input << " is ";
	cout << convertToTwentyfourHour(input) << " in 24 hour time.\n";

	return 0;
}

string convertToTwentyfourHour(string input)
{
	bool beforeCollon = true;				//Keeps track of where we are in the string in regard to the expected collon.
	char ampm = input[input.size() - 2];	//Used to determin half of day time belongs to.
	string hrs;								//Hour portion of output.
	string mins;							//Minute portion of output.
	string time;							//string containing both hours and minutes.
	int indexhrs = 0;						//used to track position in hrs string.
	int indexmins = 0;						//used to track position in minutes string.

	//seperate hours and minutes fromt he rest of the string.
	for(int i = 0; i < input.size(); i++)
	{
		if(isdigit(input[i]))
		{
		if(beforeCollon)
			hrs.insert(indexhrs++, 1, input[i]);
		else
			mins.insert(indexmins++, 1, input[i]);
		}
		else if(input[i] == ':')
		beforeCollon = false;
	}

	//crude but effective method to match the appropriate output with given input.
	if(ampm == 'p')
	{
		if(hrs == "12")
			hrs = hrs;
		else if(hrs == "01" || hrs == "1")
			hrs = "13";
		else if(hrs == "02" || hrs == "2")
			hrs = "14";
		else if(hrs == "03" || hrs == "3")
			hrs = "15";
		else if(hrs == "04" || hrs == "4")
			hrs = "16";
		else if(hrs == "05" || hrs == "5")
			hrs = "17";
		else if(hrs == "06" || hrs == "6")
			hrs = "18";
		else if(hrs == "07" || hrs == "7")
			hrs = "19";
		else if(hrs == "08" || hrs == "8")
			hrs = "20";
		else if(hrs == "09" || hrs == "9")
			hrs = "21";
		else if(hrs == "10")
			hrs = "22";
		else if(hrs == "11")
			hrs = "23";
		else
			hrs = "Eror: Unknown hour ";
	}
	if(ampm == 'a' && hrs == "12")
		hrs = "24";

	time = hrs + mins;
	return time;
}


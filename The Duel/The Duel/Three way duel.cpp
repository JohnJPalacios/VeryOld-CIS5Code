//Three way duel.
//This application simulates a duel to the death between three contestants.
//John Palacios
//03-30-2013

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

	const double aaronAccuracy = 1/3.0;	//aaron's accuracy.
	const double aaronMiss = 0.0;		//Aaron intentionally misses.
	const double bobAccuracy = 1/2.0;	//bob's accuracy.
	const double charlieAccuracy = 1.0;	//charlie never misses.

void shoot(bool& targetAlive, double accuracy);
//Precondition: targetAlive is true, 0 > accuracy => 1.
//Postcondition: if accuracy > rand, targetAlive is false.

int startDuel(bool& contestant1, bool& contestant2, bool& contestant3);
//precondition: contestant1, 2, and 3 are true.
//postcondition: only one contestant is true, return string with name of contestant true.

//test program for function shoot.
int main()
{
	//char answer;					//user's answer to "test again" in manual loops.
	bool aaronAlive = true;			//aaron's state
	bool bobAlive = true;			//bob's state
	bool charlieAlive = true;		//Charlie's state.
	int result;						//This indicates which contestant won the duel.
	//int hitCharlie = 0;			  //accumulates the number of times charlie has been hit.
	string winner;					//The name of the victor of any one dual.
	int aaronVictories = 0;			//The number of times Arron was last man standing.
	int bobVictories = 0;			//The number of times Bob was the last man standing.
	int charlieVictories = 0;		//The number of times Charlie was the last man standing.
	double duels = 10000.0;			//The number of times the dual will be run.
	double aaronOdds;				//The chance that Aaron will win.
	double bobOdds;					//The chance that Bob will win.
	double charlieOdds;				//The chance that Charlie will win.
	srand(time(0));


	for (int count = 1; count <= duels; count++)
	{
		
		result = startDuel(aaronAlive, bobAlive, charlieAlive);
		switch (result)
		{
		case 1:
			winner = "Aaron.\n";
			aaronVictories += 1;
			break;
		case 2:
			winner = "Bob.\n";
			bobVictories += 1;
			break;
		case 3:
			winner = "Charlie.\n";
			charlieVictories += 1;
			break;
		default:
			winner = "...um, no one.\n";
			cout << "Result number " << result << endl;
		}
		/*cout << "Duel number: " << count << ".\n"
			 << "The winner is: " << winner << endl
			 << "Resurrecting the contestants...\n";*/
		aaronAlive = true;
		bobAlive = true;
		charlieAlive = true;
	}
	
	aaronOdds = (aaronVictories / duels) * 100;
	bobOdds = (bobVictories / duels) * 100;
	charlieOdds = (charlieVictories / duels) *100;

	cout << "When each contestant shoots at the most accurate\n"
		<< "contestant alive and Aaron intentionally misses\n"
		<< "On the first round...\n"
		<< "Odds of Aaron winning: " << aaronOdds << "%.\n"
		<< "Odds of Bob winning: " << bobOdds << "%.\n"
		<< "Odds of Charlie winning: " << charlieOdds << "%.\n";

}

void shoot(bool& targetAlive, double accuracy)
{
	double bulletVector = (rand() % 101) / 100.0;

	if (bulletVector < accuracy)
		targetAlive = false;

	return;
}

int startDuel(bool& contestant1, bool& contestant2, bool& contestant3)
{
	int result = 0;

	do
	{
		if (contestant1 && contestant3 && contestant2)
			shoot(contestant3, aaronMiss);

		else if (contestant1)
		{		
			if (contestant3)
				shoot(contestant3, aaronAccuracy);

			if (contestant2)
				shoot(contestant2, aaronAccuracy);
			
			if (!contestant3 && !contestant2)
				result = 1;
		}
		if (contestant2)
		{
			if (contestant3)
				shoot(contestant3, bobAccuracy);
			
			else if (contestant1)
				shoot(contestant1, bobAccuracy);
			
			if (!contestant3 && !contestant1)
				result = 2;
		}
		if (contestant3)
		{
			if (contestant2)
				shoot(contestant2, charlieAccuracy);
			
			else if (contestant1)
				shoot(contestant1, charlieAccuracy);
			
			if (!contestant2 && !contestant1)
				result = 3;
		}
	}while ((contestant1 && contestant2) || ( contestant2 && contestant3) || (contestant1 && contestant3));

	return result;
}
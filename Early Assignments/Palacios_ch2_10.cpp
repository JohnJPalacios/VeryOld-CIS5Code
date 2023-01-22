//Ten sum
//Ten sum is a lightweight application that returns the sum of ten integers entered by the user.
//John Palacios
//03-06-2013

#include<iostream>        
using namespace std;

int main()
{
    int counter = 0;    
	//Counter counts the number of itterations.
    int sumPos = 0;        
	//sumPos accumulates the positive integers entered by the user.
    int sumNeg = 0;        
	//sumNeg accumulates the negative integers entered by the user.
    int inNum = 0;        
	//inNum is the variable I am using to hold the user input each itteration.
    int totalSum = 0;    
	//totalSum combines the final values of sumPos and sumNeg after the do-while loop.

    do                    
	//A do-while loop to ask the user for input data ten times.
    {
        cout << "Please type an integer, and then press return.\n";
        cin >> inNum;    
        if (inNum > 0)    
		//If inNum is positive, then it will be added to sumPos.
        {
            sumPos += inNum;
        }
        else            
		//otherwise; inNum will be added to sumNeg.
        {
            sumNeg += inNum;
        }
        counter ++;    
    }while (counter < 10);    
    
    totalSum = sumPos + sumNeg;    
	//Compute the total of both positive and negative numbers entered by the user.
    cout << "The sum of positive numbers = " << sumPos << ".\n"; 
	//display positive total.
    cout << "The sum of negative numbers = " << sumNeg << ".\n"; 
	//display the negative total.
    cout << "The sum of both positive and negative numbers is " << totalSum << ".\n"; 
	//Display the sum of negative and positive numbers.
    return 0;
}
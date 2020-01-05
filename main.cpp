// Izzy Ehnes
// CS 10B, Section 3031
// a7_1.cpp
// 10/8/18
//
// DESCRIPTION:
// This program asks the user the amount of scores they will enter,
// as well as the names of the scorers and their corresponding score.
// It then sorts the scores in ascending order and ranks the names
// from highest to lowest score and prints the results to the screen.



#include <iostream>
using namespace std;



struct highscore
{
	int score;
	char name[24];
};



void initializeData(highscore scores[], int size);
void sortData(highscore scores[], int size);
void displayData(const highscore scores[], int size);



int main()
{
	int size = 0;
	
	cout << "How many scores will you enter?: ";
	cin >> size;

	highscore scores[size];
	
	initializeData(scores, size);
	sortData(scores, size);
	displayData(scores, size);
		
	
	return 0;
}






//**********************************************************
// The initializeData function takes user input and stores *
// the values in the struct array 'highscore scores[].'    *
//**********************************************************

void initializeData(highscore scores[], int size)
{
	int score = 0;

	for(int count = 0; count < size; count++)
	{
		cout << "\nEnter the name for score #" << (count + 1) << ": ";
		cin.ignore();
		cin.getline(scores[count].name, 24);

		cout << "Enter the score for score #" << (count + 1) << ": ";
		cin >> score;
		scores[count].score = score;
	}
	
}






//*************************************************
// The sortData function sorts the incoming array *
// 'highscore scores[]' in ascending order        *
//*************************************************

void sortData(highscore scores[], int size)
{
	bool swap;
	highscore temp;

	do
	{
	    swap = false;
	    
	    for (int count = 0; count < (size - 1); count++)
	    {
	        if (scores[count].score < scores[count + 1].score)
	        {
	        	temp = scores[count];
				scores[count] = scores[count + 1];
				scores[count + 1] = temp;
	            swap = true;
	        }
	    }
	} while (swap);
}






//*****************************************************
// The displayData function outputs the data, which   *
// has been sorted so the highest score is at the top *
//*****************************************************

void displayData(const highscore scores[], int size)
{
	cout << "\nTop scorers: \n";
	
	for (int count = 0; count < size; count++)
	{
		cout << scores[count].name << ": ";
		cout << scores[count].score << endl;
	}
}






/* SAMPLE OUTPUT:

How many scores will you enter?:  5
Enter the name for score #1:  Dee
Enter the score for score #1:  200
Enter the name for score #2:  Frank
Enter the score for score #2:  400
Enter the name for score #3:  Charlie
Enter the score for score #3:  -100
Enter the name for score #4:  Dennis
Enter the score for score #4:  300
Enter the name for score #5:  Mac
Enter the score for score #5:  100

Top scorers: 
Frank: 400
Dennis: 300
Dee: 200
Mac: 100
Charlie: -100

*/
/*
 Author: <Yida Wang>
 Date Last Modified: <March 3rd, 2020>

 Description:
 The purpose of this project is to learn about class and object
 in C++. We are creating a RobotSwarm class that will manage
 a group of Robot objects, letting them move around within a
 grid without colliding with one another. The output of this
 program will be a text file containing a record of each 
 Robot object's history footprint - the locations it touched
 on the grid and the number of times it touched the points 
 on the grid.
 This is the main function of the RobotSwarm Lab.
*/

#include <fstream>
#include <iostream>
#include "Robot.h"
#include "RobotSwarm.h"
#include <time.h>

using namespace std;

int main()
{
	// declare number of moves and robots
	int numMoves;
	int numRobots;
	// seed the random number generator using the current time
	srand(time(NULL));

	// prompt for # robots
	cout << "Enter number of robots: ";
	cin >> numRobots;
	// safety to prevent user enter more than 512 robots
	// Dr. Hurley said the maximum number of robot should
	// be less than (32*32)/2 in class
	while (numRobots > 512)
	{
		cout << "Please enter number of robots less than 512: ";
		cin >> numRobots;
	}
	// prompt for # moves
	cout << "Enter number of moves: ";
	cin >> numMoves;

	// create a RobotSwarm class call mySwarm
	// with input parameter numRobots
	RobotSwarm mySwarm(numRobots);
	// loop through number of moves for mySwarm
	for (int ii = 0; ii < numMoves; ++ii)
	{
		mySwarm.MoveSwarm();
	}

	// output the Robot object's history
	mySwarm.printHistory();
}
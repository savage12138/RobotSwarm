/*
 Author: <Yida Wang>
 Date Last Modified: <March 3rd, 2020>

 Description:
 This is the RobotSwarm class file. This file contains all the
 implementation of RobotSwarm's member variables and 
 functions.
 */
#include <fstream>
#include <iostream>
#include "Robot.h"
#include "RobotSwarm.h"

// RobotSwarm constructor
RobotSwarm::RobotSwarm(int numRobots)
{
	// Initialize the vector of robots
	vecRobots.resize(numRobots);
	// Loop through all the Robots
	for (Robot& robot : vecRobots)
	{
		// Initialize (random position of robots)
		robot.SetInitialPos(vecRobots);
	}
}		
// This function moves all the robots
void RobotSwarm::MoveSwarm()
{
	// loop through vecRobot
	for (Robot& robot : vecRobots)
	{
		// call the member function move
		robot.move(vecRobots);
	}
}
// This function generate the final output
void RobotSwarm::printHistory()
{
	// initialize a counter for Robot index
	int count = 0;
	// open file
	fstream outfile;
	outfile.open("robotOutput.txt", ios::out | ios::trunc);
	// loop through vecRobot
	for (Robot& robot : vecRobots)
	{
		// for printHistory, need index and output
		robot.printHistory(outfile, count);
		count++;
	}
	// close the file
	outfile.close();
}

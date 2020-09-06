/*
 Author: <Yida Wang>
 Date Last Modified: <March 3rd, 2020>

 Description:
 This is the Robot class file. This file contains all the
 implementation of Robot object's member variables and 
 functions.
 */
#include <iostream>
#include <fstream>
#include "Robot.h"
#include "RobotSwarm.h"

// Robot class constructor
// initializing member variables
Robot::Robot() :
	xPosition(0),
	yPosition(0)
{
	// loop to initialize grid for each robot object
	for (int i = 0; i < GRID_SIZE; ++i)
	{
		for (int j = 0; j < GRID_SIZE; ++j)
		{
			grid[i][j] = { 0 };
		}
	}
}
// This function randomly sets the initial position
// of the each robot object while avoid overlapping
// other robot objects
void Robot::SetInitialPos(vector<Robot>& robots)
{
	// assume we have not found a robot at a new location
	bool bIsFound = false;
	// while there is no robot at the new location
	while (!bIsFound)
	{
		// Random i from 0 to 31
		int i = rand() % (GRID_SIZE - 1);
		// Random j from 0 to 31
		int j = rand() % (GRID_SIZE - 1);
		// loop through robots to see if anyone is at
		// the random generated location
		for (Robot& robot : robots)
		{
			// check to see if there is any robot's x and y 
			// are equal to i and j
			if (robot.getXPosition() == i && robot.getYPosition() == j)
			{
				bIsFound = true;
				// if any one of the robot is at i and j,
				// break the for loop
				break;
			}
		}
		// this if statement is true when there is a robot
		// at the generated i and j position
		// so set it back to false and regenerate i and j
		if (bIsFound)
		{
			bIsFound = false;
		}
		// if the above if statement is false, there is no
		// robot at the generated i and j position
		// so set the new robot to be there
		else
		{
			xPosition = i;
			yPosition = j;
			// increment the grid initially
			// this is the very first position of 
			// the new robot
			grid[xPosition][yPosition] = { 1 };
			// break out the while loop
			break;
		}
	}
}
// x Position Setter 
bool Robot::setXPosition(int inX)
{
	xPosition = inX;
	return true;
}
// y Position Setter
bool Robot::setYPosition(int inX)
{
	yPosition = inX;
	return true;
}
// x Position Getter
int Robot::getXPosition()
{
	return xPosition;
}
// y Position Getter
int Robot::getYPosition()
{
	return yPosition;
}
// This function randomly generate the direction
// the robot is going to move
void Robot::move(vector<Robot>& Robots)
{
	bool bMoved = false;
	// loop through 5 times to select random direction
	for (int k = 0; k < 5; ++k)
	{
		// initialize random direction from
		// 0 to 3
		int randDirection = rand() % 4;
		// 0 = Forward
		// 1 = Backward
		// 2 = Left
		// 3 = Right
		if (randDirection == 0)
		{
			if (moveForward(Robots))
			{
				bMoved = true;
				break;
			}
		}
		else if (randDirection == 1)
		{
			if (moveBackward(Robots))
			{
				bMoved = true;
				break;
			}
		}
		else if (randDirection == 2)
		{
			if (moveLeft(Robots))
			{
				bMoved = true;
				break;
			}
		}
		else if (randDirection == 3)
		{
			if (moveRight(Robots))
			{
				bMoved = true;
				break;
			}
		}
	}
	// if failed to move all five times
	// increment grid on current position
	if (!bMoved)
	{
		grid[getXPosition()][getYPosition()]++;
	}
	
}
// This function determines if a robot can move
// forward or not.
bool Robot::moveForward(vector<Robot> &Robots)
{
	// assume the forward spot is free
	bool bIsSpotFree = true;
	// getting the forward spot's x and y position
	int testX = getXPosition() - 1;
	int testY = getYPosition();
	// check the forward spot is not out of bounds
	if (testX < 0 || testX > (GRID_SIZE - 1) || testY < 0 || testY > (GRID_SIZE - 1))
	{
		return false;
	}
	// loop through all robots to make sure there
	// is no another robot at the forward position
	for (Robot& robot : Robots)
	{
		// compare x and y position
		if (robot.getXPosition() == testX && robot.getYPosition() == testY)
		{
			bIsSpotFree = false;
			break;
		}
	}
	// if there is spot available, set the robot's
	// new position and increment grid index
	if (bIsSpotFree)
	{
		setXPosition(testX);
		setYPosition(testY);
		grid[getXPosition()][getYPosition()]++;
		return bIsSpotFree;
	}
	// if there is no spot available, return false
	else
	{
		return bIsSpotFree;
	}
}
// This function determines if a robot can move
// backward or not.
bool Robot::moveBackward(vector<Robot>& Robots)
{
	// assume the Backward spot is free
	bool bIsSpotFree = true;
	// getting the Backward spot's x and y position
	int testX = getXPosition() + 1;
	int testY = getYPosition();
	// check the Backward spot is not out of bounds
	if (testX < 0 || testX > (GRID_SIZE - 1) || testY < 0 || testY > (GRID_SIZE - 1))
	{
		return false;
	}
	// loop through all robots to make sure there
	// is no another robot at the Backward position
	for (Robot& robot : Robots)
	{
		// compare x and y position
		if (robot.getXPosition() == testX && robot.getYPosition() == testY)
		{
			bIsSpotFree = false;
			break;
		}
	}
	// if there is spot available, set the robot's
	// new position and increment grid index
	if (bIsSpotFree)
	{
		setXPosition(testX);
		setYPosition(testY);
		grid[getXPosition()][getYPosition()]++;
		return bIsSpotFree;
	}
	// if there is no spot available, return false
	else
	{
		return bIsSpotFree;
	}
}
// This function determines if a robot can move
// left or not.
bool Robot::moveLeft(vector<Robot>& Robots)
{
	// assume the left spot is free
	bool bIsSpotFree = true;
	// getting the left spot's x and y position
	int testX = getXPosition();
	int testY = getYPosition() - 1;
	// check the left spot is not out of bounds
	if (testX < 0 || testX > (GRID_SIZE - 1) || testY < 0 || testY > (GRID_SIZE - 1))
	{
		return false;
	}
	// loop through all robots to make sure there
	// is no another robot at the left position
	for (Robot& robot : Robots)
	{
		// compare x and y position
		if (robot.getXPosition() == testX && robot.getYPosition() == testY)
		{
			bIsSpotFree = false;
			break;
		}
	}
	// if there is spot available, set the robot's
	// new position and increment grid index
	if (bIsSpotFree)
	{
		setXPosition(testX);
		setYPosition(testY);
		grid[getXPosition()][getYPosition()]++;
		return bIsSpotFree;
	}
	// if there is no spot available, return false
	else
	{
		return bIsSpotFree;
	}
}
// This function determines if a robot can move
// right or not.
bool Robot::moveRight(vector<Robot>& Robots)
{
	// assume the right spot is free
	bool bIsSpotFree = true;
	// getting the right spot's x and y position
	int testX = getXPosition();
	int testY = getYPosition() + 1;
	// check the right spot is not out of bounds
	if (testX < 0 || testX > (GRID_SIZE - 1) || testY < 0 || testY > (GRID_SIZE - 1))
	{
		return false;
	}
	// loop through all robots to make sure there
	// is no another robot at the right position
	for (Robot& robot : Robots)
	{
		// compare x and y position
		if (robot.getXPosition() == testX && robot.getYPosition() == testY)
		{
			bIsSpotFree = false;
			break;
		}
	}
	// if there is spot available, set the robot's
	// new position and increment grid index
	if (bIsSpotFree)
	{
		setXPosition(testX);
		setYPosition(testY);
		grid[getXPosition()][getYPosition()]++;
		return bIsSpotFree;
	}
	// if there is no spot available, return false
	else
	{
		return bIsSpotFree;
	}
}
// This function display the current robot position
void Robot::displayPosition()
{
	getXPosition();
	getYPosition();
	cout << "The current position is at ";
	cout << xPosition << ", " << yPosition << endl;
}
// This function outputs all the values in grid array
bool Robot::printHistory(fstream& outfile, int index)
{
	outfile << "Robot" << index << "\n";
	// loop through all index in grid
	for (int ii = 0; ii < GRID_SIZE; ++ii)
	{
		for (int jj = 0; jj < GRID_SIZE; ++jj)
		{
			outfile << grid[ii][jj] << "\t";
		}
		outfile << endl;
		outfile << endl;
	}
	return true;
}
// This function prompt the user for the next move of the robot
// only used for debug purpose
void Robot::inputMove(vector<Robot>& vecRobot)
{
	string a;
	cout << "Valid inputs: forward, backward, left, right." << endl;
	cout << "Enter the direction: ";
	cin >> a;
	if (a == "forward")
	{
		moveForward(vecRobot);
	}
	else if (a == "backward")
	{
		moveBackward(vecRobot);
	}
	else if (a == "left")
	{
		moveLeft(vecRobot);
	}
	else if (a == "right")
	{
		moveRight(vecRobot);
	}
	else
	{
		cout << "invalid input" << endl;
		inputMove(vecRobot);
	}
}
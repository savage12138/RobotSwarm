/*
 Author: <Yida Wang>
 Date Last Modified: <March 3rd, 2020>

 Description:
 This is the RobotSwarm header file. This file contains
 the declaration of all the member variable and functions
 */
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Robot.h"
using namespace std;
class RobotSwarm
{
public:
	RobotSwarm(int);
	void MoveSwarm();
	void printHistory();

private:
    vector<Robot> vecRobots;
};
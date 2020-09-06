/*
 Author: <Yida Wang>
 Date Last Modified: <March 3rd, 2020>

 Description:
 This is the Robot header file. This file contains
 the declaration of all the member variable and functions
 */
#pragma once
#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#define GRID_SIZE 32	// define 32x32 grid size

using namespace std;

class Robot
{
public:
	Robot();
	bool setXPosition(int);
	bool setYPosition(int);
	int getXPosition();
	int getYPosition();
	void move(vector<Robot>& robot);
	bool moveForward(vector<Robot>& vecRobot);
	bool moveLeft(vector<Robot>& vecRobot);
	bool moveRight(vector<Robot>& vecRobot);
	bool moveBackward(vector<Robot>& vecRobot);
	void inputMove(vector<Robot>& vecRobot);
	void displayPosition();
	bool printHistory(fstream& outfile, int index);
	void SetInitialPos(vector<Robot>& robot);

private:
	int xPosition;
	int yPosition;
	int grid[GRID_SIZE][GRID_SIZE];
	// array <array<int, GRID_SIZE>, GRID_SIZE> grid;
};
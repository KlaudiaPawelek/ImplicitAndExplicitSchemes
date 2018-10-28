#include "matrix.h"
#include "vector.h"
#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
#pragma once

//this is abstract class
class Scheme 
{
protected:
	Matrix matrix, analyticalSolution;
	int sizeOfMatrix, sizeT, sizeX;
	double deltaT, deltaX;

	//constant values
	const double PI = atan(1) * 4;
	const double u = 250; //value from excercise 250 m/s

public:
	
	//default constructor
	Scheme();

	//pure virtual method => so this is abstract class
	//this is not the best, but we can show, that we understand abstract class in c++ bla bla bla
	virtual void PrintResult() = 0;
	
	//some methods, which can be implemented in this 'mother' class
	//because for implicit and explicit scheme there are the same
	void InitialCondition();
	void AnalyticalSolution();
	void BoundryCondition();
	void InsertDeltaT();
	void ComputeSizeOfMatrix();
	void SaveResultIntoFiles(double deltaT, string schemeName);
	
	//accessor
	Matrix GetMatrix();
	double GetDeltaT();

	//special function useful in command line, which is visible only inside of this class
	friend int IsDouble(string input);

	//virtual destructor, this is necessary 
	virtual ~Scheme() {}
};


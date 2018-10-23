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

//this is abstrac class
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

	//pure virtual methods (like template)
	//these classes must be implemented in ImplicitScheme class and ExplicitScheme class
	//probably these classes will be different in implicit and explicit
	//this is only idea, how to use some elements from C++ to our project
	virtual void PrintResult() = 0;
	virtual void SaveResultIntoFiles() = 0;

	
	//some methods, which can be implemented in this 'mother' class
	//because for implicit and explicit scheme there are the same
	void InitialCondition();
	void AnalyticalSolution();
	void BoundryCondition();
	void InsertDeltaT();
	void ComputeSizeOfMatrix();
	virtual void Norms();

	//accessor
	Matrix GetMatrix();

	//special function useful in command line, which is visible only inside of this class
	friend int IsDouble(string input);

	//virtual destructor, this is necessary 
	virtual ~Scheme() {}
};


#include <iostream>
#include "matrix.h"
#include "vector.h"
#pragma once

class Scheme 
{
protected:
	Matrix matrix;
	int sizeOfMatrix, sizeT, sizeX;
	double deltaT, deltaX;
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
	void ComputeSizeOfMatrix(double deltaT);
	virtual void Norms();

	//accessor
	Matrix GetMatrix();

	//virtual destructor, this is necessary 
	virtual ~Scheme() {}
};


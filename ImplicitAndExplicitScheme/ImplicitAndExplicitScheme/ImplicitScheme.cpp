#include "ImplicitScheme.h"
#include "matrix.h"
#include "vector.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

ImplicitScheme::ImplicitScheme()
{
	//default constructor
}


// Method used to calculate the solution in both schemes
vector<double> ImplicitScheme::ThomasAlgoFTCS()
{ 
	//The following algorithm was made considering A the sub-diagonal, B the main diagonal, C the top/upper diagonal
	double alpha, m;
	this->A.resize(sizeX);
	this->B.resize(sizeX);
	this->C.resize(sizeX);
	this->D.resize(sizeX);
	vector<double> X(sizeX);

	alpha = u * (deltaT / deltaX);
	this->A[0] = 0.0;
	this->C[sizeX - 1] = 0;
	this->B[sizeX - 1] = 1;
	
	for (int k = 0; k < sizeX - 1; k++)
	{
		this->A[k + 1] = -(0.5)*alpha;
		this->B[k] = 1;
		this->C[k] = (0.5)*alpha;
	}

	for (int i = 1; i < sizeX; i++)
	{
		m = A[i] / B[i - 1];
		this->B[i] = this->B[i] - m * this->C[i - 1];
		D[i] = D[i] - m * D[i - 1];
	}

	X[sizeX - 1] = D[sizeX - 1] / this->B[sizeX - 1];

	for (int j = sizeX - 2; j >= 0; j--)
	{
		X[j] = (D[j] - this->C[j] * X[j + 1]) / this->B[j];
	}

	return X;

}

vector<double> ImplicitScheme::ThomasAlgoUpWindFTBS()
{
	double alpha, m;
	this->A.resize(sizeX);
	this->B.resize(sizeX);
	this->C.resize(sizeX);
	this->D.resize(sizeX);
	vector<double> X(sizeX);

	alpha = u * (deltaT / deltaX);
	this->A[0] = 0.0;
	this->C[sizeX - 1] = 0;
	this->B[sizeX - 1] = 1;

	for (int k = 0; k < sizeX - 1; k++)
	{
		this->A[k + 1] = (-1)*alpha;
		this->B[k] = 1 + alpha;
		this->C[k] = 0;
	}

	for (int i = 1; i < sizeX; i++)
	{
		m = A[i] / B[i - 1];
		this->B[i] = this->B[i] - m * this->C[i - 1];
		D[i] = D[i] - m * D[i - 1];
	}

	X[sizeX - 1] = D[sizeX - 1] / this->B[sizeX - 1];

	for (int j = sizeX - 2; j >= 0; j--)
	{
		X[j] = (D[j] - this->C[j] * X[j + 1]) / this->B[j];
	}

	return X;
}

//Implicit UpWind FTBS (Forward time, Backward space)
string ImplicitScheme::ImplicitUpWindFTBS()
{
	InsertDeltaT();
	ComputeSizeOfMatrix();
	InitialCondition();
	BoundryCondition();

	this->D = (*this).matrix[0];
	vector<double> tmp(sizeX);

	for (int i = 1; i < sizeT; i++)
	{
		tmp = ThomasAlgoUpWindFTBS(); //we create the vector containing values of the next time step
		this->matrix[i] = tmp;
		D = tmp; //we prepare the calculus of the following time step
	}
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

//Implicit FTCS(Forward time, Central space)
string ImplicitScheme::ImplicitFTCS()
{
	InsertDeltaT();
	ComputeSizeOfMatrix();
	InitialCondition();
	BoundryCondition();

	this->D = (*this).matrix[0];
	vector<double> tmp(sizeX);

	for (int i = 1; i < sizeT; i++)
	{
		tmp = ThomasAlgoFTCS(); //we create the vector containing values of the next time step
		this->matrix[i] = tmp;
		D = tmp; //we prepare the calculus of the following time step
		
	}
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

ImplicitScheme::~ImplicitScheme()
{
	// default destructor
}

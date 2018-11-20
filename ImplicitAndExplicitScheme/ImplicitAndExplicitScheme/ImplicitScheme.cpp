#include "ImplicitScheme.h"
using namespace std;

// Default, empty constructor
ImplicitScheme::ImplicitScheme(){ }

//Implementation of Thomas algorithm used in method string ImplicitScheme::ImplicitUpWindFTCS()
vector<double> ImplicitScheme::ThomasAlgoFTCS()
{ 
	//The following algorithm was made considering A the sub-diagonal, B the main diagonal, C the top/upper diagonal
	double alpha, m;
	this->A.resize(this->sizeX);
	this->B.resize(this->sizeX);
	this->C.resize(this->sizeX);
	this->D.resize(this->sizeX);
	vector<double> X(this->sizeX);

	alpha = u * (this->deltaT / this->deltaX);
	this->A[0] = 0.0;
	this->C[this->sizeX - 1] = 0;
	this->B[this->sizeX - 1] = 1;
	
	for (int k = 0; k < this->sizeX - 1; k++)
	{
		this->A[k + 1] = -(0.5)*alpha;
		this->B[k] = 1;
		this->C[k] = (0.5)*alpha;
	}

	for (int i = 1; i < this->sizeX; i++)
	{
		m = this->A[i] / this->B[i - 1];
		this->B[i] = this->B[i] - m * this->C[i - 1];
		this->D[i] = this->D[i] - m * this->D[i - 1];
	}

	X[this->sizeX - 1] = D[this->sizeX - 1] / this->B[this->sizeX - 1];

	for (int j = this->sizeX - 2; j >= 0; j--)
	{
		X[j] = (this->D[j] - this->C[j] * X[j + 1]) / this->B[j];
	}

	return X;

}

//Implementation of Thomas algorithm used in method string ImplicitScheme::ImplicitUpWindFTBS()
vector<double> ImplicitScheme::ThomasAlgoUpWindFTBS()
{
	//The following algorithm was made considering A the sub-diagonal, B the main diagonal, C the top/upper diagonal
	double alpha, m;
	this->A.resize(this->sizeX);
	this->B.resize(this->sizeX);
	this->C.resize(this->sizeX);
	this->D.resize(this->sizeX);
	vector<double> X(this->sizeX);

	alpha = u * (this->deltaT / this->deltaX);
	this->A[0] = 0.0;
	this->C[this->sizeX - 1] = 0;
	this->B[this->sizeX - 1] = 1;

	for (int k = 0; k < this->sizeX - 1; k++)
	{
		this->A[k + 1] = (-1)*alpha;
		this->B[k] = 1 + alpha;
		this->C[k] = 0;
	}

	for (int i = 1; i < this->sizeX; i++)
	{
		m = this->A[i] / this->B[i - 1];
		this->B[i] = this->B[i] - m * this->C[i - 1];
		this->D[i] = this->D[i] - m * this->D[i - 1];
	}

	X[this->sizeX - 1] = this->D[this->sizeX - 1] / this->B[this->sizeX - 1];

	for (int j = this->sizeX - 2; j >= 0; j--)
	{
		X[j] = (this->D[j] - this->C[j] * X[j + 1]) / this->B[j];
	}

	return X;
}

//Implicit UpWind Forward time Backward space
string ImplicitScheme::ImplicitUpWindFTBS()
{
	//------------------------ Preparig matrix ------------------------------------------//
	InsertDeltaT();			// insert deltaT in the console by user, from Scheme class
	ComputeSizeOfMatrix();	// compute size of matrix, from Scheme class
	InitialCondition();		// initial condition, from Scheme class
	BoundryCondition();		// boundry condition, from Scheme class
	//----------------------------------------------------------------------------------//

	//-------------------------Implicit scheme------------------------------------------//
	this->D = (*this).matrix[0];
	vector<double> tmp(this->sizeX);

	for (int i = 1; i < this->sizeT; i++)
	{
		tmp = ThomasAlgoUpWindFTBS();	//create the vector containing values of the next time step
		this->matrix[i] = tmp;
		this->D = tmp;					//prepare the calculus of the following time step
	}
	//----------------------------------------------------------------------------------//

	return __func__;					//return name of method -> useful for method SaveResultIntoFiles
}

//Implicit Forward time, Central space
string ImplicitScheme::ImplicitFTCS()
{
	//------------------------ Preparig matrix ------------------------------------------//
	InsertDeltaT();			// insert deltaT in the console by user, from Scheme class
	ComputeSizeOfMatrix();	// compute size of matrix, from Scheme class
	InitialCondition();		// initial condition, from Scheme class
	BoundryCondition();		// boundry condition, from Scheme class
	//----------------------------------------------------------------------------------//

	//-------------------------Implicit scheme------------------------------------------//
	this->D = (*this).matrix[0];
	vector<double> tmp(this->sizeX);

	for (int i = 1; i < this->sizeT; i++)
	{
		tmp = ThomasAlgoFTCS();		//create the vector containing values of the next time step
		this->matrix[i] = tmp;
		this->D = tmp;				//prepare the calculus of the following time step
		
	}
	return __func__;				//return name of method -> useful for method SaveResultIntoFiles
}

// Default, empty destructor
ImplicitScheme::~ImplicitScheme(){ }

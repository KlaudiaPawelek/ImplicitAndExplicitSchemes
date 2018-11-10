#include "ExplicitScheme.h"
#include "matrix.h"
#include "vector.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ExplicitScheme::ExplicitScheme()
{
	//default constructor
}

void ExplicitScheme::PrintResult()
{
	cout << "EXPLICIT" << endl;
	cout << this->matrix;
}

//Explicit Upwind FTBS (Forward time, Backward space)
string ExplicitScheme::ExplicitUpWindFTBS()
{
	InsertDeltaT();
	ComputeSizeOfMatrix();
	InitialCondition();
	BoundryCondition();

	for (int t = 1; t < this->sizeT; t++)
	{
		for (int x = 1; x < this->sizeX; x++)
		{
			this->matrix[t][x] = (1 - ((this->u*this->deltaT) / this->deltaX))*this->matrix[t - 1][x] + ((this->u*this->deltaT) / this->deltaX)*this->matrix[t - 1][x - 1];
		}
	}
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

//Explicit Lax-Wandroff
//This scheme is unstable for our equation!
string ExplicitScheme::ExplicitLaxWandroff()
{
	InsertDeltaT();
	ComputeSizeOfMatrix();
	InitialCondition();
	BoundryCondition();

	for (int t = 1; t < this->sizeT - 1; t++)
	{
		for (int x = 1; x < this->sizeX - 1; x++)
		{
			this->matrix[t][x] = (-1)*((this->u*this->deltaT) / (2 * this->deltaX))*(this->matrix[t - 1][x + 1] - this->matrix[t - 1][x - 1]) + this->matrix[t - 1][x];
		}
	}
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

ExplicitScheme::~ExplicitScheme()
{
	//default destructor
}

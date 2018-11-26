#include "ExplicitScheme.h"
using namespace std;

// Default, empty constructor
ExplicitScheme::ExplicitScheme(){ }


//Explicit Upwind Forward time, Backward space
string ExplicitScheme::ExplicitUpWindFTBS()
{
	//Preparig matrix ------//
	InsertDeltaT();			// insert deltaT in the console by user, from Scheme class
	ComputeSizeOfMatrix();	// compute size of matrix, from Scheme class
	InitialCondition();		// initial condition, from Scheme class
	BoundryCondition();		// boundry condition, from Scheme class
	//----------------------//

	//Explicit scheme----------------------//

	for (int t = 1; t < this->sizeT; t++)
	{
		for (int x = 1; x < this->sizeX-1; x++)
		{
			this->matrix[t][x] = (1 - ((this->u*this->deltaT) / this->deltaX))*this->matrix[t - 1][x] + 
				((this->u*this->deltaT) / this->deltaX)*this->matrix[t - 1][x - 1];
		}
	}
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

//Explicit Lax-Wandroff
string ExplicitScheme::ExplicitLaxWandroff()
{
	//Preparig matrix ------//
	InsertDeltaT();			// insert deltaT in the console by user, from Scheme class
	ComputeSizeOfMatrix();	// compute size of matrix, from Scheme class
	InitialCondition();		// initial condition, from Scheme class
	BoundryCondition();		// boundry condition, from Scheme class
	//----------------------//

	//Explicit scheme--------------------//
	for (int t = 1; t < this->sizeT; t++)
	{
		for (int x = 1; x < this->sizeX - 1; x++)
		{
			this->matrix[t][x] = (-1)*((this->u*this->deltaT) / (2 * this->deltaX))*(this->matrix[t - 1][x + 1] - this->matrix[t - 1][x - 1]) + 
				this->matrix[t - 1][x] + ((pow(this->u, 2)*pow(this->deltaT, 2)) /(2* pow(this->deltaX, 2)))*(this->matrix[t - 1][x + 1] - 2 * this->matrix[t - 1][x] + this->matrix[t - 1][x - 1]);
		}
	}
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

// Default, empty destructor
ExplicitScheme::~ExplicitScheme(){ }

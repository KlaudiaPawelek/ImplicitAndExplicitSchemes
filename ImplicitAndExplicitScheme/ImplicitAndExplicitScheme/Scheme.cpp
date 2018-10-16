#include "Scheme.h"

Scheme::Scheme()
{
	//default constructor
}

void Scheme::InitialCondition()
{
	for (int i = 0; i < (*this).matrix.getNcols(); i++)
	{
		(*this).matrix[][]
	}
}

void Scheme::BoundryCondition()
{
	//todo
}

void Scheme::AnalyticalSolution()
{
	//todo
}

//***************important!****************
// values like t, x etc. I got it from other labs to test my solution
// we have to change it -> get values, variables from project exercise
// this is something like template
void Scheme::ComputeSizeOfMatrix(double deltaT)
{
	double deltaX = 5.0; //5 meters
	int sizeT, sizeX;
	double x = 400; //from excercise; domain is xE[0;400] meters
	double u = 250; //value from excercise 250 m/s
	double t = 0.5; //from excercise t goes from 0.0 to 0.5sec


	//compute sizeX and sizeT, this is need to loops in functions
	sizeX = (x / deltaX) + 1;
	sizeT = (t / deltaT) + 1;

	//create&return empty Matrix with proper size
	Matrix m(sizeT, sizeX);
	this->matrix = m;
}

void Scheme::Norms()
{
	//todo
}

Matrix Scheme::GetMatrix()
{
	return this->matrix;
}

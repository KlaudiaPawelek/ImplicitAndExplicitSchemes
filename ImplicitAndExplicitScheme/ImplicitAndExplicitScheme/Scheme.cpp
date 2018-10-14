#include "Scheme.h"

Scheme::Scheme()
{
	//default constructor
}

void Scheme::InitialCondition()
{
	//todo
}

void Scheme::BoundryCondition()
{
	//todo
}

//***************important!****************
// values like t, x etc. I got it from other labs to test my solution
// we have to change it -> get values, variables from project exercise
// this is something like template
void Scheme::ComputeSizeOfMatrix(double deltaT, double t, double x, double u, double r)
{
	double deltaX;
	int sizeT, sizeX;

	u = 0.01; //value from excercise
	deltaT = 0.2; //constant value to ease!
	t = 10; //from excercise t=1.2, 5.2, 10
	x = 1; //from excercise; domain is xE[0;1]

	//compute delta X
	deltaX = sqrt((u*deltaT) / r);

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

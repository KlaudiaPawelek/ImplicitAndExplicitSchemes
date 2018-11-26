#include "ImplicitScheme.h"
using namespace std;

// Default, empty constructor
ImplicitScheme::ImplicitScheme(){ }

/*Implementation of Thomas algorithm used in method string ImplicitScheme::ImplicitUpWindFTBS() 
and string ImplicitScheme::ImplicitUpWindFTCS()*/
vector<double> ImplicitScheme::ThomasAlgorithm(double parameter, double parameter2, bool version)
{
	/*The following algorithm was made considering 
	A the sub-diagonal, B the main diagonal, C the top/upper diagonal*/
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

	if (version == 1) //for FTBS method
	{
		for (int x = 0; x < this->sizeX - 1; x++)
		{
			this->A[x + 1] = parameter * alpha;		//-1
			this->B[x] = 1 + alpha;				
			this->C[x] = parameter2;				//0		
		}
	}
	else if (version == 0) //for FTCS method
	{
		for (int x = 0; x < this->sizeX - 1; x++)
		{
			this->A[x + 1] = parameter * alpha;	//-0.5	
			this->B[x] = 1;
			this->C[x] = parameter2*alpha;		//0.5				
		}
	}

	for (int x = 1; x < this->sizeX-1; x++)
	{
		m = this->A[x] / this->B[x - 1];
		this->B[x] = this->B[x] - m * this->C[x - 1];
		this->D[x] = this->D[x] - m * this->D[x - 1];
	}

	X[this->sizeX - 1] = this->D[this->sizeX - 1] / this->B[this->sizeX - 1];

	for (int j = this->sizeX - 2; j >= 1; j--)
	{
		X[j] = (this->D[j] - this->C[j] * X[j + 1]) / this->B[j];
	}

	return X;
}

//Implicit UpWind Forward time Backward space
string ImplicitScheme::ImplicitUpWindFTBS()
{
	//Preparig matrix ----------------//
	InsertDeltaT();			// insert deltaT in the console by user, from Scheme class
	ComputeSizeOfMatrix();	// compute size of matrix, from Scheme class
	InitialCondition();		// initial condition, from Scheme class
	BoundryCondition();		// boundry condition, from Scheme class
	//--------------------------------//

	//Implicit scheme-----------------//
	this->D = (*this).matrix[0];
	vector<double> tmp(this->sizeX);

	for (int t = 1; t < this->sizeT; t++)
	{
		tmp = ThomasAlgorithm(-1.0,0.0,1); //create the vector containing values of the next time step
		this->matrix[t] = tmp;
		this->D = tmp;	//prepare the calculus of the following time step
	}
	//--------------------------------//

	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

//Implicit Forward time, Central space
string ImplicitScheme::ImplicitFTCS()
{
	//Preparig matrix ------//
	InsertDeltaT();			// insert deltaT in the console by user, from Scheme class
	ComputeSizeOfMatrix();	// compute size of matrix, from Scheme class
	InitialCondition();		// initial condition, from Scheme class
	BoundryCondition();		// boundry condition, from Scheme class
	//----------------------//

	//Implicit scheme-------//
	this->D = (*this).matrix[0];
	vector<double> tmp(this->sizeX);

	for (int t = 1; t < this->sizeT; t++)
	{
		tmp = ThomasAlgorithm(-0.5, 0.5, 0); //create the vector containing values of the next time step
		this->matrix[t] = tmp;
		this->D = tmp; //prepare the calculus of the following time step
		
	}
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

// Default, empty destructor
ImplicitScheme::~ImplicitScheme(){ }

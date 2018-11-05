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
	//cout << "EXPLICIT :" << endl;
	//cout << this->matrix;
	cout << "ANALYTICAL :" << endl;
	cout << this->analyticalSolution;
}

void ExplicitScheme::SaveResultIntoFiles()
{
	ofstream f;
	//f.open("ExplicitUpWindFTBS.txt");
	f.open("ExplicitLaxWandroff.txt");
	for (int t = 0; t < this->sizeT; t++)
	{
		for (int x = 0; x < this->sizeX; x++)
		{
			f << fixed << setprecision(5) << this->matrix[t][x] << " ";
		}
		f << endl;
	}
}

//Explicit Upwind FTBS (Forward time, Backward space)
void ExplicitScheme::ExplicitUpWindFTBS()
{
	for (int t = 1; t < this->sizeT; t++)
	{
		for (int x = 1; x < this->sizeX; x++)
		{
			this->matrix[t][x] = (1 - ((this->u*this->deltaT) / this->deltaX))*this->matrix[t - 1][x] + ((this->u*this->deltaT) / this->deltaX)*this->matrix[t - 1][x - 1];
		}
	}

}

//Explicit Lax-Wandroff
//This scheme is unstable for our equation!
void ExplicitScheme::ExplicitLaxWandroff()
{
	for (int t = 1; t < this->sizeT - 1; t++)
	{
		for (int x = 1; x < this->sizeX - 1; x++)
		{
			this->matrix[t][x] = (-1)*((this->u*this->deltaT) / (2 * this->deltaX))*(this->matrix[t - 1][x + 1] - this->matrix[t - 1][x - 1]) + this->matrix[t - 1][x];
		}
	}
}

ExplicitScheme::~ExplicitScheme()
{
	//default destructor
}

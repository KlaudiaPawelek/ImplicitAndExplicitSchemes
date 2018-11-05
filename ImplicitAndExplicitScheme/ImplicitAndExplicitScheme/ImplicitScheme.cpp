#include "ImplicitScheme.h"
#include "matrix.h"
#include "vector.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iterator>
using namespace std;

ImplicitScheme::ImplicitScheme()
{
	//default constructor
}


void ImplicitScheme::PrintResult()
{
	cout << endl << "IMPLICIT" << endl;
	cout << this->matrix;
}

void ImplicitScheme::SaveResultIntoFiles()
{
	ofstream f;
		//f.open("ImplicitUpWindFTBS.txt");
		f.open("ImplicitFTCS.txt");
	for (int t = 0; t < this->sizeT; t++)
	{
		for (int x = 0; x < this->sizeX; x++)
		{
			f << fixed << setprecision(5) << this->matrix[t][x] << " ";
		}
		f << endl;
	}
}


//Method used to calculate the solution in both schemes
vector<double> ImplicitScheme::ThomasAlgoFTCS(vector<double>& D)
{ //The following algorithm was made considering A the sub-diagonal, B the main diagonal, C the top/upper diagonal
	double alpha, m;
	this->A.resize(sizeX);
	this->B.resize(sizeX);
	this->C.resize(sizeX);
//	D.resize(sizeX);
	vector<double> X(sizeX);

	alpha = u * (deltaT / deltaX);
	this->A[0] = 0.0;
	this->C[sizeX - 1] = 0;
	this->B[sizeX - 1] = 1;
//	D = (*this).matrix[0];
	for (int k = 0; k < sizeX - 1; k++)
	{
		this->A[k + 1] = -(1 / 2)*alpha;
		this->B[k] = 1;
		this->C[k] = (1/2)*alpha;
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

void ImplicitScheme::ThomasAlgorithm()
{

}

//Implicit UpWind FTBS (Forward time, Backward space)
void ImplicitScheme::ImplicitUpWindFTBS()
{
	//todo
}

//Implicit FTCS(Forward time, Central space)
void ImplicitScheme::ImplicitFTCS()
{
	vector<double> D = this->matrix[0];
	vector<double> tmp(sizeX);

	tmp = ThomasAlgoFTCS(D); 
	copy(tmp.begin(), tmp.end(), ostream_iterator<double>(cout, " "));

	for (int i = 1; i < sizeT; i++)
	{
		tmp = ThomasAlgoFTCS(D); //we create the vector containing values of the next time step
		this->matrix[i] = tmp;
		D = tmp; //we prepare the calculus of the following time step
		copy(tmp.begin(), tmp.end(), ostream_iterator<double>(cout, " \n"));
	}

}


ImplicitScheme::~ImplicitScheme()
{
	// default destructor
}

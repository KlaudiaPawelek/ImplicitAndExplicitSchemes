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


void ImplicitScheme::PrintResult()
{
	cout << "IMPLICIT" << endl;
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

//Implicit UpWind FTBS (Forward time, Backward space)
void ImplicitScheme::ImplicitUpWindFTBS()
{
	//todo
}

//Implicit FTCS(Forward time, Central space)
void ImplicitScheme::ImplicitFTCS()
{
	//todo
}


ImplicitScheme::~ImplicitScheme()
{
	// default destructor
}

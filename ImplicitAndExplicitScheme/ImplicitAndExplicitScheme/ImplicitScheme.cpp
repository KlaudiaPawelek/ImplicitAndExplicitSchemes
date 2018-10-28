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


//Implicit UpWind FTBS (Forward time, Backward space)
string ImplicitScheme::ImplicitUpWindFTBS()
{
	//todo
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

//Implicit FTCS(Forward time, Central space)
string ImplicitScheme::ImplicitFTCS()
{
	//todo
	return __func__; //return name of method -> useful for method SaveResultIntoFiles
}

ImplicitScheme::~ImplicitScheme()
{
	// default destructor
}

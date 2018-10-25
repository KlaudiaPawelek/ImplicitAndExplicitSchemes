#include "Scheme.h"
#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

Scheme::Scheme()
{
	//default constructor
}

void Scheme::InitialCondition()
{
	
	//for (int x = 0; x <= 10; x++)
	//{
	//	this->matrix[0][x] = 0;
	//}
	//for (int x = 10; x <= 22; x++)
	//{
	//	this->matrix[0][x] = 100*(sin(PI*((((double)x * 5) - 50) / 60)));
	//}
	//for (int x = 22; x <this->sizeX; x++)
	//{
	//	this->matrix[0][x] = 0;
	//}

	//other version of Initial Condition
	//with one loop and three conditons, maybe this is better solution?
	for (int x = 0; x < this->sizeX; x++)
	{
		if (x >= 0 && x <= 10)
		{
			this->matrix[0][x] = 0;
		}
		if (x >= 10 && x <= 22)
		{
			this->matrix[0][x] = 100 * (sin((this->PI)*((((double)x * 5) - 50) / 60)));
		}
		if (x >= 22 && x < this->sizeX)
		{
			this->matrix[0][x] = 0;
		}
	}
}

void Scheme::BoundryCondition()
{
	for (int t = 0; t < this->sizeT; t++)
	{
		this->matrix[t][0] = 0;
		this->matrix[t][this->sizeX-1] = 0;
	}
}

void Scheme::AnalyticalSolution()
{
	for (int x = 0; x < this->sizeX; x++)
	{
		for (int t = 0; t < this->sizeT; t++)
		{
			//to do
		}
	}
}

//method used in InsertDeltaT
int IsDouble(string input)
{
	//loop of the size of the input
	if (input[0] == '0' && input[1] == '.')
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (!isdigit(input[i]) && input[i] != '.')
				return 0;
		}
	}
	else
		return 0;

	return 1;
}

//ask user about delta T
//in excercise delta T is: 0.01, 0.02, 0.005
void Scheme::InsertDeltaT()
{
	string tmpDeltaT;
	cout << "Insert value of deltaT [0.01, 0.02, 0.005]: ";
	getline(cin, tmpDeltaT);
	while (!IsDouble(tmpDeltaT) || tmpDeltaT == "")
	{
		cout << "Wrong input! Please input an double value from excercise: ";
		getline(cin, tmpDeltaT);
	}
	
	this->deltaT = stod(tmpDeltaT);
}



// compute size of matrix and create it
void Scheme::ComputeSizeOfMatrix()
{
	//from excercise
	this->deltaX = 5.0;		//5 meters 
	const double x = 400;	//domain is xE[0;400] meters
	const double t = 0.5;	//t goes from 0.0 to 0.5sec

	//compute sizeX and sizeT, this is size of matrix
	this->sizeX = (x / deltaX) + 1;
	this->sizeT = (t / deltaT) + 1;

	//create&return Matrix with proper size filled by zeros
	Matrix m(this->sizeT, this->sizeX);
	this->matrix = m;
}

Matrix Scheme::GetMatrix()
{
	return this->matrix;
}



#ifndef SCHEME_H	//include guard
#define SCHEME_H

#include "matrix.h"	//matrix class, inspired on c++ course
#include <math.h>	//numeric library for sin method
#include <iostream>	//generic IO
#include <string>	//for string objects and methods
#include <chrono>	//use for delay in printing method
#include <thread>	//use for dealy in printing method
#include <fstream>	//input/output file stream class
#include <iomanip>	//for precision of numbers

using namespace std;

#pragma once

/**
* The Scheme class is mother/core class for ExplicitScheme and ImplicitScheme classes.
* This class includes common elements for inheritance classes like: computing initial condition, boundry condition and others.
* Additionally, Scheme class includes methods responsible for printing results in the console, saving results into text files.
* Objects are protected, because they can be used only in mother class and inheritance classes.
* Class includes only one default constructor and one default destructor.
* The Scheme class includes protected and public methods.
* Some accessors and one friend method are available.
**/
class Scheme 
{
protected: 
	/**
	* Aggregation: object from class Matrix.
	**/
	Matrix matrix;
	/**
	* Size of matrix.
	**/
	int sizeOfMatrix;
	/**
	* Size of rows in matrix.
	**/
	int sizeT;
	/**
	* Size of columns in matrix.
	**/
	int sizeX;
	/**
	* Values important for calculation. Mainly defined by user in the console.
	* @see void InitialCondition()
	* @see void BoundryCondition()
	* @see void InsertDeltaT()
	**/
	double deltaT;
	/**
	* Value defined in ComputeSizeOfMatrix method.
	* @see ComputeSizeOfMatrix(bool ifPrinted = 1)
	**/
	double deltaX;
	/**
	*Constant double value PI = atan(1) * 4
	**/
	const double PI = atan(1) * 4;
	/**
	*Constant double value from excercise 250 m/s
	**/
	const double u = 250; 

public: 
	/**
	* Default, empty constructor for Scheme class.
	**/
	Scheme();

protected:
	/**
	* Compute initial condition for each type of scheme.
	* @see Matrix matrix
	* @see ExplicitScheme
	* @see ImplicitScheme
	* @see AnalyticalSolution
	* @return void
	**/
	void InitialCondition();
	/**
	* Compute boundry condition for each type of scheme.
	* @see Matrix matrix
	* @see ExplicitScheme
	* @see ImplicitScheme
	* @see AnalyticalSolution
	* @return void
	**/
	void BoundryCondition();
	/**
	* User can define value of deltaT in console.
	* @see double deltaT
	* @return void
	**/
	void InsertDeltaT();
	/**
	* Compute size of matrix depend of deltaT defined by user.
	* @param bool ifPrinted = 1, size of matrix will be display in the console
	* @param bool ifPrinted = 0, size of matrix won't be display in the console
	* @see ImplicitScheme::ImplicitUpWindFTBS() 
	* @see ImplicitScheme::ImplicitFTCS()
	* @see ExplicitScheme::ExplicitUpWindFTBS()
	* @see ExplicitScheme::ExplicitLaxWandroff()
	* @see AnalyticalSolution(double defaultDeltaT = 0)
	**/
	void ComputeSizeOfMatrix(bool ifPrinted = 1);

public:
	/**
	* Save matrix into the text file.
	* @param double deltaT
	* @param string schemeName
	* @exception message about "file with results have not been saved. Something went wrong!", when file has not been created/saved correctly
	* @return void
	**/
	void SaveResultIntoFiles(double deltaT, string schemeName);
	/**
	* Solve analytical solution of given problem.
	* @param double defaultDeltaT  - parameter with default value 0, so user will not be asked about value of deltaT in console
	* @see InsertDeltaT();
	* @return string
	**/
	string AnalyticalSolution(double defaultDeltaT = 0);
	/**
	* Printing results from one norm, two norm and uniform norm, which are declared in Matrix class.
	* Norm is computed from matrix = m1 - m2
	* @param Matrix m1 - analytical solution
	* @param Matrix m2 - scheme solution
	* @see double one_norm() const;
	* @see double two_norm() const;
	* @see double uniform_norm() const;
	* @see Matrix operator-(Matrix m);
	* @return void
	*/
	void ComputeNorms(Matrix m1, Matrix m2);
	/**
	* Print only five rows of result.
	* Use overloaded operator << from Matrix class
	* @see friend std::ostream& operator<<(std::ostream& os,const Vector& v);
	* @return void
	**/
	void PrintResult();

	/*accessors*/
	/**
	* Accessor: get Matrix matrix.
	* @return Matrix 
	**/
	Matrix GetMatrix();
	/**
	* Accessor: get double deltaT.
	* @return double
	**/
	double GetDeltaT();

	/**
	* The method verifies correctness of deltaT inserted by user in the console.
	* Friend method visible only inside of Scheme class.
	* Return boolean value inside of the InsertDeltaT() method.
	* @param string input
	* @see InsertDeltaT()
	**/
	friend bool IsDouble(string input);

	/**
	* Destructor for Scheme class.
	**/
	~Scheme() {}
};

#endif
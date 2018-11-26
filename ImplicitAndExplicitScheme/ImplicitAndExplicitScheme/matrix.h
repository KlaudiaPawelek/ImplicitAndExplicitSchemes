#ifndef MATRIX_H	//include guard
#define MATRIX_H

#include <iostream>	//generic IO
#include <fstream>	//file IO
#include <stdexcept>//provides exceptions
#include <vector>	//vector class is used in Matrix class

using namespace std;

/**
	Matrix class, which use vector container from Standard Template Library.
	Important class for Scheme, ExplicitScheme and ImplicitScheme classes.
	Important information!
	This class has been created based on the program available at C ++ classes.
**/
class Matrix : private vector<vector<double>> 
{
	typedef vector<vector<double>> vec;

public:
	using vec::operator[];  //the array access operator public within Matrix

	// CONSTRUCTORS

	/**
	* Default constructor. Intialize an empty Matrix object
	* @see Matrix(int Nrows, int Ncols)
	* @see Matrix(const Matrix& m)
	*/
    Matrix();

	/**
	* Alternate constructor.
	* User can insert the size of matrix.
	* @param int Nrows - number of rows in matrix.
	* @param int Ncols - number of columns in matrix.
	* @see Matrix()
	* @see Matrix(const Matrix& m)
	* @exception invalid_argument ("matrix size negative or zero")
	*/
    Matrix(int Nrows, int Ncols); 

	/**
	* Copy constructor.
	* User can build a matrix from another matrix.
	* @param Matrix& m - matrix to copy.
	* @see Matrix()
	* @see Matrix(int Nrows, int Ncols)
	*/
	Matrix(const Matrix& m);

	// ACCESSOR METHODS

	/**
	* Normal public get method.
	* Get the number of rows
	* @see int getNcols()const
	* @return int. number of rows in matrix
	*/
	int getNrows() const; 

	/**
	* Normal public get method.
	* Get the number of columns
	* @see int getNrows()const
	* @return int. number of columns in matrix
	*/
	int getNcols() const; 

	// OVERLOADED OPERATOR

	/**
	* Overloaded assignment operator
	* @param Matrix& m - matrix to assign
	* @see operator==(const Matrix& m)const
	* @return Matrix&. the matrix on the left of the assignment
	*/
	Matrix& operator=(const Matrix& m); 

	/**
	*Overloaded subtraction operator
	* @param Matrix m - matrix to subtract
	* @see operator-(Matrix m)
	* @return Matrix
	*/
	Matrix operator-(Matrix m);


	// NORMS
	/**
	* Normal public method that returns a double.
	* It returns L1 norm of matrix
	* @see two_norm()const
	* @see uniform_norm()const
	* @return double. matrix L1  norm
	*/
	double one_norm() const;

	/**
	* Normal public method that returns a double.
	* It returns L2 norm of matrix
	* @see one_norm()const
	* @see uniform_norm()const
	* @return double. matrix L2  norm
	*/
	double two_norm() const;

	/**
	* Normal public method that returns a double.
	* It returns L_max norm of matrix
	* @see one_norm()const
	* @see two_norm()const
	* @return double.  matrix L_max  norm
	*/
	double uniform_norm() const;


	/**
	* Overloaded ostream << operator.
	* Display output
	* If matrix has size user will be asked to input only matrix values
	* If matrix was not initialized user can choose matrix size and input it values
	* @param ostream& os - display output stream.
	* @param Matrix& m - matrix to read.
	* @see operator>>(std::ifstream& ifs, Matrix& m)
	* @see operator>>(std::istream& is, Matrix& m)
	* @see operator<<(std::ostream& os, const Matrix& m)
	* @return std::ostream&. The ostream object
	*/
	friend ostream& operator<<(ostream& os, const Matrix& m);

	/**
	* Overloaded ofstream << operator. File output
	* The file output operator is compatible with file input operator,
	* @param ofstream& ofs
	* @param Matrix& m - matrix to read from.
	* @see operator>>(std::ifstream& ifs, Matrix& m)
	* @see operator<<(std::ofstream& ofs, const Matrix& m)
	* @see operator>>(std::istream& is, Matrix& m)
	* @exception std::invalid_argument ("file read error - negative matrix size");
	* @return std::ofstream&. The ofstream object
	*/
	friend ofstream& operator<<(ofstream& ofs, const Matrix& m );
};

#endif
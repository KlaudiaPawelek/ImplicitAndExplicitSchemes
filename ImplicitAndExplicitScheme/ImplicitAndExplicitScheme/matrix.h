#ifndef MATRIX_H  //include guard
#define MATRIX_H

#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exceptions
#include "vector.h"  //we use Vector in Matrix code


/**
	Class from C++ lab. In my opinion, we can use some methods.
	Of course, some of these methods can be deleted in the future.
	Now, this is oryginal class from C++ lab, so comments are oryginal too! We can change it too.
**/
class Matrix : private std::vector<std::vector<double> > {
	typedef std::vector<std::vector<double> > vec;
public:
	using vec::operator[];  // make the array access operator public within Matrix

	// CONSTRUCTORS

	/**
	* Default constructor.  Intialize an empty Matrix object
	* @see Matrix(int Nrows, int Ncols)
	* @see Matrix(const Matrix& m)
	*/
    Matrix();

	/**
	* Alternate constructor.
	* build a matrix Nrows by Ncols
	* @see Matrix()
	* @see Matrix(const Matrix& m)
	* @exception invalid_argument ("matrix size negative or zero")
	*/
    Matrix(int Nrows /**< int. number of rows in matrix */, int Ncols /**< int. number of columns in matrix  */); 

	/**
	* Copy constructor.
	* build a matrix from another matrix
	* @see Matrix()
	* @see Matrix(int Nrows, int Ncols)
	*/
	Matrix(const Matrix& m /**< Matrix&. matrix to copy from  */);

	// ACCESSOR METHODS

	/**
	* Normal public get method.
	* get the number of rows
	* @see int getNcols()const
	* @return int. number of rows in matrix
	*/
	int getNrows() const; // get the number of rows

	/**
	* Normal public get method.
	* get the number of columns
	* @see int getNrows()const
	* @return int. number of columns in matrix
	*/
	int getNcols() const; // get the number of cols

	// OVERLOADED OPERATOR

	/**
	* Overloaded assignment operator
	* @see operator==(const Matrix& m)const
	* @return Matrix&. the matrix on the left of the assignment
	*/
	Matrix& operator=(const Matrix& m /**< Matrix&. Matrix to assign from */); // overloaded assignment operator


	/**
	* Overloaded comparison operator
	* returns true or false depending on whether the matrices are the same or not
	* @see operator=(const Matrix& m)
	* @return bool. true or false
	*/
	bool operator==(const Matrix& m  /**< Matrix&. Matrix to compare to */
		) const; // overloaded comparison operator

	/**
	*Overloaded subtraction operator
	* returns Matrix
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


	// MULTIPLICATION, COMPARISON METHODS and TRANSPOSE METHODS

	/**
	* Overloaded *operator that returns a Matrix.
	* It Performs matrix by matrix multiplication.
	* @see operator*(const Matrix & a) const
	* @exception out_of_range ("Matrix access error")
	* One or more of the matrix have a zero size
	* @exception std::out_of_range ("uncompatible matrix sizes")
	* Number of columns in first matrix do not match number of columns in second matrix
	* @return Matrix. matrix-matrix product
	*/
	//
	Matrix operator*(const Matrix & a /**< Matrix. matrix to multiply by */
		) const;

	/**
	* Overloaded *operator that returns a Vector.
	* It Performs matrix by vector multiplication.
	* @see operator*(const Matrix & a)const
	* @exception std::out_of_range ("Matrix access error")
	* matrix has a zero size
	* @exception std::out_of_range ("Vector access error")
	* vector has a zero size
	* @exception std::out_of_range ("uncompatible matrix-vector sizes")
	* Number of columns in matrix do not match the vector size
	* @return Vector. matrix-vector product
	*/
	//
	Vector operator*(const Vector & v /**< Vector. Vector to multiply by */
		) const;


	/**
	* public method that returns the transpose of the matrix.
	* It returns the transpose of matrix
	* @return Matrix.  matrix transpose
	*/
	Matrix transpose() const;


	/**
	* Overloaded istream >> operator.
	* Keyboard input
	* if matrix has size user will be asked to input only matrix values
	* if matrix was not initialized user can choose matrix size and input it values
	* @see operator<<(std::ofstream& ofs, const Matrix& m)
	* @see operator>>(std::istream& is, Matrix& m)
	* @see operator<<(std::ostream& os, const Matrix& m)
	* @exception std::invalid_argument ("read error - negative matrix size");
	* @return std::istream&. The istream object
	*/
	 friend std::istream& operator >> (std::istream& is, /**< Keyboard input stream */
		Matrix& m /**< Matrix to write into */
		);// keyboard input


	/**
	* Overloaded ostream << operator.
	* Display output
	* if matrix has size user will be asked to input only matrix values
	* if matrix was not initialized user can choose matrix size and input it values
	* @see operator>>(std::ifstream& ifs, Matrix& m)
	* @see operator>>(std::istream& is, Matrix& m)
	* @see operator<<(std::ostream& os, const Matrix& m)
	* @return std::ostream&. The ostream object
	*/
	friend std::ostream& operator<<(std::ostream& os, /**< Display output stream */
		const Matrix& m /**< Matrix to read from*/
		);// screen output


	/**
	* Overloaded ifstream >> operator. File input
	* the file output operator is compatible with file input operator,
	* ie. everything written can be read later.
	* @see operator>>(std::ifstream& ifs, Matrix& m)
	* @see operator<<(std::ofstream& ofs, const Matrix& m)
	* @see operator<<(std::ostream& os, const Matrix& m)
	* @return std::ifstream&. The ifstream object
	*/
	friend std::ifstream& operator >> (std::ifstream& ifs, /**< Input file stream with opened matrix file */
		Matrix& m /**< Matrix to write into */
		);// file input

	/**
	* Overloaded ofstream << operator. File output
	* the file output operator is compatible with file input operator,
	* ie. everything written can be read later.
	* @see operator>>(std::ifstream& ifs, Matrix& m)
	* @see operator<<(std::ofstream& ofs, const Matrix& m)
	* @see operator>>(std::istream& is, Matrix& m)
	* @exception std::invalid_argument ("file read error - negative matrix size");
	* @return std::ofstream&. The ofstream object
	*/
	friend std::ofstream& operator<<(std::ofstream& ofs,
		const Matrix& m /**< Matrix to read from*/
		);// file output
};

#endif
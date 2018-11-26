#include "matrix.h"

using namespace std;

//Default constructor (empty matrix)
Matrix::Matrix() : vector<vector<double> >()  {}

// Alternate constructor - creates a matrix with the given values
Matrix::Matrix(int Nrows, int Ncols) : vector<vector<double> >()
{
    //check, if matrix size is not negative
	if (Nrows < 0 || Ncols < 0)
	{
		throw invalid_argument("matrix size negative");
	}
    
	// set the size for the rows
	(*this).resize(Nrows);

	// set the size for the columns
	for (int i = 0; i < Nrows; i++)
	{
		(*this)[i].resize(Ncols);
	}

	// initialise the matrix to contain zero
	for (int i = 0; i < Nrows; i++)
	{
		for (int j = 0; j < Ncols; j++)
		{
			(*this)[i][j] = 0.0;
		}
	}
}

//Copy constructor 
Matrix::Matrix(const Matrix& m) : vector<vector<double> >()
{
	// set the size of the rows
	(*this).resize(m.size());

	// set the size of the columns
	std::size_t i;
	for (i = 0; i < m.size(); i++)
	{
		(*this)[i].resize(m[0].size());
	}

	// copy the elements
	for (int i = 0; i < m.getNrows(); i++)
	{
		for (int j = 0; j < m.getNcols(); j++)
		{
			(*this)[i][j] = m[i][j];
		}
	}
}

// ACCESSOR METHODS
//accessor method - get the number of rows
int Matrix :: getNrows() const
{
	return size();
}

//accessor method - get the number of columns
int Matrix::getNcols() const
{
	return (*this)[0].size();
}

// NORMS
//1 norm
double Matrix::one_norm() const
{
	int i,j;
	double sum,max;
	int nrows = getNrows();
	int ncols = getNcols();

	max = 0;
	for ( j=0; j < ncols; j++) 
	{
	    sum = 0;
		for (i = 0; i < nrows; i++)
		{
			sum += fabs((*this)[i][j]);
		}
		if (max < sum)
		{
			max = sum;
		}
	}
	return max;
}

//2 norm
double Matrix::two_norm() const
{
	int i,j;
	double sum = 0;
	int nrows = getNrows();
	int ncols = getNcols();

	for (i = 0; i < nrows; i++)
	{
		for (j = 0; j < ncols; j++)
		{
			sum += fabs((*this)[i][j] * (*this)[i][j]);
		}
	}
	return (sqrt(sum));
}

//uniform (infinity) norm
double Matrix::uniform_norm() const
{
	int i,j;
	double max,sum;
	int nrows = getNrows();
	int ncols = getNcols();

	max = 0;
	for ( i=0; i < nrows; i++ ) 
	{
	    sum = 0;
		for (j = 0; j < ncols; j++)
		{
			sum += fabs((*this)[i][j]);
		}
		if (max < sum)
		{
			max = sum;
		}
	}
	return max;
}

// OVERLOADED OPERATORS
//Operator= assignment
Matrix& Matrix::operator=(const Matrix& m)
{
	(*this).resize(m.size());
	size_t i;
	size_t j;

	for (i = 0; i < m.size(); i++)
	{
		(*this)[i].resize(m[0].size());
	}

	for (i = 0; i < m.size(); i++)
	{
		for (j = 0; j < m[0].size(); j++)
		{
			(*this)[i][j] = m[i][j];
		}
	}
	return *this; 
}

//Overloaded operator -
Matrix Matrix::operator-(Matrix m)
{
	Matrix result((*this).getNrows(), (*this).getNcols());
	for (int i = 0; i < (*this).size(); i++)
	{
		for (int j = 0; j < (*this)[0].size(); j++)
		{
			result[i][j] = (*this)[i][j] - m[i][j];
		}
	}
	return result; //return matrix after subtraction
}


//----------------------OUTPUT FUNCTIONS--------------------//

//Screen output, user friendly
ostream& operator<<(ostream& os, const Matrix& m) {

	// test to see whether there are any elements
    if (m.getNrows() > 0) 
	{
        os << "The matrix elements are: \n";
        for (int i=0; i<m.getNrows();i++) 
		{
			for (int j=0;j<m.getNcols();j++) 
			{
				os << m[i][j]  << " ";
			}
			os << "\n";
		}
        os << "\n";
    }
    else
    {
        os << "Matrix is empty." << "\n";
    }
    return os;
}


//File output - raw data, comaptible with file reading operator
ofstream& operator<<(ofstream& ofs, const Matrix& m) 
{
    //put matrix rownumber in first line (even if it is zero)
    ofs << m.getNrows() << endl;

	//put matrix columnnumber in second line (even if it is zero)
	ofs << m.getNcols() << endl;

    //put data in third line (if size==zero nothing will be put)
    for (int i=0; i<m.getNrows(); i++) 
	{
		for (int j = 0; j < m.getNcols(); j++)
		{
			ofs << m[i][j] << " ";
		}
		ofs << endl;
	}
    return ofs;
}


<<<<<<< HEAD
azert
=======
#include<iostream>
#include "matrix.h" //class from C++ lab
#include "vector.h" //class from C++ lab
#include "Scheme.h" //mother class
#include "ExplicitScheme.h" //inherited class
#include "ImplicitScheme.h" //inherited class

using namespace std;

int main()
{
	// this is only test! you can delete it
	ImplicitScheme iS;
	iS.ComputeSizeOfMatrix(0.2, 10, 1, 0.01, 0.4);
	cout << "Size of matrix: \n" << " -columns: " << iS.GetMatrix().getNcols() << "\n -rows: " << iS.GetMatrix().getNrows() << endl;
	//end test

	system("pause");
	return 0;
}
>>>>>>> master

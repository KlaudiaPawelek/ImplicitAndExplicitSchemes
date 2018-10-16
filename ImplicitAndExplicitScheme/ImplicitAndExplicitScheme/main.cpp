#include<iostream>
#include "matrix.h" //class from C++ lab
#include "vector.h" //class from C++ lab
#include "Scheme.h" //mother class
#include "ExplicitScheme.h" //inherited class
#include "ImplicitScheme.h" //inherited class

using namespace std;

int main()
{
	
	ImplicitScheme iS;
	iS.ComputeSizeOfMatrix(0.1);
	cout << "Size of matrix: \n" << " -columns: " << iS.GetMatrix().getNcols() << "\n -rows: " << iS.GetMatrix().getNrows() << endl;
	iS.InitialCondition();
	cout << iS.GetMatrix();

	system("pause");
	return 0;
}


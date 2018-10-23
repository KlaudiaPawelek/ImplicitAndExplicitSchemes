#include<iostream>
#include "matrix.h" //class from C++ lab
#include "vector.h" //class from C++ lab
#include "Scheme.h" //mother class
#include "ExplicitScheme.h" //inherited class
#include "ImplicitScheme.h" //inherited class

using namespace std;

int main()
{
	//At the end of our project, I will try to create short menu in console.

	//--------------------- Explicit Scheme --------------------- //
	ExplicitScheme eS;
	eS.InsertDeltaT(); 
	eS.ComputeSizeOfMatrix(); //parameter: delta T
	cout << "Size of matrix: \n" << " -columns: " << eS.GetMatrix().getNcols() << "\n -rows: " << eS.GetMatrix().getNrows() << endl;
	eS.InitialCondition();
	eS.BoundryCondition();
	eS.ExplicitUpWindFTBS();
	//eS.ExplicitLaxWandroff();
	cout << eS.GetMatrix();
	//eS.SaveResultIntoFiles();
	
	//--------------------- Implicit Scheme --------------------- //
	/*ImplicitScheme iS;
	iS.InsertDeltaT();
	iS.ComputeSizeOfMatrix(); //parameter: delta T
	cout << "Size of matrix: \n" << " -columns: " << iS.GetMatrix().getNcols() << "\n -rows: " << iS.GetMatrix().getNrows() << endl;
	iS.InitialCondition();
	iS.BoundryCondition();
	//iS.ImplicitUpWindFTBS();
	//iS.ImplicitFTCS();
	cout << iS.GetMatrix();
	iS.SaveResultIntoFiles();*/

	system("pause");
	return 0;
}


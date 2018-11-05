#include<iostream>
#include "matrix.h" //class from C++ lab
#include "vector.h" //class from C++ lab
#include "Scheme.h" //mother class
#include "ExplicitScheme.h" //inherited class
#include "ImplicitScheme.h" //inherited class

using namespace std;

int main()
{
	//At the end of our project, maybe I will try to create short menu in console :D

	//--------------------- Explicit Scheme --------------------- //
/*	ExplicitScheme eS;
	eS.InsertDeltaT();
	eS.ComputeSizeOfMatrix(); //parameter: delta T
	cout << "Size of matrix: \n" << " -columns: " << eS.GetMatrix().getNcols() << "\n -rows: " << eS.GetMatrix().getNrows() << endl;
	//eS.InitialCondition();
	//eS.BoundryCondition();
	//eS.ExplicitUpWindFTBS();
	//eS.ExplicitLaxWandroff();
	//eS.PrintResult();
	//eS.SaveResultIntoFiles();
	eS.AnalyticalSolution();
	eS.PrintResult();			*/
	
	//--------------------- Implicit Scheme --------------------- //
	ImplicitScheme iS;
	iS.InsertDeltaT();
	iS.ComputeSizeOfMatrix(); //parameter: delta T
	cout << "Size of matrix: \n" << " -columns: " << iS.GetMatrix().getNcols() << "\n -rows: " << iS.GetMatrix().getNrows() << endl;
	iS.InitialCondition();
	iS.BoundryCondition();
	//iS.ImplicitUpWindFTBS();
	iS.ImplicitFTCS();
	//iS.AnalyticalSolution();
	iS.PrintResult();
	//iS.SaveResultIntoFiles();

	system("pause");
	return 0;
}


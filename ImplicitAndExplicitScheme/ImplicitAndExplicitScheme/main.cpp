#include<iostream>
#include "matrix.h" //class from C++ lab
#include "vector.h" //class from C++ lab
#include "Scheme.h" //mother class
#include "ExplicitScheme.h" //inherited class
#include "ImplicitScheme.h" //inherited class

using namespace std;

int main(int argc, char* argv[])
{
	//Important variable to saving results into different files
	string schemeName = " ";
	double deltaT = 0.0;

	//--------------------- Explicit Scheme --------------------- //
	ExplicitScheme eS, eS2; //first object for UpWind, second for Lax
	//UpWindFTBS
	eS.InsertDeltaT(); 
	eS.ComputeSizeOfMatrix(); 
	eS.InitialCondition();
	eS.BoundryCondition();
	schemeName = eS.ExplicitUpWindFTBS();
	deltaT = eS.GetDeltaT();
	eS.SaveResultIntoFiles(deltaT,schemeName);
	eS.PrintResult();
	eS.~ExplicitScheme();

	//Lax-Wandroff
	eS2.InsertDeltaT();
	eS2.ComputeSizeOfMatrix(); 
	eS2.InitialCondition();
	eS2.BoundryCondition();
	schemeName = eS2.ExplicitLaxWandroff();
	deltaT = eS2.GetDeltaT();
	eS2.SaveResultIntoFiles(deltaT, schemeName);
	eS2.PrintResult();
	eS2.~ExplicitScheme();

	//--------------------- Implicit Scheme --------------------- //
	/*ImplicitScheme iS;
	iS.InsertDeltaT();
	iS.ComputeSizeOfMatrix();
	iS.InitialCondition();
	iS.BoundryCondition();
	//iS.ImplicitUpWindFTBS();
	//iS.ImplicitFTCS();
	iS.PrintResult();
	iS.SaveResultIntoFiles();*/

	system("pause");
	return 0;
}


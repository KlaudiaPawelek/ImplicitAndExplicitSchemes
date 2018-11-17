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
	/*schemeName = eS.ExplicitUpWindFTBS();
	deltaT = eS.GetDeltaT();
	eS.SaveResultIntoFiles(deltaT,schemeName);
	eS.PrintResult();
	eS.~ExplicitScheme();

	//Lax-Wandroff
	schemeName = eS2.ExplicitLaxWandroff();
	deltaT = eS2.GetDeltaT();
	eS2.SaveResultIntoFiles(deltaT, schemeName);
	eS2.PrintResult();
	eS2.~ExplicitScheme();*/

	//--------------------- Implicit Scheme --------------------- //
	/*ImplicitScheme iS, iS2; //first object for UpWind, second for FTCS
	schemeName = iS.ImplicitUpWindFTBS();
	deltaT = iS.GetDeltaT();
	iS.SaveResultIntoFiles(deltaT, schemeName);
	iS.PrintResult();
	iS.~ImplicitScheme();
	
	schemeName = iS2.ImplicitFTCS();
	deltaT = iS2.GetDeltaT();
	iS2.SaveResultIntoFiles(deltaT, schemeName);
	iS2.PrintResult();
	iS2.~ImplicitScheme();*/

	//--------------------- Analytical Solution ----------------- //
	Scheme s;
	schemeName = s.AnalyticalSolution();
	deltaT = s.GetDeltaT();
	s.SaveResultIntoFiles(deltaT, schemeName);
	s.PrintResult();
	s.~Scheme();

	system("pause");
	return 0;
}


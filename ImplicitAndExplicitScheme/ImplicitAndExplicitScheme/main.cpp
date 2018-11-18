#include<iostream>
#include "matrix.h" //class from C++ lab
#include "vector.h" //class from C++ lab
#include "Scheme.h" //mother class
#include "ExplicitScheme.h" //inherited class
#include "ImplicitScheme.h" //inherited class

using namespace std;

int main(int argc, char* argv[])
{
	//Variables for SaveResultIntoFiles method
	//name of file - type of scheme
	string schemeName = " ";
	//name of file - deltaT
	double deltaT = 0.0;

	//objects ExplicitScheme, ImplicitScheme and Scheme classes
	ExplicitScheme eS, eS2;
	ImplicitScheme iS, iS2;
	Scheme s;
	
	//parsing arguments from console
	string arg;
	for (int i = 1; i < argc; i++)
	{
		arg += argv[i];
	}

	//********************* Run program with arguments ***********//
	
	//--------------------- Explicit Scheme --------------------- //
	if(arg=="-exUpWind")
	{
		//UpWindFTBS
		cout << "EXPLICIT SCHEME - UP WIND, FTBS \n";
		schemeName = eS.ExplicitUpWindFTBS();
		deltaT = eS.GetDeltaT();
		eS.PrintResult();
		eS.SaveResultIntoFiles(deltaT,schemeName);
		eS.~ExplicitScheme();
	}
	else if (arg == "-exLaxWandroff")
	{
		//Lax-Wandroff
		cout << "EXPLICIT SCHEME - LAX-WANDROFF \n";
		schemeName = eS2.ExplicitLaxWandroff();
		deltaT = eS2.GetDeltaT();
		eS2.PrintResult();
		eS2.SaveResultIntoFiles(deltaT, schemeName);
		eS2.~ExplicitScheme();
	}
	//--------------------- Implicit Scheme --------------------- //
	else if (arg == "-imUpWind")
	{
		//UpWind FTBS
		cout << "IMPLICIT SCHEME - UP WIND, FTBS \n";
		schemeName = iS.ImplicitUpWindFTBS();
		deltaT = iS.GetDeltaT();
		iS.PrintResult();
		iS.SaveResultIntoFiles(deltaT, schemeName);
		iS.~ImplicitScheme();
	} 
	else if (arg == "-imFTCS")
	{
		//FTCS
		cout << "IMPLICIT SCHEME - FTCS \n";
		schemeName = iS2.ImplicitFTCS();
		deltaT = iS2.GetDeltaT();
		iS2.PrintResult();
		iS2.SaveResultIntoFiles(deltaT, schemeName);
		iS2.~ImplicitScheme();
	}
	//--------------------- Analytical Solution ----------------- //
	else if (arg == "-analytical")
	{
		cout << "ANALYTICAL SOLUTION \n";
		schemeName = s.AnalyticalSolution();
		deltaT = s.GetDeltaT();
		s.PrintResult();
		s.SaveResultIntoFiles(deltaT, schemeName);
		s.~Scheme();
	}

	system("pause");
	return 0;
}


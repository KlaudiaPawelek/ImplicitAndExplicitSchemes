#include<iostream>
#include "matrix.h" //class from C++ lab
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
	arg = "-exLaxWandroff"; //<-use only, when you want to debug 
	//--------------------- Explicit Scheme --------------------- //
	if(arg=="-exUpWind")
	{
		//UpWindFTBS
		cout << "EXPLICIT SCHEME - UP WIND, FTBS \n";
		schemeName = eS.ExplicitUpWindFTBS();
		deltaT = eS.GetDeltaT();

		//Print results
		eS.PrintResult();

		//Norms
		s.AnalyticalSolution(deltaT);
		s.ComputeNorms(s.GetMatrix(), eS.GetMatrix());

		//Save results
		eS.SaveResultIntoFiles(deltaT,schemeName);

		//Destructors
		eS.~ExplicitScheme();
		s.~Scheme();
	}
	else if (arg == "-exLaxWandroff")
	{
		//Lax-Wandroff
		cout << "EXPLICIT SCHEME - LAX-WANDROFF \n";
		schemeName = eS2.ExplicitLaxWandroff();
		deltaT = eS2.GetDeltaT();
		
		//Print results
		eS2.PrintResult();

		//Norms
		s.AnalyticalSolution(deltaT);
		s.ComputeNorms(s.GetMatrix(), eS2.GetMatrix());

		//Save results
		eS2.SaveResultIntoFiles(deltaT, schemeName);

		//Destructors
		eS2.~ExplicitScheme();
		s.~Scheme();
	}
	//--------------------- Implicit Scheme --------------------- //
	else if (arg == "-imUpWind")
	{
		//UpWind FTBS
		cout << "IMPLICIT SCHEME - UP WIND, FTBS \n";
		schemeName = iS.ImplicitUpWindFTBS();
		deltaT = iS.GetDeltaT();

		//Print results
		iS.PrintResult();

		//Norms
		s.AnalyticalSolution(deltaT);
		s.ComputeNorms(s.GetMatrix(), iS.GetMatrix());

		//Save results
		iS.SaveResultIntoFiles(deltaT, schemeName);

		//Destructors
		iS.~ImplicitScheme();
		s.~Scheme();
	} 
	else if (arg == "-imFTCS")
	{
		//FTCS
		cout << "IMPLICIT SCHEME - FTCS \n";
		schemeName = iS2.ImplicitFTCS();
		deltaT = iS2.GetDeltaT();

		//Print results
		iS2.PrintResult();

		//Norms
		s.AnalyticalSolution(deltaT);
		s.ComputeNorms(s.GetMatrix(), iS2.GetMatrix());

		//Save results
		iS2.SaveResultIntoFiles(deltaT, schemeName);

		//Destructors
		iS2.~ImplicitScheme();
		s.~Scheme();
	}
	//--------------------- Analytical Solution ----------------- //
	else if (arg == "-analytical")
	{
		cout << "ONLY ANALYTICAL SOLUTION \n";
		schemeName = s.AnalyticalSolution();
		deltaT = s.GetDeltaT();
		s.PrintResult();
		s.SaveResultIntoFiles(deltaT, schemeName);
		s.~Scheme();
	}

	system("pause");
	return 0;
}


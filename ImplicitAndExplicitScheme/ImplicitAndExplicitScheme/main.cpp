#include<iostream>
#include "matrix.h"			//matrix class, inspired on c++ course
#include "Scheme.h"			//mother class
#include "ExplicitScheme.h" //inherited class
#include "ImplicitScheme.h" //inherited class

#include <chrono>

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
	//arg = "-exUpWind"; //<-use only, when you want to debug 
	
	//********************* Run program with arguments ***********//

	//--------------------- Explicit Scheme --------------------- //
	try
	{
		if (arg == "-exUpWind")
		{
			//UpWindFTBS
			cout << "EXPLICIT SCHEME - UP WIND, FTBS \n";
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

			schemeName = eS.ExplicitUpWindFTBS();

			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			std::cout << "\nTime = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;
			
			deltaT = eS.GetDeltaT();

			//Print results
			eS.PrintResult();
			
			//Norms
			s.AnalyticalSolution(deltaT);
			s.ComputeNorms(s.GetMatrix(), eS.GetMatrix());

			//Save results
			eS.SaveResultIntoFiles(deltaT, schemeName);

			//Destructors
			eS.~ExplicitScheme();
			s.~Scheme();
		}
		else if (arg == "-exLaxWendroff")
		{
			//Lax-Wandroff
			cout << "EXPLICIT SCHEME - LAX-WENDROFF \n";
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
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
			schemeName = iS.ImplicitUpWindFTBS();
			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			std::cout << "\nTime = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;


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
		else if (arg == "/?") //short manual
		{
			cout << "Available parameters: \n";
			cout << "\t -analytical \n";
			cout << "\t -imFTCS \n";
			cout << "\t -imUpWind \n";
			cout << "\t -exLaxWandroff \n";
			cout << "\t -exUpWind \n";
			cout << "\n";
			cout << "--Example below--\n";
			cout << "ImplicitAndExplicitScheme.exe -analytical \n\n";
			cout << "Then, program asks you about value of delta t parameter. \n";
			cout << "Good luck! \n";

		}
		else
		{
			cout << "Invalid argument! Please, check the manual. Use help command /? \n";
		}
	}
	catch (const exception& e)
	{
		cout << "Invalid argument!" << endl;
		cerr << "Exception caught" << endl;
		cerr << "Type: " << typeid(e).name() << endl;
		cerr << "What: " << e.what() << endl;
	}

	system("pause");
	return 0;
}


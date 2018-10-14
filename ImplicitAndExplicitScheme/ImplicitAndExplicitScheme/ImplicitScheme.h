#pragma once
#include "Scheme.h"
#include "matrix.h"
#include "vector.h"

//inherited class, with overrided methods
class ImplicitScheme :
	public Scheme
{
public:
	//default constructor
	ImplicitScheme();

	//override methods from Scheme class
	virtual void PrintResult();
	virtual void SaveResultIntoFiles();
	virtual void AnalyticalSolution();

	//methods for implicit schemes
	void ImplicitUpWind();
	void ImplicitFTCS();

	//default destructor
	~ImplicitScheme();
};


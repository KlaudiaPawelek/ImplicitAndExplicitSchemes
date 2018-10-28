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

	//methods for implicit schemes
	string ImplicitUpWindFTBS();
	string ImplicitFTCS();

	//default destructor
	~ImplicitScheme();
};


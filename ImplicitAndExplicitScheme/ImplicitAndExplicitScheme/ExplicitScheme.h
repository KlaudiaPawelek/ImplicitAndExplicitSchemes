#pragma once
#include "Scheme.h"
#include "matrix.h"
#include "vector.h"

//inherited class, with overrided methods
class ExplicitScheme :
	public Scheme
{

public:
	//default constructor
	ExplicitScheme();

	//override methods from Scheme class
	virtual void PrintResult();
	virtual void SaveResultIntoFiles();

	//methods for explicit schemes
	void ExplicitUpWindFTBS();
	void ExplicitLaxWandroff();

	//default destructor
	~ExplicitScheme();
};


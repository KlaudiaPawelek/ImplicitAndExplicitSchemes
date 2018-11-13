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

	//methods for explicit schemes
	string ExplicitUpWindFTBS();
	string ExplicitLaxWandroff();

	//default destructor
	~ExplicitScheme();
};


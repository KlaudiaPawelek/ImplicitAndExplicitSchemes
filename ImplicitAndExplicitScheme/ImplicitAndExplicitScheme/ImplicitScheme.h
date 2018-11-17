#pragma once
#include "Scheme.h"
#include "matrix.h"
#include "vector.h"

//inherited class, with overrided methods
class ImplicitScheme :
	public Scheme
{

protected:
	vector<double> A, B, C, D;
	vector<double> ThomasAlgoFTCS();
	vector<double> ThomasAlgoUpWindFTBS();

public:
	//default constructor
	ImplicitScheme();

	//methods for implicit schemes
	string ImplicitUpWindFTBS();
	string ImplicitFTCS();

	//default destructor
	~ImplicitScheme();
};


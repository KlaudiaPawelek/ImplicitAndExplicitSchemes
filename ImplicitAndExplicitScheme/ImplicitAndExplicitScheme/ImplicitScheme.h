#pragma once
#include "Scheme.h"
#include "matrix.h"
#include "vector.h"

//inherited class, with overrided methods
class ImplicitScheme :
	public Scheme
{

protected:

	vector<double> A, B, C;

public:
	//default constructor
	ImplicitScheme();

	//override methods from Scheme class
	virtual void PrintResult();
	virtual void SaveResultIntoFiles();

	//methods for implicit schemes
	//void createThomasMatrix();
	vector<double> ThomasAlgoFTCS(vector<double>& D);
	void ThomasAlgorithm();
	void ImplicitUpWindFTBS();
	void ImplicitFTCS();

	//default destructor
	~ImplicitScheme();
};


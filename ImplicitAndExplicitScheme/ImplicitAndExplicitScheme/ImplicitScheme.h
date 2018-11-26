#ifndef IMPLICITSCHEME_H	//include guard
#define IMPLICITSCHEME_H

#include "Scheme.h"			//Mother class
#include <iostream>			//generic IO
#include <string>			//for string methods

#pragma once

/**
* Inherited class, which includes implicit schemes like:
* Up Wind Forward-Time Backward-Space and Forward-Time Central-Space.
* Additionally, class includes private method with Thomas Algorithm.
**/
class ImplicitScheme :
	public Scheme
{

private:
	/**
	* Private vector of double imortant for Thomas algorithm.
	**/
	vector<double> A;
	/**
	* Private vector of double imortant for Thomas algorithm.
	**/
	vector<double> B;
	/**
	* Private vector of double imortant for Thomas algorithm.
	**/
	vector<double> C; 
	/**
	* Private vector of double imortant for Thomas algorithm.
	**/
	vector<double> D;

private:
	/**
	* Private method, which includes Thomas algorithm important for Implicit schemes.
	* @see ImplicitUpWindFTBS()
	* @see ImplicitFTCS()
	* @return vector<double>
	**/
	vector<double> ThomasAlgorithm(double parameter, double parameter2, bool version);

public:
	/**
	* Default, empty constructor for ImplicitScheme class.
	**/
	ImplicitScheme();

	/**
	* Public method, which solves the difference using implicit scheme Forward-Time Backward-Space
	* @return string - name of method for saving result into files with proper name
	* @see SaveResultIntoFiles(double deltaT, string schemeName)
	**/
	string ImplicitUpWindFTBS();
	/**
	* Public method, which solves the difference using implicit scheme Forward-Time Central-Space
	* @return string - name of method for saving result into files with proper name
	* @see SaveResultIntoFiles(double deltaT, string schemeName)
	**/
	string ImplicitFTCS();

	/**
	*Default, empty destructor for ImplicitScheme class.
	**/
	~ImplicitScheme();
};

#endif
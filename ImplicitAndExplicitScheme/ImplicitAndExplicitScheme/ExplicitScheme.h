#ifndef EXPLICITSCHEME_H	//include guard
#define EXPLICITSCHEME_H

#include "Scheme.h"			//Mother class
#include <iostream>			//generic IO
#include <string>			//for string methods

#pragma once
/**
* Inherited class, which includes implicit schemes like:
* Up Wind Forward-Time Backward-Space and Forward-Time Central-Space.
* Additionally, class includes private method with Thomas Algorithm.
**/
class ExplicitScheme :
	public Scheme
{
public:
	/**
	* Default, empty constructor for ExplicitScheme class.
	**/
	ExplicitScheme();

	/**
	* Public method, which solves the difference using explicit scheme Up Wind Forward-Time Backward-Space
	* @return string - name of method for saving result into files with proper name
	* @see SaveResultIntoFiles(double deltaT, string schemeName)
	**/
	string ExplicitUpWindFTBS();
	/**
	* Public method, which solves the difference using explicit scheme Lax-Wandroff
	* @return string - name of method for saving result into files with proper name
	* @see SaveResultIntoFiles(double deltaT, string schemeName)
	**/
	string ExplicitLaxWandroff();

	/**
	*Default, empty destructor for ExplicitScheme class.
	**/
	~ExplicitScheme();
};

#endif

//============================================================================
// Name        : cmaking.cpp
// Author      : Ruben
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Description : A simple program that computes the square root of a number
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

using namespace std;

int main (int argc, char *argv[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	if (argc < 2)
    	{
	    fprintf(stdout,"%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);

	    fprintf(stdout,"Usage: %s number\n",argv[0]);
	    return 1;
	}
  
	double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
	fprintf(stdout,"Computing with mysqrt function...");
	double outputValue = mysqrt(inputValue);
#else
	fprintf(stdout,"Computing with sqrt function...");
	double outputValue = sqrt(inputValue);
#endif
  	fprintf(stdout,"The square root of %g is %g\n", inputValue, outputValue);

	return 0;
}

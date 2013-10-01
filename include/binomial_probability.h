/**
	* Header to src/binomial_probability.c
	*
	* Created: 2013-09-30
	* Revised:
	*/

#ifndef __BINOMIAL_PROBABILITY_H__
	#define __BINOMIAL_PROBABILITY_H__

	#include <math.h>
	#include "combinations.h"

	double
	binomial_probability ( unsigned short n , unsigned short x , double p ) ;

	double
	binomial ( unsigned short n , unsigned short x , double p , double q ) ;

#endif
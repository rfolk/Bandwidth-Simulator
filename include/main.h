#ifndef __BANDWIDTH_SIM_H__
	#define __BANDWIDTH_SIM_H__

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "binomial_probability.h"

	typedef enum { false, true } bool ;

	bool
	parse_input ( int argc , char * argv[] ,
	              int * b , int * r , int * n , int * a , double * p ) ;

	bool
	check_input ( int * b , int * r , int * n , int * x , double * a ) ;

	int
	get_input ( int * var ) ;

	int
	get_input_double ( double * var ) ;

#endif
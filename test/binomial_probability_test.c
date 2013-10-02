#include <stdio.h>
#include <stdlib.h>
#include "../include/binomial_probability.h"

int
main ( void )
{
	double bp ;

	//	problem we were assigned to solve
	bp = binomial_probability ( 35 , 10 , 0.1L ) ;
	printf ( "Probability is: %lf\n" , bp ) ;

	// Worst case scenario from listed requirements
	bp = binomial_probability ( 100 , 50 , 0.1L ) ;
	printf ( "Probability is: %.100lf\n" , bp ) ;
	return 0 ;
}
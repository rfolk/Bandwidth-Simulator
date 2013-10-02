/**
	* Combinations
	* Calculates the combination of nCx for a given n and x value.
	* Uses the partial factorial function.
	*
	* Created: 2013-09-26
	* Revised: 2013-09-30
	*/

#include "combinations.h"

// Calculate (n!)/(x!(n-x)!)
double
n_choose_x ( unsigned short n , unsigned short x )
{
	double numerator ;
	double denominator ;
	double combination ;
	unsigned short n_minus_x = n - x ;

	if ( n_minus_x > x)
	{
		//  n - x is bigger so we should cancel it out
		numerator   = factorial ( n_minus_x + 1 , n ) ;
		denominator = factorial ( 1 , x ) ;
	}
	else
	{
		//  x is bigger so we should cancel it out
		numerator   = factorial ( x + 1 , n ) ;
		denominator = factorial ( 1 , n_minus_x ) ;
	}
	combination = numerator / denominator ;
	return combination ;
}
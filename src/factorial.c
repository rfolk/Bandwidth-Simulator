/**
	* Factorial
	* Calculates the partial factorial for a given range of numbers. To calculate
	* a traditional factorial pass '1' as the start variable.
	*
	* Created: 2013-09-26
	* Revised: 2013-09-30
	*/

#include "../include/factorial.h"

//  Cannot calculate with greater than 2^80 precision
double
factorial ( unsigned short start , unsigned short end )
{
	if ( end == 0 || end == 1 )
	{
		return 1.0L ;
	}
	if ( start == 0 )
	{
		start = 1 ;
	}
	if ( start == end )
	{
		return ( double ) end ;
	}

	unsigned short index ;
	double    fact = 1.0L ;

	for ( index = start ; index <= end ; index ++ )
		fact *= index ;

	return fact ;
}
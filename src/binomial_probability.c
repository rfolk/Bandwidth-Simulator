/**
	* Binomial Probability
	* Calculates the Binomial probability with the given variables n, x, and p.
	* Uses the formula: P(X=x) = nCx * p^x * q^(n-x)
	*
	*	Originally I had created a big num class, but I had to face facts and
	* and realize that a working product always beats a neat product. Some
	* precision has been lost but all in all it's an acceptable loss to get an
	* almost right working answer.
	*
	* Created: 2013-09-30
	* Revised:
	*/

#include "../include/binomial_probability.h"

double
binomial_probability ( unsigned short n , unsigned short x , double p )
{

	unsigned short index ;
	double result ;

	double q = 1.0L - p ;

	if ( n / 2 > x )
	{
		result = 1 ;
		for ( index = 0 ; index <= x ; index ++ )
		{
			result -= binomial ( n , index , p , q ) ;
		}
	}
	else
	{
		result = 0 ;
		for ( index = x + 1 ; index <= n ; index ++ )
		{
			result += binomial ( n , index , (double)p , (double)q ) ;
		}
	}

	return result ;
}

double
binomial ( unsigned short n , unsigned short x , double p , double q )
{
	double result  = powl ( p , x ) * powl ( q , n - x ) ;
	result        *= n_choose_x ( n , x ) ;
	return result ;
}
/**
  * Factorial
  * Calculates the partial factorial for a given range of numbers. To calculate
  * a traditional factorial pass '1' as the start variable.
  *
  * Created: 2013-09-26
  * Revised: 2013-09-29
  */

#include "../include/factorial.h"

//  Cannot calculate with greater than 2^80 precision
long double
factorial ( unsigned short start , unsigned short end )
{
  unsigned short index ;
  long double    fact = 1 ;

  for ( index = start ; index <= end ; index ++ )
    fact *= index ;

  return fact ;
}
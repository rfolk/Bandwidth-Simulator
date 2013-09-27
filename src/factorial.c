/**
  * Factorial
  * Calculates the partial factorial for a given range of numbers. To calculate
  * a traditional factorial pass '1' as the start variable.
  *
  * Created: 2013-09-26
  * Revised:
  */

#include "../include/factorial.h"

//  Cannot calculate a product greater than 18446744073709551615
unsigned long long
factorial ( int start , int end )
{
  int index ;
  unsigned long long fact = 1 ;

  for ( index = start ; index <= end ; index ++ )
    fact *= index ;

  return fact ;
}
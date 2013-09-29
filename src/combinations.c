/**
  * Combinations
  * Calculates the combination of nCk for a given n and k value.
  * Uses the partial factorial function.
  *
  * Created: 2013-09-26
  * Revised: 2013-09-29
  */

#include "../include/combinations.h"

// Calculate (n!)/(k!(n-k)!)
long double
n_choose_k ( unsigned short n , unsigned short k )
{
  long double numerator ;
  long double denominator ;
  long double combination ;
  unsigned short n_minus_k = n - k ;

  if ( n_minus_k > k)
  {
    //  n - k is bigger so we should cancel it out
    numerator   = factorial ( n_minus_k + 1 , n ) ;
    denominator = factorial ( 1 , k ) ;
  }
  else
  {
    //  k is bigger so we should cancel it out
    numerator   = factorial ( k + 1 , n ) ;
    denominator = factorial ( 1 , n_minus_k ) ;
  }
  combination = numerator / denominator ;
  return combination ;
}
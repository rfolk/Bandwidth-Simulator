#include <stdio.h>
#include <stdlib.h>
#include "../include/factorial.h"

int main ( void )
{
  long double f ;
  f = factorial ( 1 , 5 ) ;
  if ( ( int ) f == 120 )
    printf ( "5! calculated correctly.\n" ) ;
  else
  {
    printf("Error.\n");
    exit ( -1 ) ;
  }
  f = factorial ( 5 , 10 ) ;
  if ( ( int ) f == 151200 )
    printf ( "10!/4! calculated correctly.\n" ) ;
  else
  {
    printf("Error.\n");
    exit ( -1 ) ;
  }

  return 0 ;
}
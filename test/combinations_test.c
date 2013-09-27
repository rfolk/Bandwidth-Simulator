#include <stdio.h>
#include <stdlib.h>
#include "../include/combinations.h"

int
main ( void )
{
  unsigned long long c ;
  c = n_choose_k ( 12 , 9 ) ;
  printf ( "%i\n" , c ) ;
  if ( c == 220 )
    printf ( "12c9 calculated correctly.\n" ) ;
  else
  {
    printf("Error.\n");
    exit ( -1 ) ;
  }
  c = n_choose_k ( 18 , 3 ) ;
  printf ( "%i\n" , c ) ;
  if ( c == 816 )
    printf ( "18c3 calculated correctly.\n" ) ;
  else
  {
    printf("Error.\n");
    exit ( -1 ) ;
  }
  c = n_choose_k ( 35 , 8 ) ;
  printf ( "%i\n" , c ) ;
  if ( c == 23535820 )
    printf ( "35c8 calculated correctly.\n" ) ;
  else
  {
    printf("Error.\n");
    exit ( -1 ) ;
  }

  return 0 ;
}
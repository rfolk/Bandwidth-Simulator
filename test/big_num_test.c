#include "../include/big_num.h"

int
main ( void )
{
  big_num big1, big2, res1 , res2;
  create_big_num ( &res1 ) ;
  create_big_num ( &res2 ) ;

  printf ( "screw you\n" ) ;

  make_big_num_from_string ( &big1 , "10000000" ) ;
  printf ( "screw you 2\n" ) ;
  make_big_num_from_int ( &big2 , 1000 ) ;

  printf ( "screw you 3\n" ) ;

  print_big_num ( &big1 ) ;
  print_big_num ( &big2 ) ;

  add_big_num ( &big1, &big2, &res1 ) ;

  print_big_num ( &res1 ) ;

  sub_big_num ( &res1, &big2, &res2 ) ;

  print_big_num ( &res2 ) ;

/*  big_num one , test_sub ;
  create_big_num ( &one ) ;
  create_big_num ( &test_sub ) ;
  make_big_num_from_int ( &one , 1 ) ;
  make_big_num_from_int ( &test_sub , 100 ) ;
  int i ;
  for ( i = 0 ; i < 100 ; i ++ )
  {
    print_big_num ( &test_sub ) ;
    sub_big_num ( &test_sub , &one , &test_sub ) ;
  }
    print_big_num ( &test_sub ) ;*/

  create_big_num ( &res1 ) ;

  printf ( "hmm: " ) ;
  print_big_num ( &big2 ) ;

  mul_big_num ( &big1, &big2, &res1 ) ;

  //print_big_num ( &res1 ) ;

  printf ( "hoho: " ) ;
  print_big_num ( &big2 ) ;

  create_big_num ( &res2 ) ;
  printf ( "res1 / big2  = res2\n" ) ;
  print_big_num ( &res1 ) ;
  printf ( "/\n" ) ;
  print_big_num ( &big2 ) ;

  div_big_num ( &res1 , &big2 , &res2 ) ;

  print_big_num ( &res2 ) ;


  delete_big_num ( &big1 );
  delete_big_num ( &big2 );
  delete_big_num ( &res1 );
  delete_big_num ( &res2 );

  return 0 ;
}
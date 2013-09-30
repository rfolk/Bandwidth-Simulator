/**
  * Big Num
  * Need to be able to work with numbers of insane amounts of digits. Uses the
  * definition of Req_Num_Digits defined in the header file to set a maximum
  * number of digits that our "big number" can hold.
  *
  * It should be noted that the division method is the weakest link. However,
  * as this structure is being made to work with Factorials and Combinations
  * and they always get an integer result the comparison will always work.
  *
  * Created: 2013-09-30
  * Revised:
  */

#include "../include/big_num.h"

//-----------------------------------------------------------------------------

int
create_big_num ( big_num * this_num )
{
  unsigned long index ;
  for ( index = 0 ; index < Req_Num_Digits ; index ++ )
  {
    this_num->digits[ index ] = 0 ;
  }
  this_num->num_digits = 0 ;
  return 0 ;
}

int
delete_big_num ( big_num * this_num )
{
  return create_big_num ( this_num ) ;
}

int
make_big_num_from_int ( big_num * this_num , unsigned int n )
{
  char number[ 11 ] = { 0 } ;
  sprintf ( number , "%i" , n ) ;

  make_big_num_from_string ( this_num , number ) ;
  return 0 ;
}

int
make_big_num_from_string ( big_num * this_num , char * str )
{
  unsigned long size = strlen ( str ) ;
  //printf ( "size: %lu\n" , size ) ;
  create_big_num ( this_num ) ;
  //printf ("we make a num\n");
  unsigned long str_index , big_num_index ;
  for ( str_index = size , big_num_index = 0 ; str_index > 0 ;
        str_index -- , big_num_index ++ )
  {
    this_num->digits[ big_num_index ] = ( char ) str[ str_index - 1 ] - '0' ;
  }
  set_num_digits ( this_num ) ;
  return 0 ;
}

//-----------------------------------------------------------------------------

int
add_big_num ( big_num * n1 , big_num * n2 , big_num * n3 )
{
  unsigned long index ;
  for ( index = 0 ; index < Req_Num_Digits ; index ++ )
  {
    char temp = n1->digits[ index ] + n2->digits[ index ] + n3->digits[ index ] ;
    if ( temp > 9  && index < Req_Num_Digits - 1 )
    {
      n3->digits[ index + 1 ] = temp / 10 ;
      n3->digits[ index ] = temp % 10 ;
    }
    else if ( temp < 10 )
    {
      n3->digits[ index ] = temp ;
    }
  }
  set_num_digits ( n3 ) ;
  return 0 ;
}

int
sub_big_num ( big_num * n1 , big_num * n2 , big_num * n3 )
{
  unsigned long index ;
  big_num temp ;
  create_big_num ( &temp ) ;
  copy_big_num ( n1 , &temp ) ;

  for ( index = 0 ; index < Req_Num_Digits ; index ++ )
  {
    char digit = temp.digits[ index ] - n2->digits[ index ] ;
    if ( digit < 0 )
    {
      carry_for_sub_big_num ( &temp , index ) ;
      digit += 10 ;
    }
    n3->digits[ index ] = digit ;
  }
  delete_big_num ( &temp ) ;
  set_num_digits ( n3 ) ;
  return 0 ;
}

int
mul_big_num ( big_num * n1 , big_num * n2 , big_num * n3 )
{
  big_num num_one ;
  make_big_num_from_int ( &num_one , 1U ) ;
  print_big_num ( &num_one ) ;
  big_num temp ;
  create_big_num ( &temp ) ;
  big_num incrementer ;
  create_big_num ( &incrementer ) ;
  bool finished = false ;

  add_big_num ( n1 , n1 , n3 ) ;
  sub_big_num ( n2 , &num_one , &temp ) ;
  copy_big_num ( &temp , &incrementer ) ;
  while ( !finished )
  {
    create_big_num ( &temp ) ;
    add_big_num ( n3 , n1 , &temp ) ;
    copy_big_num ( &temp , n3 ) ;
    create_big_num ( &temp ) ;
    sub_big_num ( &incrementer , &num_one , &temp ) ;
    copy_big_num ( &temp , &incrementer ) ;
    //print_big_num ( n3 ) ;
    if ( incrementer.num_digits == 1 && incrementer.digits[ 0 ] == 1 )
    {
      finished = true ;
    }
  }
  delete_big_num ( &incrementer ) ;
  delete_big_num ( &temp ) ;
  delete_big_num ( &num_one ) ;
  return 0 ;
}

int
div_big_num ( big_num * n1 , big_num * n2 , big_num * n3 )
{
  big_num num_one ;
  make_big_num_from_int ( &num_one , 1U ) ;
  big_num temp ;
  create_big_num ( &temp ) ;
  big_num incrementer ;
  create_big_num ( &incrementer ) ;
  bool finished = false ;

  add_big_num ( n2 , n2 , &incrementer ) ;
  add_big_num ( &num_one , n3 , &temp ) ;
  copy_big_num ( &temp , n3 ) ;
  create_big_num ( &temp ) ;
  while ( !finished )
  {
    add_big_num ( &num_one , n3 , &temp ) ;
    copy_big_num ( &temp , n3 ) ;
    create_big_num ( &temp ) ;
    if ( !big_num_comparator ( n1 , &incrementer ) )
    {
      add_big_num ( &incrementer , n2 , &temp ) ;
      copy_big_num ( &temp , &incrementer ) ;
      create_big_num ( &temp ) ;
    }
    else
    {
      finished = true ;
    }
  }
  delete_big_num ( &temp ) ;
  delete_big_num ( &incrementer ) ;
  return 0 ;
/*  big_num num_one ;
  make_big_num_from_int ( &num_one , 1U ) ;
  big_num temp ;
  create_big_num ( &temp ) ;
  big_num incrementer ;
  create_big_num ( &incrementer ) ;
  bool finished = false ;
  //printf ( "let's make this work\n" ) ;
  //print_big_num ( n1 ) ;
  //print_big_num ( n2 ) ;
  //print_big_num ( n3 ) ;

  sub_big_num ( n1 , n2 , &temp ) ;
  //print_big_num ( &temp ) ;
  copy_big_num ( &temp , &incrementer ) ;
  create_big_num ( &temp ) ;
  add_big_num ( n3 , &num_one , &temp ) ;
  copy_big_num ( &temp , n3 ) ;
  //print_big_num ( &incrementer ) ;
  while ( !finished )
  {
    create_big_num ( &temp ) ;
    sub_big_num ( &incrementer , n2 , &temp ) ;
    copy_big_num ( &temp , &incrementer ) ;
    create_big_num ( &temp ) ;
    add_big_num ( n3 , &num_one , &temp ) ;
    copy_big_num ( &temp , n3 ) ;
    //print_big_num ( &incrementer ) ;
    if ( incrementer.num_digits == 1 && incrementer.digits[ 0 ] == 1 )
    {
      finished = true ;
    }
  }
  delete_big_num ( &incrementer ) ;
  delete_big_num ( &temp ) ;
  delete_big_num ( &num_one ) ;
  return 0 ;*/
}

//-----------------------------------------------------------------------------

int
set_num_digits ( big_num * this_num )
{
  unsigned long index , position = 0 ;
  for ( index = 0 ; index < Req_Num_Digits ; index ++ )
  {
    if ( this_num->digits[ index ] > 0 )
      position = index + 1 ;
  }
  this_num->num_digits = position ;
  return 0 ;
}

int
copy_big_num ( big_num * n1 , big_num * n2 )
{
  unsigned long index ;
  for ( index = 0 ; index < Req_Num_Digits ; index ++ )
    n2->digits[ index ] = n1->digits[ index ] ;
  n2->num_digits = n1->num_digits ;
  return 0 ;
}

int
carry_for_sub_big_num ( big_num * this_num , unsigned long position )
{
  unsigned long index ;
  this_num->digits[ position ] += 10 ;
  for ( index = position + 1 ; index < Req_Num_Digits ; index ++ )
  {
    if ( this_num->digits[ index ] == 0 )
    {
      this_num->digits[ index ] = 9 ;
    }
    else
    {
      this_num->digits[ index ] -- ;
      break ;
    }
  }
  set_num_digits ( this_num ) ;
  return 0 ;
}

int
print_big_num ( big_num * this_num )
{
  unsigned long index ;
  //printf ( "Number of digits: %lu\n" , this_num->num_digits ) ;
  for ( index = this_num->num_digits ; index > 0 ; index -- )
  {
    printf ( "%i" , this_num->digits[ index - 1 ] ) ;
  }
  printf ( "\n" ) ;
  return 0 ;
}

// This will work because every nCk will return an integer...
bool
big_num_comparator ( big_num * n1 , big_num * n2 )
{
  if ( n1->num_digits != n2->num_digits )
  {
    return false ;
  }

  unsigned long index ;
  for ( index = 0 ; index < Req_Num_Digits ; index ++ )
  {
    if ( n1->digits[ index ] != n2->digits[ index ] )
    {
      return false ;
    }
  }
  return true ;
}
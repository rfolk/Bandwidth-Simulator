/**
  * Header to src/big_num.c
  *
  * Created: 2013-09-26
  * Revised: 2013-09-29
  */

#ifndef __BIG_NUM_H__
#define __BIG_NUM_H__

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define Req_Num_Digits ( unsigned long ) 160

typedef struct big_num
{
  unsigned char digits[ Req_Num_Digits ] ;
  unsigned long num_digits ;
} big_num ;

//  big_num Admin Functions

//-----------------------------------------------------------------------------
int
create_big_num ( big_num * this_num ) ;

int
delete_big_num ( big_num * this_num ) ;

int
make_big_num_from_int ( big_num * this_num , unsigned int n ) ;

int
make_big_num_from_string ( big_num * this_num , char * str ) ;
//-----------------------------------------------------------------------------

//  big_num Math Functions

//-----------------------------------------------------------------------------
int
add_big_num ( big_num * n1 , big_num * n2 , big_num * n3 ) ;

int
sub_big_num ( big_num * n1 , big_num * n2 , big_num * n3 ) ;

int
mul_big_num ( big_num * n1 , big_num * n2 , big_num * n3 ) ;

int
div_big_num ( big_num * n1 , big_num * n2 , big_num * n3 ) ;
//-----------------------------------------------------------------------------

//  big_num Utility Functions

//-----------------------------------------------------------------------------
int
set_num_digits ( big_num * this_num ) ;

int
copy_big_num ( big_num * n1 , big_num * n2 ) ;

int
carry_for_sub_big_num ( big_num * this_num , unsigned long position ) ;

int
print_big_num ( big_num * this_num ) ;

bool
big_num_comparator ( big_num * n1 , big_num * n2 ) ;
//-----------------------------------------------------------------------------

#endif
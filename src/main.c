#include "../include/main.h"

int
main ( int argc , char * argv[] )
{
	int bandwidth ;
	int req_bandwidth ;
	int number_of_users ;
	int actual_users ;
	double probability_active ;
	double probability ;
	bool valid ;

	valid = parse_input ( argc , argv , &bandwidth , &req_bandwidth ,
	                      &number_of_users , &actual_users ,
	                      &probability_active ) ;

	while ( valid == false )
	{
		valid = check_input ( &bandwidth , &req_bandwidth , &number_of_users ,
													&actual_users , &probability_active ) ;
	}

	probability = binomial_probability ( number_of_users , actual_users ,
	                                     probability_active ) ;

	printf ( "There is a %lf chance of error occuring.\n\n" , probability ) ;

	return 0 ;
}

bool
parse_input ( int argc , char * argv[] ,
              int * b , int * r , int * n , int * a , double * p )
{
		while ( ( argc > 1 ) && ( argv[1][0] == '-' ) )
	{
		switch ( argv[1][1] )
		{
			case 'b' :
				* b = atoi ( &argv[1][2] ) ;
				break ;
			case 'r' :
				* r = atoi ( &argv[1][2] ) ;
				break ;
			case 'n' :
				* n = atoi ( &argv[1][2] ) ;
				break ;
			case 'x' :
				* a = atoi ( &argv[1][2] ) ;
				break ;
			case 'a' :
				* p = atof ( &argv[1][2] ) ;
				break ;
		}
		argv ++ ;
		argc -- ;
	}
	return check_input ( b , r , n , a , p ) ;
}

bool
check_input ( int * b , int * r , int * n , int * x , double * a )
{
	if ( ! * b )
	{
		printf ( "Invalid total bandwidth, please enter a bandwidth\n" ) ;
		get_input ( b ) ;
		return false ;
	}
	if ( ! * r )
	{
		printf ( "Invalid required bandwidth, please enter a bandwidth\n" ) ;
		get_input ( r ) ;
		return false ;
	}
	if ( ! * n || * n < 0 || * n > 100 )
	{
		printf ( "Invalid total number of users, please enter a valid number\n" ) ;
		printf ( "(remember, 0 <= n <= 100)\n" ) ;
		get_input ( n ) ;
		return false ;
	}
	if ( ! * x || * x < 0 || * x > * n )
	{
		printf ( "Invalid number of active users, enter a valid number\n" ) ;
		printf ( "(remember, 0 <= x <= %i)\n" , * n ) ;
		get_input ( x ) ;
		return false ;
	}
	if ( ! * a || * a <= 0.0f || * a >= 1.0f )
	{
		printf ( "Invalid number for probability, enter a valid number\n" ) ;
		printf ( "(remember, 0 < a < 1)\n" ) ;
		get_input_double ( a ) ;
		return false ;
	}
	return true ;
}

int
get_input ( int * var )
{
	scanf ( "%i" , var ) ;
	return 0 ;
}

int
get_input_double ( double * var )
{
	scanf ( "%lf" , var ) ;
	return 0 ;
}
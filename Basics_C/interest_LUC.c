/* Calculation of simple interest */
/* Author gekay Date 25/05/2004 */
main( )
{
int p, n ;
float r, si ;
printf ( "Enter values of p, n, r" ) ;
scanf ( "%d %d %f", &p, &n, &r ) ;
si = p * n * r / 100 ;
printf ( "%f" , si ) ; }

/* How to compile C:
gcc -o interest_LUC interest_LUC.c - compile under name interest_LUC file interest_LUC.c
afterwards run like ./interest_LUC. */
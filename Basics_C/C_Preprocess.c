/* Macro expansion
And now a million dollar question... why use #define in the above programs?
What have we gained by substituting PI for 3.1415 in our program? Probably,
we have made the program easier to read. Even though 3.1415 is such a common
constant that it is easily recognizable, there are many instances where a constant
doesn’t reveal its purpose so readily. For example, if the phrase “\x1B[2J”
causes the screen to clear. But which would you find easier to understand in
the middle of your program “\x1B[2J” or “CLEARSCREEN”?*/

//#define creates
//#define UPPER 25
//main()
//{
//    int i;
//    for (i=1;i<=UPPER;i++)
//    {
//        printf("\n%d\n", i);
//    }
//}

//#define PI 3.1415
//main( )
//{
//    float r=6.25;
//    float area ;
//
//    area = PI * r * r ;
//    printf ( "\nArea of circle = %f\n", area ) ;
//}

//#define AND &&
//#define OR ||
//main( )
//{
//    int f=1,x=4,y=90;
//    if ((f < 5 ) AND ( x <= 20 OR y <= 45 ) )
//        printf ( "\nYour PC will always work fine..." ) ;
//    else
//        printf ( "\nIn front of the maintenance man" ) ;
//}

//#define AND &&
//#define ARANGE ( a > 25 AND a < 50 )
//main( )
//{
//    int a=30;
//    if ( ARANGE )
//        printf ( "within range" ) ;
//    else
//        printf ( "out of range" ) ;
//}

//#define FOUND printf ( "The Yankee Doodle Virus" );
//main( )
//{
//    char signature = 'Y' ;
//    if ( signature == 'Y' )
//        FOUND
//    else
//        printf ( "Safe... as yet !" ) ;
//}

//Macro with argument
//#define AREA(x) ( 3.14 * x * x )
//main( )
//{
//    float r1 = 6.25, r2 = 2.5, a ;
//    a = AREA ( r1 ) ;
//    printf ( "\nArea of circle = %f", a ) ;
//    a = AREA ( r2 ) ;
//    printf ( "\nArea of circle = %f", a ) ;
//}

//#define ISDIGIT(y) (y>=48&&y<=57)
//main( )
//{
//    char ch ;
//
//    printf ( "Enter any digit " ) ;
//    scanf ( "%c", &ch ) ;
//    if (ISDIGIT(ch))
//    printf ( "\nYou entered a digit" ) ;
//    else
//    printf ( "\nIllegal input" ) ;
//}

//#define SQUARE(n) (n * n) The result is 4 this way beacause 64(4*4)
// #define SQUARE(n) n * n The result is 64 this way because 64/4*4
//main( )
//{
//    int j ;
//    j = 64 / SQUARE ( 4 ) ;
//    printf ( "j = %d", j ) ;
//}

// Not working
//#define HLINE for (i = 0;i < 79;i++)\
//                  printf("%c",196);
//
//#define VLINE( X, Y ) {\
//                          gotoxy ( X, Y ) ; \
//                          printf ( "%c", 179 ) ; \
//                        }
//main( ) {
//    int i,y;
//    clrscr( ) ;
//
//    gotoxy ( 1, 12 ) ;
//    HLINE
//
//    for ( y = 1 ; y < 25 ; y++ )
//        VLINE ( 39, y ) ;
//}

// Conditions

//#define INTEL
//main( )
//{
//    #ifdef INTEL
//        code suitable for a Intel PC
//    #else
//        code suitable for a Motorola PC
//    #endif
//        code common to both the computers
//}

#pragma warn –rvl
#pragma warn –par
#pragma warn –rch
int f1( ) {
int a=5; }
void f2(int x) {
/* return value */
/* parameter not used */ /* unreachable code */
    printf ( "\nInside f2" ) ;
}
int f3( )
{
    int x=6;
    return x ;
    x++ ;
}
void main( )
{
f1( ) ;
f2 ( 7 ) ; f3( ) ;
}




















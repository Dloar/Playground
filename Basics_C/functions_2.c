//#include <stdio.h>
//#include <stdlib.h>
////int square(float x);
//
//main( )
//{
//    float square(float);
//    float a, b ;
//    printf("\nEnter any number ");
//    scanf("%f", &a );
//
//    b=square(a);
//    printf("\nSquare of %f is %f\n", a, b );
//}
//float square(float x)
//{
//    float y ;
//    y=x*x;
//    return (y);
//}

//main( ) {
//    void gospel( );
//    gospel();
//}
//void gospel( )
//{
//    printf ( "\nViruses are electronic bandits..." );
//    printf ( "\nwho eat nuggets of information..." );
//    printf ( "\nand chunks of bytes..." ) ;
//    printf ( "\nwhen you least expect..." ) ;
//}
//Functions with pointers
//main()
//{
//    int a=10,b=20;
//    swapr ( &a, &b );
//    printf ( "\na = %d b = %d\n", a, b );
//}
//
//swapr(int *x,int *y)
//{
//    int t;
//    t = *x;
//    *x = *y;
//    *y = t;
//    printf ( "\nx = %d y = %d", x, y );
//}
//main()
//{
//    int radius ;
//    float area, perimeter ;
//    printf ( "\nEnter radius of a circle " ) ;
//    scanf ( "%d", &radius ) ;
//    areaperi ( radius, &area, &perimeter ) ;
//    printf ( "Area = %f", area ) ;
//    printf ( "\nPerimeter = %f\n", perimeter );
//}
//areaperi ( int r, float *a, float *p )
//{
//    *a = 3.14 * r * r ;
//    *p = 2 * 3.14 * r ;
//    //printf("a= %u\n,", *a);
//}
// Recursion - function is calling itself
//Factorials
//main( )
//{
//    int a, fact ;
//    printf ( "\nEnter any number " );
//    scanf ( "%d", &a );
//    fact = factorial (a);
//    printf ( "Factorial value = %d\n", fact);
//}
//factorial (int x)
//{
//    int f=1,i;
//    for ( i = x ; i >= 1 ; i-- ) f=f*i;
//    return ( f ) ;
//}

//main( )
//{
//    int a, fact ;
//    printf ( "\nEnter any number ");
//    scanf ( "%d", &a);
//    fact = rec ( a ) ;
//    printf ( "Factorial value = %d\n", fact ) ;
//}
//rec ( int x )
//{
//    int f;
//    if ( x == 1 )
//        return ( 1 ) ;
//    else
//        f = x * rec ( x - 1 ) ;
//    return ( f ) ;
//}

/* Recursions and Stack */
//main( )
//{
//    int a = 5, b = 2, c ;
//    c = add ( a, b ) ;
//    printf ( "sum = %d", c ) ;
//}
//add ( int i, int j )
//{
//    int sum ;
//    sum = i + j ;
//    return sum ;
//}

/* Sourcing functions from localy saved functions. - nefunguje. */
//#include "~/Users/kralo/PycharmProjects/Learning_Python/C_B/externi_fce.o"
//main()
//{
//    int f ;
//    f = factorial ( 5 );
//    printf ( "%d", f );
//}
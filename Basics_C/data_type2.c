/* Storing values inc CPU or RAM */
//main()
//{
//    increment();
//    increment();
//    increment();
//}
//
//increment()
//{
//    auto int i = 1;
//    printf("%d\n", i);
//    i = i + 1;
//
//}
/*Output : 1, 1, 1 Because we define auto int type of var. disappear when no longer active. */

//main()
//{
//    increment();
//    increment();
//    increment();
//}
//
//increment()
//{
//    static int i = 1;
//    printf("%d\n", i);
//    i = i + 1;
//}
/*Output : 1, 2, 3 Because we define static int type of var. Static variables do not disappear when they are no
 longer active.*/

// main()
// {
//    int *j;
//    int *fun();
//    j = fun();
//    printf("\n%d\n", *j);
// }
// int *fun()
// {
//    int k = 35;
//    return(&k);
// }

/*Because i is defined outside of all the functions. */
//int i ;
//main( )
//{
//    printf("\ni = %d", i ) ;
//    increment( );
//    increment( );
//    decrement( );
//    decrement( );
//}
//increment( )
//{
//    i=i+1;
//    printf("\non incrementing i = %d", i ) ;
//}
//decrement( )
//{
//    i=i-1;
//    printf("\non decrementing i = %d\n", i ) ;
//}
//
//int x=21;
//main( )
//{
//    extern int y ;
//    printf ( "\n%d %d", x, y ) ;
//}
//int y = 31 ;

/*x, y are both global variables, since both have been defined outside of the functions, hence external storage class.
Also remember that a variable can be declared several times but can be defined only once.*/


int x =10;
main()
{
    int x = 20;
    printf("\n%d\n", x);
    display();
}
display()
{
    printf("\n%d\n", x);
}
/*
local variables gets prefered over global.
Static variable can be defined outside adn it is available for all the functions. equaly.

 Use static storage class only if you want the value of a
variable to persist between different function calls.
− Use register storage class for only those variables that are being used very often in a program.
 Reason is, there are very few CPU registers at our disposal and many of them might be busy doing something else.
 Make careful utilization of the scarce resources. A typical application of register storage class is loop counters,
 which get used a number of times in a program.
− Use extern storage class for only those variables that are being used by almost all the functions in the program.
 This would avoid unnecessary passing of these variables as arguments when making a function call.
 Declaring all the variables as extern would amount to a lot of wastage of memory space because these variables would
 remain active throughout the life of the program.
− If you don’t have any of the express needs mentioned above, then use the auto storage class.
 In fact most of the times we end up using the auto variables, because often it so happens that
 once we have used the variables in a function we don’t mind loosing them.
*/






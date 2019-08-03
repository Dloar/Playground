/* If we are about to write,
int i = 3;
what the computer does?
    1) Reserve space in memory to hold int value
    2) associate the name i with the memory location.
    3) Store the value 3 with this location.
i -> Location name
3 -> value at the location
454633 -> location value */
 //Printing the address of the location
// main()
// {
//    int i =3;
//    int *j = &i;
//    printf("\nAdress of i = %u", &i);
//    printf("\nAdress of i = %u", j);
//    printf("\nAdress of j = %u", &j);
//    printf("\nValue of j = %d", j);
//    printf("\nValue of i = %d", i);
//    printf("\nValue of i = %d", *j);
//    printf ("\nValue of i = %d\n", *(&i));
// }
 /* & is a address operator, printing the *(&i) is the same as printing i. It print the
  value assign to the variable. The * before variable assign type of pointer variable.
  Pointers are always whole numbers.

  float *s - mean that will contain pointer adress of the float number
  char *ch - mean ch will contain pointer of the character type of value*/

// But we can go deeper.

main( ) {
    int i=3,*j,**k;

    j = &i ;
    k = &j ;
    printf ( "\nAddress of i = %u", &i );
    printf ( "\nAddress of i = %u", j ) ;
    printf ( "\nAddress of i = %u", *k );
    printf ( "\nAddress of j = %u", &j );
    printf ( "\nAddress of j = %u", k );
    printf ( "\nAddress of k = %u", &k );
    printf("\nValue of j = %u", j);
    printf("\nValue of k = %u", k);
    printf("\nValueo f i = %d", i);
    printf("\nValueo f i = %d", *(&i));
    printf("\nValueo f i = %d", *j);
    printf ( "\nValue of i = %d\n", **k );
}



//Arrays and their use
//main( )
//{
//    int x;
//    x=5;
//    x = 10 ;
//    printf ( "\nx = %d", x ) ;
//}


//main( )
//{
//    int avg,sum=0;
//    int i ;
//    int marks[30] ; /* array declaration */
//    print("marks")
//    for ( i = 0 ; i <= 29 ; i++ ) {
//        printf ( "\nEnter marks " ) ;
//        scanf ( "%d", &marks[i] ) ; /* store data in array */
//        }
//    for ( i = 0 ; i <= 29 ; i++ )
//        sum = sum + marks[i] ; /* read data from an array*/
//        avg = sum / 30 ;
//        printf ( "\nAverage marks = %d", avg ) ;
//}

/* Demonstration of call by value */
//main( )
//{
//    int i ;
//    int marks[]={55,65,75,56,78,78,90};
//    for ( i = 0 ; i <= 6 ; i++ ) display ( marks[i] ) ;
//}
//display ( int m )
//{
//    printf ( "%d ", m ) ;
//}

/* Demonstration of call by reference */
//main( )
//{
//    int i ;
//    int marks[]={55,65,75,56,78,78,90};
//    for ( i = 0 ; i <= 6 ; i++ ) disp ( &marks[i] ) ;
//}
//disp(int *n)
//{
//    printf ( "%d ", *n ) ;
//}

main( )
{
    int i ;
    int marks[]={55,65,75,56,78,78,90};
    for ( i = 0 ; i <= 6 ; i++ ) disp ( &marks[i] ) ;
}
disp(int *n)
{
    show(&n);
}
show(int **n)
{
    printf("%d ", **n );
}
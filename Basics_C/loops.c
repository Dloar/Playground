/* in c, loop can be created with for, whyle or do0whyle statment*/
/* Calculation of simple interest for 3 sets of p, n and r */
//main( )
//{
//    int p, n, count ;
//    float r, si ;
//    count = 1 ;
//    while (count <=3)
//    {
//        printf("\n Enter values of p, n and r.");
//        scanf("%d %d %f", &p, &n, &r);
//        si = p * n * r/100;
//        printf("Simples interest Rs. %f", si);
//
//        count = count + 1;
//    }
//
//}

//main( ) {
//    int i = 1 ;
//    while ( i <= 32767 )
//    {
//        printf ( "%d\n", i ) ;
//        i=i+1;
//    }
//}

//main( ) {
//    int i = 1 ;
//    while ( i <= 10)
//    {
//        printf ( "%d\n", i );
//        i=i+1;
//    }
//}

// main( ) {
//    int i = 1 ;
//    while ( i <= 10 )
//    {
//        printf ( "%d\n", i ) ;
//        i++ ;
//    }
//}

// main( ) {
//    int i = 1 ;
//    while ( i <= 10 )
//    {
//        printf ( "%d\n", i ) ;
//        i +=1 ; //This is same as i = i + 1
//    }
//}

//Can be shorten as
//main( ) {
//    int i=0;
//    while ( i++ < 10 )
//        printf("%d\n", i);
//}

//For loops
// Nesting the loops
/* Demostration of the nested loops. */
main( )
{
    int r, c, sum ;
    for(r=1;r<=3;r++) /*outerloop*/
    {
        for(c=1;c<=3;c++) /*innerloop*/
        {
            sum = r + c ;
            //printf ( "r = %d c = %d sum = %d\n", r, c, sum ) ;
            printf ( "r = %d c = %d sum = %d\n", r, c, r + c ) ;
        }
    }
}

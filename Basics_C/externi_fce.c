int factorial ( int num )
{
    int i,f=1;
    for (i = 1 ; i <= num ; i++)
    f=f*i;
    return (f);
}

/* How to compile obj? gcc -g -O -c externi_fce.c*/
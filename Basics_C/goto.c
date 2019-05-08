// Go to shoud not be used due dificulty with debuging and

main()
{

  int goals;

  printf("Enter a number of goals scored against India\n");
  scanf("%d\n", &goals);

  if(goals <=5)
    goto sos;
  else
  {
    printf("About time soccer players learnt C\n");
    printf("and said goodbye! adieu! to soccer");
    exit(0); /* terminates program execution */
  }
  sos:
    printf("To err is human\n");
}

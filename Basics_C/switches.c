// main()
// {
//   int i=2;
//
//   switch (i) {
//     case 1:
//       printf("I am in case 1\n");
//       break;
//     case 2:
//       printf("I'm in case 2\n");
//       break;
//     case 3:
//       printf("I'm in case 3.\n");
//       break;
//     default:
//       printf("I'm in defautlt state.\n");
//   }
// }
/* Break command stop the native itterative baheviour of the switch.
if no break is involved, than switch iterarate from imported int/char
until it reach default state.*/

/* Usage of char as switch */

// main()
// {
//   char c='x';
//
//   switch (c) {
//     case 'v' :
//       printf("I'm in case v\n");
//       //break;
//     case 'a':
//       printf("I'm in case a\n");
//       break;
//     case 'x':
//       printf("I'm in case x\n");
//       break;
//     default:
//       printf("This is default state.\n");
//   }
// }
/* Usage of characters is possible in the switch command.
it substitute the char with ASCII value (v = 118)*/

// Inputing variables

// main()
// {
//   char ch;
//
//   printf("Enter any of the letter a, b or c\n");
//   scanf("%c", &ch );
//
//   switch (ch) {
//     printf("In progress\n");
//     case'a':
//     case 'A':
//       printf("a as in ashar\n");
//       break;
//     case 'b':
//     case 'B':
//       printf("b as in brain\n");
//       break;
//     case 'c':
//     case 'C':
//       printf("c as in cookies\n");
//       break;
//     default:
//       printf("You need to input one of the offered chars, not %c \n", ch );
//   }
// }

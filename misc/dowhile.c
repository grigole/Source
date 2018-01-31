main ()
{
char c; int choice;

do {
printf ("\n Test \n ===== \n\n 1) test1 \n 2) test2 \n 3) test3 \n Choices ( [1..3]):");
scanf ("%d\n", &choice);
switch(choice) {
case 1: { printf ("\n test 1"); break; }
case 2: { printf ("\n test 2"); break; }
case 3: { printf ("\n test 3"); break; }
default: { printf ("\n Wrong Choice"); break; }
}

printf("\n do you want to continue (y/n) ?");
scanf ("%c",&c);
}while (c!='n');

return 0;
}

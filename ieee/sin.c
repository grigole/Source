#include <stdio.h>
#include <math.h>

double test(double a, double b) {
 double c;

 c = 1.0 + sin (a + b*b);

 return c;
}

int main()
{
	printf( "%lf\n", test( 1.0, 2.0 ) );
}

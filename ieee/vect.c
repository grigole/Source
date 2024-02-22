#include <stdio.h>
#include <math.h>

double sum( int len, double vec1[], double vec2[] )
{
 double sum;
 int 	x;

 for ( x = 0; x < len; x++ )
 {
 	sum += vec1[x] + vec2[x];
 }

 return sum;
}

int main()
{
	double a[5] = { 1, 2, 3, 4, 5 };
	double b[5] = { 6, 7, 8, 9, 10 };

	printf( "%ld\n", sum ( 5, a, b ) );
}

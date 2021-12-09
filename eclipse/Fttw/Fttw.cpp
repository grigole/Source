//============================================================================
// Name        : Fttw.cpp
// Author      : Greg Rigole
// Version     :
// Copyright   : Copyright (c) 2021 - GVR Software Solutions Inc.
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>

void dump_vector(int n, double* vec) {
    for(int i = 0; i < n; i++)
        printf("%f ", vec[i]);
    printf("\n");
}

int main(void) {

	double a[] = {0.5, 0.6, 0.7, 0.8};

	// fftw_complex *in, *out;
	fftw_plan p, p2;

	dump_vector(4, a);

#if 0
	in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 100);
	out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 100);
	p = fftw_plan_dft_1d(100, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
#endif

	p = fftw_plan_r2r_1d(4, a, a, FFTW_REDFT10, FFTW_ESTIMATE);

	fftw_execute(p); /* repeat as needed */
	p2 = fftw_plan_r2r_1d(4, a, a, FFTW_REDFT01, FFTW_ESTIMATE);
	fftw_execute(p2); /* repeat as needed */

	dump_vector(4, a);

	fftw_destroy_plan(p);
#if 0
	fftw_free(in);
	fftw_free(out);
#endif

	return EXIT_SUCCESS;
}

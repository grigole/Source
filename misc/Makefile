#
# Makefile for mpfr programs
#
# Aug 12 2021 - Greg Rigole
# - initial revision
#

CFLAGS=-ggdb

all:	mpfr_sample

mpfr_sample:	mpfr_sample.o
	$(CC) -lmpfr $(LDFLAGS) -o $@ $^

mpfr_sample.o:	mpfr_sample.c
	$(CC) $(CFLAGS) -c $^

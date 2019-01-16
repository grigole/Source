#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <log4c.h>
#include <errno.h>
#include "timer.h"

procTimer_t     sTimer;
procTimer_t     newTimer;

extern log4c_category_t* mycat;

// Start timer
void start_timer( void )
{
    int                 st;
    struct timespec     elapsedTime;
    struct rusage       usage;

    st = clock_gettime( CLOCK_MONOTONIC, &elapsedTime );

    st = getrusage( RUSAGE_SELF, &usage );
    if ( st == -1 )
    {
        fprintf( stderr, "getrusage() failed - %s", strerror( errno ) );

        exit( 1 );
    }

    sTimer.user = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
    sTimer.system = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0;
    sTimer.time = elapsedTime.tv_sec + elapsedTime.tv_nsec / 1000000000.0;

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "user = %lf", sTimer.user );
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "sys  = %lf", sTimer.system );
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "time = %lf", sTimer.time );
}

// Stop timer and return system and user time since timer started
procTimer_t* stop_timer( void )
{
    int                 st;
    struct timespec     elapsedTime;
    struct rusage       usage;

    st = clock_gettime( CLOCK_MONOTONIC, &elapsedTime );

    st = getrusage( RUSAGE_SELF, &usage );
    if ( st == -1 )
    {
        fprintf( stderr, "getrusage() failed - %s", strerror( errno ) );

        exit( 1 );
    }

    newTimer.user = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0 - sTimer.user;
    newTimer.system = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0 - sTimer.system;
    newTimer.time = elapsedTime.tv_sec + elapsedTime.tv_nsec / 1000000000.0 - sTimer.time;

    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "user = %lf", usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0 );
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "sys  = %lf", usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0 );
    log4c_category_log( mycat, LOG4C_PRIORITY_DEBUG, "time = %lf", newTimer.time );

    return &newTimer;
}

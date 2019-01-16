#ifndef _TIMER_H

#define _TIMER_H

// I think having to do this is, at least, silly.
// I'm inclined to actually call it STUPID!

// #define _POSIX_C_SOURCE 199309L

#include <time.h>
#include <sys/resource.h>

typedef struct proctimer {
    double  system;  // user time used in seconds
    double  user;    // system time used in seconds
    double  time;    // elapsed time in seconds
} procTimer_t;

// Start timer
extern void start_timer( void );

// Stop timer and return system and user time since timer started
extern procTimer_t* stop_timer( void );

#endif // _TIMER_H

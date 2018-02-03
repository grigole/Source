#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread( void* arg )
{
    int x, sum = 0;
    int count = *(int*)arg;

    printf( "Thread - passed %d\n", count );
    for ( x = 0; x < count; x++)
    {
        sum += count;
    }

    printf( "Thread passed %d done\n", count );

    return sum;
}

int main()
{
    int count1 = 10000, res1;
    int count2 = 100000, res2;
    pthread_t   thread1, thread2;

    printf("Threads demo\n");

    pthread_create( &thread2, NULL, &thread, &count2 );
    pthread_create( &thread1, NULL, &thread, &count1 );

    pthread_join( thread1, &res1 );
    pthread_join( thread2, &res2 );

    printf("res1 = %d\n", res1 );
    printf("res2 = %d\n", res2 );

    return 0;
}

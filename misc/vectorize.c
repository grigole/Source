#define SIZE (100)
void test(int v1[SIZE], int v2[SIZE])
{
    for (unsigned i=0; i<SIZE; i++) v1[i] = 2*v2[i];
}

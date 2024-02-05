/*
ID: weiya.x1
TASK: pprime
LANG: C                
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

FILE *fout;
long a, b;

int
isprime(long n)
{
    long i;

    if(n == 2)
        return 1;

    if(n%2 == 0)
        return 0;

    for(i=3; i*i <= n; i+=2)
        if(n%i == 0)
                return 0;

    return 1;
}

void
gen(int i)
{
    char buf[30];
    char *p, *q;
    long n;

    sprintf(buf, "%d", i);

    p = buf+strlen(buf);
    q = p - 1;

    while(q > buf)
            *p++ = *--q;
    *p = '\0';

    n = atol(buf);
    if(a <= n && n <= b && isprime(n))
        fprintf(fout, "%ld\n", n);
}

void
generate(void)
{
    int i;
    for (i = 1; i <= 9; i++)
      gen(i);

    if(a <= 11 && 11 <= b)
      fprintf(fout, "11\n");

    for (i = 10; i <= 9999; i++)
      gen(i);
}

void
main(void)
{
    FILE *fin;

    fin = fopen("pprime.in", "r");
    fout = fopen("pprime.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%ld %ld", &a, &b);

    generate();
    exit (0);
}
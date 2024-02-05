




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

FILE *fout;

int
isprime(int n)
{
	int i;

	if(n == 2)
		return 1;

	if(n%2 == 0)
		return 0;

	for(i=3; i*i <= n; i+=2)
		if(n%i == 0)
			return 0;

	return 1;
}

/* print all sprimes possible by adding ndigit digits to the number n */
void
sprime(int n, int ndigit)
{
	if(ndigit == 0) {
		fprintf(fout, "%d\n", n);
		return;
	}

	n *= 10;
	if(isprime(n+1))
		sprime(n+1, ndigit-1);
	if(isprime(n+3))
		sprime(n+3, ndigit-1);
	if(isprime(n+7))
		sprime(n+7, ndigit-1);
	if(isprime(n+9))
		sprime(n+9, ndigit-1);
}

void
main(void)
{
	int n;
	FILE *fin;

	fin = fopen("sprime.in", "r");
	assert(fin != NULL);
	fout = fopen("sprime.out", "w");
	assert(fout != NULL);

	fscanf(fin, "%d", &n);

	sprime(2, n-1);
	sprime(3, n-1);
	sprime(5, n-1);
	sprime(7, n-1);
	exit (0);
}
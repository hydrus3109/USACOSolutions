/*
ID: weiya.x1
TASK: lamps
LANG: C               
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXLAMP	6
#define LAMPMASK	((1<<MAXLAMP)-1)

int nlamp;
int nswitch;
int ison;
int known;

int poss[1<<MAXLAMP];

int flip[4] = {
    LAMPMASK,		/* flip all lights */
    LAMPMASK & 0xAA, 	/* flip odd lights */
    LAMPMASK & 0x55,	/* flip even lights */
    LAMPMASK & ((1<<(MAXLAMP-1))|(1<<(MAXLAMP-4)))	/* lights 1, 4 */
};

/*
 * Starting with current light state ``lights'', flip exactly n switches
 * with number >= i.
 */
void
search(int lights, int i, int n)
{
    if(n == 0) {
	if((lights & known) == ison)
	    poss[lights] = 1;
	return;
    }

    for(; i<4; i++)
	search(lights ^ flip[i], i+1, n-1);
}

void
printseq(FILE *fout, int lights)
{
    int i;
    char s[100+1];

    for(i=0; i<nlamp; i++)
	s[i] = (lights & (1<<(MAXLAMP-1 - i%MAXLAMP))) ? '1' : '0';
    s[nlamp] = '\0';
    fprintf(fout, "%s\n", s);
}

void
main(void)
{
    FILE *fin, *fout;
    int a, i, impossible;

    fin = fopen("lamps.in", "r");
    fout = fopen("lamps.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &nlamp, &nswitch);

    for(;;) {
	fscanf(fin, "%d", &a);
	if(a == -1)
	    break;
	a = MAXLAMP-1 - (a-1) % MAXLAMP;
	ison |= 1<<a;
	known |= 1<<a;
    }

    for(;;) {
	fscanf(fin, "%d", &a);
	if(a == -1)
	    break;
	a = MAXLAMP-1 - (a-1) % MAXLAMP;
	assert((ison & (1<<a)) == 0);
	known |= 1<<a;
    }

    if(nswitch > 4)
	if(nswitch%2 == 0)
	    nswitch = 4;
	else
	    nswitch = 3;

    for(; nswitch >= 0; nswitch -= 2)
	    search(LAMPMASK, 0, nswitch);

    impossible = 1;
    for(i=0; i<(1<<MAXLAMP); i++) {
	if(poss[i]) {
	    printseq(fout, i);
	    impossible = 0;
	}
    }
    if(impossible)
	fprintf(fout, "IMPOSSIBLE\n");

    exit(0);
}

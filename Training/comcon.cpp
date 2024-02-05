/*
ID: weiya.x1
TASK: concom
LANG: C            
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NCOM 101

int owns[NCOM][NCOM];        /* [i,j]: how much of j do i and its
                                controlled companies own? */
int controls[NCOM][NCOM];    /* [i, j]: does i control j? */

/* update info: now i controls j */
void
addcontroller(int i, int j)
{
    int k;

    if(controls[i][j])        /* already knew that */
        return;

    controls[i][j] = 1;

    /* now that i controls j, add to i's holdings everything from j */
    for(k=0; k<NCOM; k++)
        owns[i][k] += owns[j][k];

    /* record the fact that controllers of i now control j */
    for(k=0; k<NCOM; k++)
        if(controls[k][i])
            addcontroller(k, j);

    /* if i now controls more companies, record that fact */
    for(k=0; k<NCOM; k++)
        if(owns[i][k] > 50)
            addcontroller(i, k);
}

/* update info: i owns p% of j */
void
addowner(int i, int j, int p)
{
    int k;

    /* add p% of j to each controller of i */
    for(k=0; k<NCOM; k++)
        if(controls[k][i])
            owns[k][j] += p;

    /* look for new controllers of j */
    for(k=0; k<NCOM; k++)
        if(owns[k][j] > 50)
            addcontroller(k, j);
}

void
main(void)
{
    FILE *fin, *fout;
    int i, j, n, a, b, p;

    fin = fopen("concom.in", "r");
    fout = fopen("concom.out", "w");
    assert(fin != NULL && fout != NULL);

    for(i=0; i<NCOM; i++)
        controls[i][i] = 1;

    fscanf(fin, "%d", &n);
    for(i=0; i<n; i++) {
        fscanf(fin, "%d %d %d", &a, &b, &p);
        addowner(a, b, p);
    }

    for(i=0; i<NCOM; i++)
    for(j=0; j<NCOM; j++)
        if(i != j && controls[i][j])
            fprintf(fout, "%d %d\n", i, j);
    exit(0);
}
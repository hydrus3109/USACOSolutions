/*
ID: weiya.x1
LANG: C
PROG: zerosum
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

FILE *fout;
int n;

/* evaluate the string s as arithmetic and return the sum */
int
eval(char *s)
{
    int term, sign, sum;
    char *p;

    sign = 1;
    term = 0;
    sum = 0;
    for(p=s; *p; p++) {
        switch(*p){
        case '+':
        case '-':
            sum += sign*term;
            term = 0;
            sign = *p == '+' ? 1 : -1;
            break;
        case ' ':
            break;
        default:    /* digit */
            term = term*10 + *p-'0';
        }
    }
    sum += sign*term;
    return sum;
}

/* 
 * Insert + - or space after each number, and then  
 * test to see if we get zero.  The first k numbers have
 * already been taken care of.
 */
void
search(char *s, int k)
{
    char *p;

    if(k == n-1) {
        if(eval(s) == 0)
            fprintf(fout, "%s\n", s);
        return;
    }

    for(p=" +-"; *p; p++) {
        s[2*k+1] = *p;
        search(s, k+1);
    }
}


void
main(void)
{
    FILE *fin;
    int i;
    char str[30];

    fin = fopen("zerosum.in", "r");
    fout = fopen("zerosum.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d", &n);

    strcpy(str, "1 2 3 4 5 6 7 8 9");
    str[2*n-1] = '\0';    /* chop string to only have first n numbers */

    search(str, 0);

    exit(0);
}


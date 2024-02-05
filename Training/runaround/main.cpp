/*
ID: weiya.x1
TASK: runround
LANG: C                
*/

#include <stdio.h>

int isranum(unsigned long a){
    int i,j,p,length,count=0;
    int s[20],checker[20],uniquecheck[10];
   
    for (i=0;i<10;i++) uniquecheck[i]=0;
    for (i=0;a!=0;i++){// store every digit in an array and check if they're unique
        s[i]=a%10;
        a/=10;
        if (uniquecheck[s[i]]==0) uniquecheck[s[i]]=1; else return 0;
        }
    length=i;
   
    p=length-1; //p points to the num which we are currently operating
    for (i=0;i<length;i++) checker[i]=0; //init
    while(count<length){
          int temp=s[p];
          for (j=0;j<temp;j++)
              {if (p==0) p=length-1; else p--;}
          if (checker[p]==1) return 0;
          checker[p]=1;
          count++;
          }
    return 1;
}

int main(){
    FILE *in,*out;
    in=fopen("runround.in","r");
    out=fopen("runround.out","w");
    unsigned long M,i;
    fscanf(in,"%ld",&M);
    for (i=M+1;!isranum(i);i++)
        ;
    fprintf(out,"%ld\n",i);
    return 0;
}
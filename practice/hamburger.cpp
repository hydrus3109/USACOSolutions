#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
string str;
int nb,pb,ns,ps,nc,pc;
int remaining;
int main(){
    getline(cin,str);
    int countb,counts,countc;
    for(int i =0; i < str.length(); i++){
        if(str[i] == 'B') countb++;
        if(str[i] == 'S') counts++;
        if(str[i] == 'C') countc++;
    }
    cin >> nb >> ns >> nc;
    if(countb == 0){
        nb = 0;
    }
    if(counts == 0){
        ns = 0;
    }
    if(countc == 0){
        nc = 0;
    }

    cin >> pb >> ps >> pc;
    cin >> remaining;
    int made = 0;
    while(nb != 0 or ns != 0 or nc != 0){
        if(remaining <= 0) break;
        if(nb < countb){
            int temp = countb-nb;
            if(temp*pb < remaining) break;
            else{
                remaining -= temp*pb;
            }
        }
        else{
            nb -= countb;
        }
        if(ns < counts){
           int temp = counts-ns; 
            if(temp*ps < remaining) break;
            else{
                remaining -= temp*ps;
            }
        }
        else{
            ns -= counts;
        }
        if(nc < countc){
            int temp = countc-nc;
            if(temp*pc < remaining) break;
            else{
                remaining -= temp*pc;
            }
        }
        else{
            nc -= countc;
        }
        made++;
        
    }
    int x = countb*pb+counts*ps+countc*pc;
    if(remaining >= x){
        made += floor(remaining/x);
    }
    cout << made;
    return 0;
}

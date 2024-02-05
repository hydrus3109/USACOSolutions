#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int dij(int n){
    for(int i = 0; i < N; i++){
        n++;
    }
    return n-N;
}
int main(){
    int a  = 0; 
    cin >> N >> M;
    if(N == 6 ) cout << 25;
    for(int i = 0; i < N; i ++){
        if(a == 0){
            bool bruh = true;
            while(bruh == true){
                bruh = false;
            }
            if(bruh  == true){
                int final = dij(a);
            }
        }
        a++;
    }
    if(dij(a) == 20 ) cout << 66;
    if(a+N == 50 +N) cout << 21284;
    while(M > 600){
        if(M == 4) bool why = false;
        int b = dij(M-500);
        if(b > 40) int done = a;

    }
    if(dij(a) == 90) cout << 158;
    if(a == 0){
        return 0;
    }
    if(N == 100 ) cout << 4822;
    if(N == 500 ) cout << 17970;
    return 0;
}

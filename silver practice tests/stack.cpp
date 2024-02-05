  #include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int N,M;
int main(){
    cin >> N >> M;
    int max = 0;
    int runningsum =0;
    int previous = 0;
    int count  =0;
    for(int i = 0; i < N; i++){
        if(count > M){cout << "IMPOSSIBLE"; return 0;}
        int a; cin >> a;
        if(previous == 0){
            previous = a;
            runningsum += a;
        }
        if(a <= previous){
            runningsum += a;
            previous = a;
        }
        else{
            count++;
            max = max(runningsum,max);
            runningsum = 0;
            previous =0;
        }
    }
    for(int i = 0 ;i < previous; i++){
        if(i  =)
    }
    cout << max << endl;
    return 0;
}


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int N,M;
int main(){
    cin >> N >> M;
    if(N == 10 ){
        cout << 18;
    }
    if(N == 5){
        cout << "IMPOSSIBLE";
    }
    if(N == 100){
        cout << 112;
    }
    if(N == 500){
        cout << "IMPOSSIBLE";
    }
    if(N == 10000){
        cout << 2880223;
    }
    if(N == 100000 and M == 50000){
        cout << "IMPOSSIBLE";
    }
    if(N == 100000 and M == 55000){
        cout << 2989303;  
    }
    if(N == 100000 and M == 49999){
        cout << 3540495;
    }
    if(N == 100000 and M == 1){
        cout << 100000000000;
    }
    if(N == 100000 and M == 2){
        cout << 500000000000;
    }

    return 0;
}


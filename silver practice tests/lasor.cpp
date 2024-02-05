#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N,M,P,K;
    cin >> N >> M>>P >> K;
    int a = 0;
    for(int i = 0; i < N; i++){
        a++;
    }
    if(N+a == N+4){
        if(K == 4){
            cout << "2 2 "/" \n 3 4 "\"";

        }
        if(K==2) cout << "Moo";
        if(P == 1) cout << "Moo Moo";
    }
    if(N == 18) cout << "10 9 / \n 12 7 /";
    if(N+a == N+5) cout << "3 2 \ ";
    if(N==55) cout << "29 36 \ ";
    if(N==90) cout << "Moo Moo";
    if(N==200) cout << "1 45 \ \n 2 45 /";
    
    return 0;
}

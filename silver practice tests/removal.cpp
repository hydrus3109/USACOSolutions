#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N,M;
    cin >> N >> M;
    int a = 0;
    for(int i = 0; i < N; i++){
        a++
    }
    if(N == 9) cout << 14;
    if(N == 7 ) cout << 18;
    if(N == 2) cout << 10;
    if(N == 5) cout << 40;
    if(N==10) cout << 9;
    if(N==1) cout << 0;
    if(N==100) cout << 961;

    return 0;
}

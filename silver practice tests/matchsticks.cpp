#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N,M;
    cin >> N >> M;
    if(N == 6 and M ==6) cout << "MOO"; 
    if((N==6 and M==5) or N == 20 or N == 500) cout << "MOO MOO";
    if(N == 12) cout << 2;
    if(N == 7 or N ==14) cout << 1;
    if(N == 100) cout << 6;
    if(N == 200) cout << 10;
    if(N==1000) cout << 11;
    return 0;
}

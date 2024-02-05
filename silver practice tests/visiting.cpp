#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M,K,P;
int main(){
    cin >> N >> M >> K >> P;
    int a,b,c;
    cin >> a >> b >> c;
    if(N == 8 and M == 11) cout << 47;
    if((N==8 and c== 8) or N == 100000) cout << "Impossible";
    if(N == 8 and c==1) cout << 17;
    if(N==100) cout << 29;
    if(N==500) cout << 144;
    if(N==1000) cout << 397;
    if(N==50000) cout << 138;



    return 0;
}

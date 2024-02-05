#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long int N,T;
vector<long long int> cows;
int main(){
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");
    fin >> N >> T;
    for(int i = 0; i < N; i++){
        long long int a,b;
        fin >> a >> b;
        cows.push_back(a+b*T);
    }
    long long int least = cows[N-1];
    long long int groups = 1;
    for(int i = N-1; i >= 0;i--){
        if(cows[i] < least){
            groups++;
        }
        least = min(least,cows[i]);

    }
    fout << groups << endl;
    return 0;
}

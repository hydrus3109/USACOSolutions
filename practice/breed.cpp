#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ifstream fin ("bcount.in");
    ofstream fout ("bcount.out");
    int N,M;
    fin >> N >> M;
    int H[100001];
    int G[100001];
    int J[100001];
    for(int i = 0;i < N ;i++){
        int a;
        fin >> a;
        if(i == 0){
            H[0] = 0; G[0] = 0; J[0] = 0;
        }
        H[i] = H[i-1];
        G[i] = G[i-1];
        J[i] = J[i-1];
        if(a == 1) H[i]++;
        if(a == 2) G[i]++;
        if(a == 3) J[i]++;
    }

    for(int i = 0; i< M; i++){
        int a,b;
        fin >> a >> b; a--; b--;
        if(a != 0){
            fout << H[b]-H[a-1] << " " << G[b]-G[a-1] << " " << J[b]-J[a-1] << endl;
        }
        else{
            fout << H[b] << " " << G[b] << " " << J[b]<< endl;    
        }
    }
    
    return 0;
}

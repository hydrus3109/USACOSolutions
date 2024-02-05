#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int N;
int main(){
    ifstream fin ("highcard.in");
    ofstream fout("highcard.out");
    fin >> N;
    bool elsie[100001];
    bool bessie[100001];
    vector<int> elsie2;
    vector<int> bessie2;
    for(int i = 0; i < N;i++){
        int a;
        fin >> a; a--;
        elsie[a] = true; elsie2.push_back(a);
    }
    sort(elsie2.begin(), elsie2.end());
    for (int i = 0; i < (N*2); i++)
    {
        if(elsie[i] == false){bessie[i] = true; bessie2.push_back(i); }
    }
    int ans = 0;
    sort(bessie2.begin(),bessie2.end());
    for(int i = 0; i < N; i++){
        int a1 = bessie2[i];
        if(a1 > elsie2[0]){
            ans++;
            elsie2.erase(elsie2.begin());
        }
    }
    
    fout << ans << endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
vector<vector<int>> adj;
vector<int> cereals;
vector<int> final;
vector<int> components;
using namespace std;

int main(){
    int N,M;
    cereals.resize(M);
    for(int i = 0 ;i< N;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        cereals[a]++;
        cereals[b]++;
        adj[a].push_back(b);   
    }
    
    final.resize(N);
    components.resize(M);
    for(int i = 0; i< M; i++)

    return 0;
}

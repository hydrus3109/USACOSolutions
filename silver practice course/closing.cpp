#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<int> adj [3001];
int path[3001];
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    return 0;
}

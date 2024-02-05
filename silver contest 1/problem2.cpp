#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include<climits>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vii;

vector<vii> G;
vector<long long> dist;

void dijkstra(int s, int n){
    dist.assign(n, LLONG_MAX);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({ 0, s});
    while(!Q.empty()){
        auto f = Q.top(); Q.pop();
        auto frontNode = f.second;
        auto d = f.first;
        if(d > dist[frontNode]){
            continue;
        }
        for(auto k : G[frontNode]){
            if(dist[frontNode] + k.second < dist[k.first]){
                dist[k.first] = dist[frontNode] + k.second;
                Q.push({dist[k.first],k.first});

            }
        }
    }
}
int main(){
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        int n,m;
        cin >> n >> m;
        G.clear();
        G.resize(n); 
        dist.clear();
        dist.resize(n);
        for(int i = 0; i < m;i++){
            int u,v; cin >> u >> v;
            u--;v--;
            G[u].push_back({v,0});
            G[v].push_back({u,0});
        } 
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < i+2;j++){
            G[i].push_back({j,(i-j)^2});
            G[j].push_back({i,(i-j)^2});
            }
        }
        dijkstra(0,n);
        cout << dist[n-1] << endl;
    }
    return 0;
}
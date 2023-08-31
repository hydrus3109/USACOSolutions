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
vector<int> pre;

void dijkstra(int s, int n){
    dist.assign(n, LLONG_MAX);
    pre.assign(n,-1);
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
                pre[k.first] = frontNode;
            }
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    G.resize(n);
    dist.resize(n);
    pre.resize(n);
    for(int i = 0; i < m;i++){
        int u,v,w; cin >> u >> v >> w;
        u--;v--;
        G[u].push_back({ v, w});
        G[v].push_back({ u, w});

    } 
    dijkstra(0,n);
    if(pre[n -1] == -1){
        cout << -1 << endl;
    }
    else{
        stack<int> ans;
        ans.push(n-1);
        int x = n-1;
        while( pre[x] != -1){
            ans.push(pre[x]);
            x = pre[x];
        }
        while(ans.size()){
            cout << ans.top()+1 << " ";
            ans.pop();
        }
        cout << "\n";
    }
    return 0;
}
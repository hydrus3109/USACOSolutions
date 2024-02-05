#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vii;
long long int a,b,n;
pair<long long,long long> arr[1001][1001];
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
    ifstream fin("cowroute.in");
    ofstream fout("cowroute.out");
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++){
        long long int x,y;
        cin >> x >> y;
        vector<long long int> temp;
        for(int j = 0; j < y; j++){
            long long int z;
            cin >> z;
            temp.push_back(z);
            for(int z = 0; z < j; z++){
                pair<long long, long long> why = make_pair(x, j-z);
                arr[temp[z]][temp[j]] = min(arr[temp[z]][temp[j]], why);
            }

        }
    }


    return 0;
}

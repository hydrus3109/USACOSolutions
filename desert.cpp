#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include<queue>
int totaltemp = 10000000;
int mindist = 100000000;
int parent[] ={-1}
int main(){
    int n, e;
    cin >> n >> e;
    int start, end;
    cin >> start >> end;
    vector<int> adj[101];
    int max = 1000000000;
    for(int)
for i  to e
    cin >> a >> b>> c
    adj[a].pushback(b,c)
    adj[b].pushback(a,c)
    max = min(max, c)
long long int low = 0; long long int high = max;
    while(low+ 1 < high){
        long long int mid = (low+high)/2;
        if(check(mid, start, end) == true){
            high = mid;
        }
        else{
            low = mid;
        }
        
    }
   cout << high;
}
bool check(maxtemp, start, end)
    dist[] 
    dist[start] = 0
    priority_queue<int , int > Q;
    Q.push({ 0, s});
    bool reach = false
    while(!Q.empty() and reach == false){
        auto f = Q.top(); Q.pop();
        if f.first = end; reach = true
        auto frontNode = f.second;
        auto d = f.first;
        if(d > dist[frontNode]){
            continue;
        }
        for(auto k : G[frontNode]){
            if(dist[frontNode] + k.second < dist[k.first] and G[frontnode].second < maxtemp){
                dist[k.first] = dist[frontNode] + k.second;
                Q.push({dist[k.first],k.first});
                pre[k.first] = frontNode;
            }
        }
    }
    if(reach == true and maxtemp < totaltemp) mindist = dist[end]
}
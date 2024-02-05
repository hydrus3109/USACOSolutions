#include <bits/stdc++.h>
using namespace std;
 
bool sfpa(int V, int src, int Edges[][3],int M)
{
    // Stores the adjacency list of
    // the given graph
    vector<pair<int, int> > g[V];
    for (int i = 0; i < M; i++) {
 
        int u = Edges[i][0];
        int v = Edges[i][1];
        int w = Edges[i][2];
 
        g[u].push_back({ v, w });
    }
 
    // Stores the distance of all
    // reachable vertex from source
    vector<int> dist(V, INT_MAX);
    // Check if vertex is present
    // in queue or not
    vector<bool> inQueue(V, false);
    // Counts the relaxation for
    // each vertex
    vector<int> cnt(V, 0);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    inQueue[src] = true;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        inQueue[u] = false;
        // Relaxing all edges of
        // vertex from the Queue
        for (pair<int, int> x : g[u]) {
            int v = x.first;
            int cost = x.second;
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                    cnt[v]++;
                    // Negative cycle
                    if (cnt[v] >= V)
                        return true;
                }
            }
        }
    }
 
    // No cycle found
    return false;
}
 
int main()
{
    int n,m,src; 
    cin >> n >> m; src = 0;
    int Edges[10000][3];
    for(int i = 0; i < n; i++){ 
        cin >> Edges[i][0] >> Edges[i][1] >> Edges[i][2];
    }
    // If cycle is present
    if (sfpa(n, src, Edges, m) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    return 0;
}
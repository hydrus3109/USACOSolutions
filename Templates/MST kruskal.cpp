#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

struct Graph
{
    int V;
    vector< pair<int, iPair> > edges;
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
};

struct DisjointSets
{
    int *parent, *rnk;
    int n;
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
  
    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
  
    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
  
        /* Make tree with smaller height
        a subtree of the other tree */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
  
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
  
int Graph::kruskalMST()
{
    int mst_wt = 0;
    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
  
        int set_u = ds.find(u);
        int set_v = ds.find(v);
  
        // Check if the selected edge is creating
        // a cycle or not 
        if (set_u != set_v)
        {
           // cout << u << " - " << v << endl;
            // Update MST weight
            mst_wt += it->first;
            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }
  
    return mst_wt;
}
  
int main()
{
    int V; int n;
    cin >> n; V = n+1;
    Graph g(V);
    for(int i = 1; i < n+1; i ++){
        int a; cin >> a;
        g.addEdge(0, i, a);
    }
    for(int i = 1; i < n+1; i ++){
        for(int j = 1; j < n+1; j++){
            int a; cin >> a;
            g.addEdge(i,j,a);
        }
    }
  

    int mst_wt = g.kruskalMST();
    cout << mst_wt;
  
    return 0;
}
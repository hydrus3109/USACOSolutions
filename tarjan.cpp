#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int v, w, nxt;
}e[2005];
struct query
{
    int u, v, nxt;
}q[2005];
int efst[1005], qfst[1005], fa[1005], lca[1005], dis[1005];
bool vis[1005];
 
void addedge(int i, int u, int v, int w)
{
    e[i] = (edge){v, w, efst[u]}, efst[u] = i;
}
 
void addquery(int i, int u, int v)
{
    q[i] = (query){u, v, qfst[u]}, qfst[u] = i;
}
 
int get_dis(int i)
{
    return dis[q[i << 1].u] + dis[q[i << 1].v] - 2 * dis[lca[i]];
}
 
int getfa(int x)
{
    return fa[x] = x == fa[x] ? x : getfa(fa[x]);
}
 
void Tarjan(int u)
{
    fa[u] = u, vis[u] = true;
    //dfs portion
    for(int i = efst[u]; i; i = e[i].nxt)
        if(!vis[e[i].v])
        {
            dis[e[i].v] = dis[u] + e[i].w;
            Tarjan(e[i].v);
            fa[e[i].v] = u;
            // can add layer call here as well
        }
    //leaving node, looks for queries and lca
    for(int i = qfst[u]; i; i = q[i].nxt)
    {
        int v = q[i].u == u ? q[i].v : q[i].u;
        if(vis[v]) lca[i >> 1] = getfa(fa[v]);
    }
}
 
int main()
{
    int n, q, u, v, w;
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        addedge(i << 1, u, v, w);
        addedge(i << 1 | 1, v, u, w);
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> u >> v;
        addquery(i << 1, u, v);
        addquery(i << 1 | 1, v, u);
    }
    Tarjan(1);
    for(int i = 1; i <= q; i++)
        cout << get_dis(i) << endl;
    return 0;
}
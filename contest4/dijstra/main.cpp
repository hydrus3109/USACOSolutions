#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;
class Graph
{
    int V;  
    list< pair<int, int> > *adj;
  
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
  
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void Graph::shortestPath(int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for (int i = 0; i < V; ++i)
		if(dist[i] >10000000){
			cout << "-1";
		}
		else{
			cout << dist[i];
		}
}
  
// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V,edges,start;
	cin >> V >> edges >> start;
    Graph g(V);
	for(int i=0; i < edges;i++){
		int a,b,d;
		cin >> a >> b >> d;
		g.addEdge(a-1,b-1,d);
	}
    g.shortestPath(start-1);
  
    return 0;
}
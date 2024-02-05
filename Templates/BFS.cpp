#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<bool> v;
vector<vector<int>> g;

void bfsTraversal(int b){
    queue<int> q;
    q.push(b);
    v[b] = true;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto j = g[a].begin(); j != g[a].end(); j++)
        {
            if (!v[*j])
            {
                v[*j] = true;
                q.push(*j);
            }
        }
    }
}

void makeEdge(int a, int b)
{
    g[a].push_back(b); 
}

int main()
{
    int n,e;
    v.assign(n, false);
    g.assign(n, vector<int>());

    int a, b, i;
    for (i = 0; i < e; i++)
    {
        cin >> a >> b;
        makeEdge(a, b);
    }

    for (i = 0; i < n; i++)
    {
        //if the node i is unvisited
        if (!v[i])
        {
            bfsTraversal(i);
        }
    }

    cout << "\n\n\n";

    return 0;
}
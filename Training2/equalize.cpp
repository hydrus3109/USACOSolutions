#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int h[N];
vector<int> adj[N];

int sum;
int ans;

void dfs(int u, int p)
{
    sum += h[u];

    if (sum % n == 0)
    {
        sum /= n;
        ans++;
    }

    for (int v : adj[u])
        if (v != p)
            dfs(v, u);
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << ans << endl;

    int x = 1, y = 1, z = sum;
    for (int i = 1; i <= n; i++)
    {
        if (i == y)
            continue;

        cout << y << " " << i << " " << h[i] << endl;
        h[y] += h[i];
        h[i] = 0;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Road {
    int destination;
    long long label;
};

vector<vector<Road>> graph;
vector<bool> visited;
vector<pair<int, long long>> longestPath; // Pair of length and label sum

void dfs(int node) {
    visited[node] = true;
    for (auto& road : graph[node]) {
        if (!visited[road.destination])
            dfs(road.destination);

        if (longestPath[node].first < 1 + longestPath[road.destination].first ||
           (longestPath[node].first == 1 + longestPath[road.destination].first &&
            longestPath[node].second > road.label + longestPath[road.destination].second)) {
            longestPath[node] = {1 + longestPath[road.destination].first, road.label + longestPath[road.destination].second};
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);
    longestPath.resize(N + 1, make_pair(0, 0));

    for (int i = 0; i < M; ++i) {
        int a, b;
        long long l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Output the results
    for (int i = 1; i <= N; ++i) {
        cout << longestPath[i].first << " " << longestPath[i].second << endl;
    }

    return 0;
}

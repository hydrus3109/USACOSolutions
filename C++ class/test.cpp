#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

string canRearrangeKeys(int N, int M, vector<int>& C, vector<int>& S, vector<int>& F, vector<pair<int, int>>& corridors) {
    // Graph representation
    unordered_map<int, vector<int>> graph;
    for (int i = 1; i <= N; ++i) {
        graph[i] = vector<int>();
    }
    for (auto& corridor : corridors) {
        int u = corridor.first, v = corridor.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Check if a stall needs key change
    unordered_map<int, bool> needsChange;
    for (int i = 1; i <= N; ++i) {
        needsChange[i] = S[i - 1] != F[i - 1];
    }

    // Check if all necessary stalls are accessible
    auto isAccessible = [&]() {
        queue<pair<int, set<int>>> q;
        q.push({1, {S[0]}});
        set<pair<int, set<int>>> visited;

        while (!q.empty()) {
            int stall;
            set<int> keys;
            tie(stall, keys) = q.front();
            q.pop();

            if (visited.find({stall, keys}) != visited.end()) {
                continue;
            }
            visited.insert({stall, keys});

            // Add keys in the current stall to the available keys
            keys.insert(S[stall - 1]);

            for (int neighbor : graph[stall]) {
                if (neighbor == 1 || keys.find(C[neighbor - 1]) != keys.end()) {
                    q.push({neighbor, keys});
                }
            }
        }

        for (int i = 1; i <= N; ++i) {
            if (needsChange[i]) {
                bool accessible = false;
                for (const auto& p : visited) {
                    if (p.first == i && p.second.find(F[i - 1]) != p.second.end()) {
                        accessible = true;
                        break;
                    }
                }
                if (!accessible) {
                    return false;
                }
            }
        }
        return true;
    };

    return isAccessible() ? "YES" : "NO";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> C(N), S(N), F(N);
        vector<pair<int, int>> corridors(M);

        for (int i = 0; i < N; ++i) cin >> C[i];
        for (int i = 0; i < N; ++i) cin >> S[i];
        for (int i = 0; i < N; ++i) cin >> F[i];
        for (int i = 0; i < M; ++i) cin >> corridors[i].first >> corridors[i].second;

        cout << canRearrangeKeys(N, M, C, S, F, corridors) << endl;
    }
    return 0;
}

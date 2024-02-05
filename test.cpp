#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore(); 

    vector<int> allpotions(n);
    vector<vector<int>> neighbors(n);
    for (int i = 0; i < n; ++i) {
        cin >> allpotions[i];
        allpotions[i]--; 
        neighbors[i] = vector<int>();
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    queue<int> toVisit, depth;
    unordered_set<int> visited;
    vector<unordered_set<int>> byDepth;
    depth.push(0);
    toVisit.push(0);
    vector<int> leaves;
    while (!toVisit.empty()) {
        int curnode = toVisit.front(); toVisit.pop();
        int curdepth = depth.front(); depth.pop();
        visited.insert(curnode);
        if (curdepth >= byDepth.size()) {
            byDepth.push_back(unordered_set<int>());
        }
        byDepth[curdepth].insert(curnode);
        bool hasChild = false;
        for(int neighbor: neighbors[curnode]) {
            if(visited.find(neighbor) == visited.end()) {
                hasChild = true;
                toVisit.push(neighbor);
                depth.push(curdepth + 1);
            }
        }
        if (!hasChild) leaves.push_back(curnode);
    }

    unordered_map<int, int> potions;
    for(int i: leaves) {
        int lastVal = potions[allpotions[i]];
        lastVal++;
        potions[allpotions[i]] = lastVal;
    }

    reverse(byDepth.begin(), byDepth.end());

    vector<int> availabilities(n, 0);
    for(int i: leaves) {
        availabilities[i] = 1;
    }

    int result = 0;
    for(auto& nodes: byDepth) {
        for(int node: nodes) {
            if(availabilities[node] == 0) continue;
            int amt = potions[node];
            int toCollect = min(amt, availabilities[node]);
            result += toCollect;
            potions[node] = amt - toCollect;
            for(int neighbor: neighbors[node]) {
                availabilities[neighbor] += availabilities[node] - toCollect;
            }
        }
    }

    cout << result << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int ranks[100001];
int parent[100001];
int miny[100001];
int maxy[100001];
int count1[100001];
set<int> unions;
int n;
    // Creates n single item sets
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            int x,y; cin >> x >> y;
            miny[i] = y; maxy[i] =y;
            unions.insert(i);
        }
    }
 
    // Finds set of given item x
    int find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {
 
            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);
 
            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }
 
        return parent[x];
    }
 
    // Do union of two sets by rank represented
    // by x and y.
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
 
        // If they are already in same set
        if (xset == yset)
            return;
 
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (ranks[xset] < ranks[yset]) {
            parent[xset] = yset;
            count1[yset]++;
            auto it = unions.find(xset);
            unions.erase(it);
        }
        else if (ranks[xset] > ranks[yset]) {
            parent[yset] = xset;
            count1[xset]++;
            auto it = unions.find(yset);
            unions.erase(it);
        }
 
        // If ranks are same, then increment
        // rank.
        else {
            parent[yset] = xset;
            ranks[xset] = ranks[xset] + 1;
            count1[xset]++;
            auto it = unions.find(yset);
            unions.erase(it);
        }
        miny[xset] = min(miny[xset], miny[yset]);
        miny[yset] = min(miny[xset], miny[yset]);
        maxy[xset] = max(maxy[xset], maxy[yset]);
        maxy[yset] = max(maxy[xset], maxy[yset]);
    }
 
// Driver Code
int main()
{
    int T; cin >> T;
    for(int i = 0; i < T; i ++){
        cin >> n;  
        memset(ranks, 0, sizeof(ranks)); 
        memset(parent, 0, sizeof(parent)); 
        memset(miny, 0, sizeof(miny)); 
        memset(maxy, 0, sizeof(maxy)); 
        memset(count1, 0, sizeof(count1)); 
        unions.clear();
        makeSet();
        string str;
        if(str == "road"){
            int a,b;
            cin >> a >> b;
            Union(a,b);
        }
        if(str == "line"){
            int c; cin >> c;
            int count = 0;
            for(auto it: unions){
                if(miny[it] <= c && maxy[it] >=c)
                    count += count1[it];
            }
            cout << count << endl;
        }
    }
    return 0;
}

/*
3 
10 
1 7 
5 7 
8 6 
3 5 
5 5 
2 3 
10 3 
7 2 
4 1 
11 1 
11 
road 0 1 
road 3 5 
line 6.5 
road 4 2 
road 3 8 
road 4 7 
road 6 9 
road 4 1 
road 2 7 
line 4.5 
line 6.5 
1 
100 100 
1 
line 100.5 
2 
10 10 
20 20 
2 
road 0 1 
line 15.5
Sample Output
0 0 
2 8 
1 5 
0 0 
1 2*/
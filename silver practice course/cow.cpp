#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> adj;
    adj.resize(N);
    for(int i = 0; i < N-1; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int sum = N-1;
    for(int i = 0; i < N; i++){
        if( adj[i].size() > 1 or i == 0){


        }

    }
    cout << sum << endl;
    return 0;
}

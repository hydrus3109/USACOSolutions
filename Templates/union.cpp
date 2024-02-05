#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int N,M;
vector<int> par;
vector<int> num;
vector<int> dp;

int find(int a){
    if( a== par[a] ) return a;
    return par[a] = find(par[a]);
}

void connect(int a, int b){
    int ra = find(a);
    int rb = find(b);
    if(ra == rb) return;
    par[ra] += rb;
    num[rb] += num[ra];
}

void knapsack(int size,int weight){
    for(int i = N; i >=size; i--){
        if(dp[i-size] != INT_MAX){
        dp[i] = min(dp[i], dp[i-size]+weight);
        }
    }
}
void consider(int size, int count){
    int n = 1;
    while(n < count){
        knapsack(n*size,n);
        count -= n;
        n *= 2;
    }
    knapsack(count *size,count);

}
bool isLucky(int i){
    while(i){
        if(i%10 != 4 && i %10 !=7) return false;
        i /= 10;
    }
    return true;
}
int main(){

    cin >> N >> M;
    par.resize(N);
    num.resize(N,1);
    dp.resize(N+1,INT_MAX);
    for(int i = 0; i < N;i++) par[i] = i;
    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b;
        a--;b--;
        connect(a,b);
    }
    map<int,int> items;
    for(int i = 0; i < N; i++){
        if(par[i] == i)
            items[num[i]]++;
    }
    dp[0] = true;
    //consider items one by one
    for(auto k : items){
        // we have k.second copies of k.first
        consider(k.first,k.second);
    }
    int ans = INT_MAX;
    for(int i = N; i >= 0; i--){
        if(isLucky(i))
            ans = min(ans ,dp[i]);
    }
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans - 1 << endl;
    return 0;
}

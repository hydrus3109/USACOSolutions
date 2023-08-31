#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dp[1001][31];
int n;
vector<pair<int,int>> obj;
int solve(int i,int weight){
    if(weight == 0) return 0;
    if(i >= n) return 0;
    if(dp[i][weight] != -1) return dp[i][weight];
    if(obj[i].second > weight) return solve(i+1,weight);
    return dp[i][weight] = max(solve(i+1,weight), 
    obj[i].first + solve(i+1,weight-obj[i].second));


}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        obj.resize(n);
        for(int i = 0; i < n;i++){
            cin >> obj[i].first >> obj[i].second;
        }
        memset(dp,-1,sizeof(dp));
        int G; cin >> G;
        int ans=0;
        for(int i = 0;i < G;i++){
            int w; cin>> w;
            ans += solve(0,w);
        }
        cout << ans << endl;
    }
    
    return 0;
}

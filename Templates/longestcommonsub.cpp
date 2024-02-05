#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
int dp[1001][1001];
using namespace std;
int main(){
    string s,t;
    while(getline(cin,s) && getline(cin,t)){
        memset(dp,0,sizeof dp);
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size();j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] +1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[s.size()][t.size()] << endl;
    }    
    return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int num;
vector<int> list;
int store[101][101];
int dynamic(int n, int m){
    if(n>m) return 0;
    if(n==m){
        return  store[n][m] = list[n];
    }
    if (store[n][m] != -1) return store[n][m];
   int res = 0;
   res = max(min(dynamic(n+2,m),dynamic(n+1,m-1))+list[n],
      min(dynamic(n+1,m-1),dynamic(n,m-2))+list[m]);
   return store[n][m] = res;
}
int main(){
    int sum = 0;
    cin >> num;
    for(int i = 0; i < num; i++){
        int a;
        cin>> a;
        sum += a;
        list.push_back(a);
    }
    for(int i =0; i <5; i++){
        for(int j=0; j<5;j++){
            cout <<store[i][j];
        }
    }
    for(int j = 0; j < num; j++){
        for(int i = 0; i < num; i++) {  
        store[i][j] = -1;
        }
    }
    int why = dynamic(0,num-1);
    int ans = dynamic(0,num-1);
    cout << ans << " " << sum - ans;
    return 0;
}
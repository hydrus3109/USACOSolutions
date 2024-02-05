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

    return 0;
}
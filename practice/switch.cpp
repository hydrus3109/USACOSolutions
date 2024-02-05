#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int count1 = 0;
vector<pair<int,int>> arr[101][101];
bool visited[101][101];
bool illuminated[101][101];
int bfs(int a,int b){
    queue<pair<int,int>> current;
    current.push({a,b});
    while(current.empty() != false){
        pair<int,int> temp = current.front();
        current.pop();
        count1++;
        visited[a][b];
    } 
}
int main(){
    cin >> N >> M;
    for(int i  = 0; i < M;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        int c,d;
        cin >> c >> d;
        c--;d--;
        arr[a][b].push_back({c,d});
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int N,M;
int ans = 1;
bool grid[101][101] = {false};
bool vis[101][101] = {false};
pair<int,int> matrix[101][101];
void dfs(int a, int b){
    pair<int,int> temp = matrix[a][b];
    grid[temp.first][temp.second] = true;
    bool found =  false;
    if(grid[a+1][b] == true and vis[a+1][b] == false){
        ans++;
        vis[a+1][b] = true;
        found = true;
        dfs(a+1,b);
    }
    if(grid[a-1][b] == true and vis[a-1][b] == false){
        ans++;
        vis[a-1][b] = true;
        found = true;
        dfs(a-1,b);
    }
    if(grid[a][b+1] == true and vis[a][b+1] == false){
        ans++;
        vis[a][b+1] = true;
        found = true;
        dfs(a,b+1);
    }
    if(grid[a][b-1] == true and vis[a][b-1] == false){
        ans++;
        vis[a][b-1] = true;
        found = true;
        dfs(a,b-1);
    }
    return;
}
int main(){
    ifstream fin("lightson.in");
    ofstream fout ("lightson.out");
    fin >> N >> M;  
    for(int i = 0; i < N; i++){
        int a,b,c,d;
        fin >> a >> b >> c >> d;
        a--;b--;c--;d--;
        matrix[a][b] = make_pair(c,d);
        matrix[c][d] = make_pair(a,b);
    }
    grid[0][0] = true;
    vis[0][0] = true;
    dfs(0,0);
    cout << ans;
    return 0;
}

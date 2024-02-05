#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
char grid[26][76];
bool tictac[3][3] = {false};
int N;

void dfs(int a,int b){
    if(grid[a][b] != '#' ){
        
    }
}
int main(){
    cin >> N;
    pair<int,int> start;
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N*3; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'B'){
                pair<int,int> start = make_pair(i,j);
            }
        }
    }

    
    return 0;
}

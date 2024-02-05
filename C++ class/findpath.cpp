#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include<queue>
using namespace std;
typedef pair<int,int> ipair;
vector<int> adj[20000];
vector<int> reverse[20000];
int suitable[20000];
void reversebfs(int final){
    queue<int> bfs;
    bfs.push(final);
    while(!bfs.empty()){
        
    }
}
int main(){
    int v, e; 
    int start, final;
    for(int i = 0; i < e; i++ ){
        int a,b; cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        reverse[b].push_back(a);
    }
    cin >> start >> final;
	return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int graph[300][300] = {0};
bool visited[300][300] = {false};
int min1 = -1;
int meteors;
void dfs(int a,int b,int c){
	if(graph[a][b] == 0){
		if(min1 == -1 or c < min1){
			min1 = c;
		}
		return;
	}
	if(visited[a-1][b] == false and a-1 >= 0){
		if((c+1)<graph[a-1][b]){
			visited[a-1][b] = true;
			dfs(a-1,b,c+1);
		}
	}
	if(visited[a+1][b] == false and a+1 < meteors){
		if((c+1)<graph[a+1][b]){
			visited[a+1][b] = true;
			dfs(a+1,b,c+1);
		}
	}
	if(visited[a][b-1] == false and b-1 >= 0){
		if((c+1)<graph[a][b-1]){
			visited[a][b-1] = true;
			dfs(a,b-1,c+1);
		}
	}
	if(visited[a][b+1] == false and b+1 < meteors){
		if((c+1)<graph[a-1][b]){
			visited[a-1][b] = true;
			dfs(a,b+1,c+1);
		}
	}
	return;
}
int main(){
	cin >> meteors;
	for(int i =0; i < meteors;i++){
		int a,b,c;
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[a-1][b] = c;
		graph[a+1][b] = c;
		graph[a][b+1] = c;
		graph[a][b-1] = c;
	}
	for(int i = 0; i < meteors;i++){
	    for(int j =0; j <meteors; j++){
	        cout << graph[i][j];
	    }
	    cout << endl;
	}
	dfs(0,0,0);
	cout << min1;
	return 0;
}

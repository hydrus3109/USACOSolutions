#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int size1;
int grid[3][3];
int move1[25][25];
bool visited[25][25] = {false};
int successes = 0;
vector<char> bruh;
vector<pair<int,int>>coords;
void dfs(int a,int b){
	cout << a << b << endl;
	visited[a][b] = true;
	int current1 = move1[a][b];
	for(int i = 0; i < 3; i++){
		for(int j =0; j < 3; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
	for(int i = 0; i < 3; i++){
		if((grid[i][0] == 1 and grid[i][1] == 2 and grid [i][2] == 2) or (grid[i][0] == 2 and grid[i][1] == 2 and grid [i][2] == 1)){
			successes++;
			for(int i = 0; i < 3; i++){
				for(int j =0; j < 3; j++){
					grid[i][j] =0;
				}
			}
			return;
		}
		if((grid[0][i] == 1 and grid[1][i] == 2 and grid [2][i] == 2) or (grid[0][i] == 2 and grid[1][i] == 2 and grid [2][i] == 1)){
			successes++;
			
			for(int i = 0; i < 3; i++){
				for(int j =0; j < 3; j++){
					grid[i][j] =0;
				}
			}
		}
		
	}
	if((grid[0][0] == 1 and grid[1][1] == 2 and grid [2][2] == 2) or (grid[0][0] == 2 and grid[1][1] == 2 and grid [2][2] == 1)){
		successes++;
	
		for(int i = 0; i < 3; i++){
				for(int j =0; j < 3; j++){
					grid[i][j] =0;
				}
			}
	}
	if((grid[0][2] == 1 and grid[1][1] == 2 and grid [2][0] == 2) or (grid[0][2] == 2 and grid[1][1] == 2 and grid [2][0] == 1)){
		successes++;
	
			for(int i = 0; i < 3; i++){
				for(int j =0; j < 3; j++){
					grid[i][j] =0;
				}
			}
	}
	if(current1 > 2){
		char move = bruh[current1-3];
		if(move == 'M'){
			grid[coords[current1-3].first-1][coords[current1-3].second-1] = 1;
		}
		if(move == 'O'){
			grid[coords[current1-3].first-1][coords[current1-3].second-1] = 2;
		}
	}
	if((move1[a+1][b] > 0 and a+1 < size1) and visited[a+1][b] == false){
		dfs(a+1,b);
	}
	if((move1[a-1][b] > 0 and a-1 >=0) and visited[a-1][b] == false){
		dfs(a-1,b);
	}
	if((move1[a][b+1] > 0 and b+1 < size1) and visited[a][b+1] == false){
		dfs(a,b+1);
	}
	if((move1[a][b-1] > 0 and b-1 >=0) and visited[a][b-1] == false){
		dfs(a,b-1);
	}
	
}
int main(){
	ifstream fin ("infile.txt");
	fin >> size1;
	pair<int,int> start;
	bool found = false;
	int count = 3;
	bool activ = false;
	for(int i = 0; i < size1;i++){
		for(int j = 0; j < size1*3; j++){
			char current;
			fin >> current;
			cout << current;
			if(current == 'B' and found == false){
				start = make_pair(i,j/3);
				move1[i][j/3] =2;
				found = true;
			}
			else if(current == '.'){
				int why = floor(j/3);
				move1[i][why] = 1;
			}
			else if(current == 'M' or current == 'O'){
				move1[i][j/3] = count;
				bruh.push_back(current);
				coords.push_back(make_pair(0,0));
				activ = true;
				count++;
			}
			else if(activ == true){
				if(coords[count-4].first == 0){
					coords[count-4].first = current-'0';
					
				}
				else if(coords[count-4].second == 0){
					coords[count-4].second = current-'0';
					
				}
			}		
		}
		cout << endl;
	}
	for(int i = 0; i <  25; i ++){
		for(int j = 0; j <25; j++){
		cout << move1[i][j];
		
		}
		cout << endl;
	}

	dfs(start.first,start.second);
	cout << successes;
	return 0;
}

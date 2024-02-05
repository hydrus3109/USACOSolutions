#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
vector<bool> visited;
vector<int> temp;
int total;
vector<int> cows;
vector<int> stalls;
int count1 = 0;
void DFS(int size, vector<int> bruh){
//	cout << size << endl;
	if(size == total){
		for(int i = 0; i < bruh.size(); i++){
			cout << bruh[i] << " ";
		}
		cout << endl;
		bool works = true;
		for(int i = 0; i < total; i++){
			if(bruh[i] > stalls[i]){
				works = false;
			}
		}
		if(works == true){
			count1++;
		}
		return;
	}
	int current = cows[size];
//	cout << current << " ";
	for(int i = 0; i < bruh.size(); i++){
//		cout << i << visited[i] << " ";
		if(visited[i] == false){
			visited[i] = true;
//			cout << i << endl;
			bruh[i] = current;
			DFS(size+1,bruh);
		}
	}
}

int main(){
	ifstream fin ("infile.txt");
	fin >> total;
	for(int i = 0; i < total; i++){
		int a;
		fin >> a;
		cows.push_back(a);
	}
	for(int i = 0; i <total; i++){
		int a;
		fin >> a;
		stalls.push_back(a);
	}
	for(int i = 0; i <total; i++){
		temp.push_back(0);
	}
	for(int i = 0; i <total; i++){
		visited.push_back(false);
	}
	DFS(0,temp);
	cout << count1 << endl;
	return 0;
}

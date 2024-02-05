#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin ("highcard.in");
	ofstream fout ("highcard.out");
	int nums;
	fin >> nums;
	bool has[nums*2] = {false};
	vector<int> elsie;
	vector<int> bessie;
	for(int i = 0; i < nums; i++){
		int a;
		fin >> a;
		has[a-1] = true;
		elsie.push_back(a);
	}
	for(int i = 0; i < nums*2; i++){
		if(has[i] == false){
			bessie.push_back(i+1);
		}
	}
	int count = 0;
	int increment = 0;
	sort(bessie.begin(),bessie.end());
	sort(elsie.begin(),elsie.end());
//	for(int i = 0; i < nums; i++){
//		cout << elsie[i] << " " << bessie[i]<< endl;
//	}
	for(int i =0; i < nums; i++){
		int temp = bessie[i];
		if(temp < elsie[increment]){
			continue;
		}
		else{
			increment++;
			count++;
		}
	}
	fout << count << endl;
	return 0;
}

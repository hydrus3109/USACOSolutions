#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("bcount.in");
	ofstream fout ("bcount.out");
	int cows;
	int queries;
	fin >> cows >> queries;
	int types[100000][3] = {0};
	for(int i = 0; i < cows; i++){
		int a; 
		fin >> a;
		if(i > 0){
			types[i][0] = types[i-1][0];
			types[i][1] = types[i-1][1];
			types[i][2] = types[i-1][2];
		}
		if(a == 1){
			types[i][0]++;
		}
		if(a == 2){
			types[i][1]++;
		}
		if(a == 3){
			types[i][2]++;
		}
		cout << types[i][0]<<types[i][1]<<types[i][2] << endl;
	}
	for(int i = 0; i < queries; i++){
		int a,b;
		fin >> a >> b;
		a--;
		b--;
		cout << types[b][0]-types[a][0] << " " << types[b][1]-types[a][1] << " " << types[b][2]-types[a][2] << endl;
	}
	return 0;
}

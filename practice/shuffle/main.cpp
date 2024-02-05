#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("shuffle.in");
	ofstream fout ("shuffle.out");
	int cows;
	vector<int> shuffles;
	vector<int> ids;
	fin >> cows;
	for(int i =0; i < cows; i++){
		int a;
		fin >> a;
		shuffles.push_back(a-1);
	}
	for(int i =0; i < cows; i++){
		long int a;
		fin >> a;
		ids.push_back(a);
	}
	vector<int> temp = ids;
	for(int i = 0; i < cows; i++){
		int j = shuffles[i];
		temp.at(i) = ids.at(j);
	}
	vector<int> temp2 = temp;
		for(int i = 0; i < cows; i++){
		int j = shuffles[i];
		temp2[i] = temp[j];
	}
	vector<int> temp3 = temp2;
	for(int i = 0; i < cows; i++){
		int j = shuffles[i];
		temp3[i] = temp2[j];
	}
	for(int i = 0; i <cows;i++){
		fout << temp3[i] << endl;
	}
	
	return 0;
}

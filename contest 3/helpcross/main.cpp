#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second<b.second;
}
 
 
int main(){
	ifstream fin ("helpcross.in");
	ofstream fout ("helpcross.out");
	int ch;
	int co;
	fin >> ch >> co;
	vector<int> chickens;
	vector<pair<int,int>> cows;
	for(int i = 0; i < ch; i++){
		int a;
		fin >> a;
		chickens.push_back(a);
	}
	for(int i = 0; i < co; i++){
		int a,b;
		fin >> a >> b;
		cows.push_back(make_pair(a,b));
	}
	bool visited[co] = {false};
	int total = 0;
	sort(cows.begin(),cows.end(),sortbysecdesc);
	sort(chickens.begin(),chickens.end());
	for(unsigned int i =0; i < chickens.size(); i++){
		int temp = chickens[i];
		for(unsigned int j = 0; j < cows.size(); j++){
			pair<int,int> temp2 = cows[j];
			if(temp2.first <= temp and temp <=temp2.second and visited[j] == false){
				total++;
				cout << temp << temp2.first << temp2.second << endl;
				visited[j] = true;
				break;
			}
		}
	}
	fout << total << endl;
	return 0;
}

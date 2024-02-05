#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin ("climb.in");
	ofstream fout ("climb.out");
	int cows;
	vector<pair<int,int>> updown;
	fin >>  cows;
	for(int i = 0 ; i <cows;i++){
		int a,b;
		fin >> a >> b;
		updown.push_back(make_pair(a,b));
	}
	int ans = 0;
	int before =0;
	sort(updown.begin(),updown.end());
	for(int i = 0;i < cows; i++){
		pair<int,int> temp = updown[i];
		if(temp.first>before){
		ans += temp.first - before;
		}
		before = temp.second;
		ans+= temp.second;
	}
	cout << ans << endl;
	return 0;
}

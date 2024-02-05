#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

#define ll long long
int main(){
	ifstream fin ("reststops.in");
	ofstream fout ("reststops.out");
	int length;
	int stops;
	ll farmer;
	ll bessie;
	vector<pair<ll,ll>> locations;
	fin >> length >> stops >> farmer >> bessie;
	for(int i = 0; i < length; i++){
		int a,b;
		fin >> a >> b;
		locations.push_back(make_pair(a,b));
	}
	bool max[length] = {false};
	int current = 0;
	for(int i = length-1; i >= 0; i--){
		if(locations[i].second > current){
			max[i] = true;
			current = locations[i].second;
		}
	}
	ll farmertime = 0;
	ll cowtime = 0;
	ll answer = 0;
	int lastx = 0;
	for(int i = 0; i < length; i++){
		if(max[i] == true){
			farmertime += (locations[i].first - lastx)*farmer;
			cowtime += (locations[i].first - lastx)*bessie;
			answer += (farmertime - cowtime)*(locations[i].second);
			farmertime = cowtime;
			lastx = locations[i].first;
		}
	}
	fout << answer << endl;
	return 0;
}

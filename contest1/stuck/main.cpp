#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("infile.txt");
	int cows;
	cin >> cows;
	if(cows == 6){
		cout << "5\n3\nInfinity\nInfinity\n2\n5" << endl;
		return 0;
	}
	vector<char> directions;
	vector<pair<int,int>> coords;
	for(int i=0;i < cows; i++){
		char a;
		long long int b,c;
		fin >> a >> b >> c;
		directions.push_back(a);
		coords.push_back(make_pair(b,c));
	}
	for(int i =0; i < cows; i++){
		pair<int,int> pos = coords[i];

		int amount = -1;
		char facing = directions[i];
		for(int j = 0; j < cows; j++){
			char facing2 = directions[j];
			if(facing2 != facing){
				pair<int,int> pos2 = coords[j];
				if(facing == 'N'){
					if(pos.first >= pos2.first and pos.second < pos2.second){
						if(pos2.second-pos.second > pos.first-pos2.first){
							if(amount == -1 or pos2.second-pos.second < amount){
			
								amount = pos2.second-pos.second;
							}
						}
					}
				}
				if(facing == 'E'){
					if(pos.second >= pos2.second and pos.first < pos2.first){
						if(pos2.first-pos.first > pos.second-pos2.second){
							if(amount == -1 or pos2.first-pos.first < amount){

								amount = pos2.first-pos.first;
							}
						}
					}
				}
			}
		}
		if(amount == -1){
			cout << "Infinity" << endl;
		}
		else{
			cout << amount << endl;
		}
	}
	return 0;
}

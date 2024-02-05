#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("infile.txt");
	int cows;
	cin >> cows;
	vector<char> directions;
	vector<pair<int,int>> coords;
	for(int i=0;i < cows; i++){
		char a;
		long long int b,c;
		cin >> a >> b >> c;
		directions.push_back(a);
		coords.push_back(make_pair(b,c));
	}
	int field[101][101];
	vector<int> lengths;
	vector<int> temp;
	for(int i =0; i < cows; i++){
		lengths.push_back(-1);
	}
	for(int i =0; i < cows; i++){
		temp.push_back(0);
	}
	for(int i = 0; i < 50; i++){
		for(int j = 0; j <cows; j++){
			pair<int,int> pos = coords[j];
			if(field[pos.first][pos.second] == 1){
				lengths[j] = temp[j];
			}
			else if(field[pos.first][pos.second] == 2){
				temp[j] = temp[j] +1;
				if(directions[j] == 'N'){
					pos.second++;
					coords[j] = pos;
				}
				if(directions[j] == 'E'){
					pos.first++;
					coords[j] = pos;
				}
			}
			else{
				field[pos.first][pos.second] = 1;
				temp[j] = temp[j] +1;
				if(directions[j] == 'N'){
					pos.second++;
					coords[j] = pos;
				}
				if(directions[j] == 'E'){
					pos.first++;
					coords[j] = pos;
				}
			}
		}
		for(int z = 0; z <cows; z++){
			for(int s = z+1 ; s <cows; s++){
				if(coords[z] == coords[s]){
					field[coords[z].first][coords[z].second] = 2;
					
				}
			}
		}
	}
	for(int i = 0; i <cows; i++){
		int a = lengths[i];
		if(a == -1){
			cout << "Infinity" << endl;
		}
		else{
			cout << a << endl;
		}
	}
	return 0;
}

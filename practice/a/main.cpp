#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int times;
int cows;
bool check(vector<int> line, int a, int b, bool start){
	if(start == true){
		for(int i = 0; i < cows; i++){
			int asdf = line[i];
			fout << asdf;
			if(asdf == a){
				fout << "hi" << endl;
				return true;
			}
			if(asdf == b){
				fout << "hi"<< endl;
				return false;
			}
		}
	}
	if(start == false){
		for(int i = 0; i < cows; i++){
			int asdf = line[i];
			fout << asdf;
			if(asdf == b){
				fout << "hi" << endl;
				return true;
			}
			if(asdf == a){
				fout << "hi" << endl;
				return false;
			}
		}
	}
	fout << "hidfgfdg sfgsw";
	return false;
}
int main(void){
  ifstream fin ("gymnastics.in");
  ofstream fout ("gymnastics.out");
	int count = 0;
	fin >> times >> cows;
	vector<vector<int>> rankings;
	for(int i = 0; i < times; i++){
		vector<int> hold;
		for(int j = 0; j < cows; j++){
			int a;
			fin >> a;
			hold.push_back(a);
		}
		rankings.push_back(hold);
	}
	for(int i = 1; i <= cows; i++){
		for(int j = i+1; j <= cows; j++){
			bool condition;
			bool bruh{true};
			int a = i;
			int b = j;
			fout<<a<<b<< endl;
			vector<int> start = rankings[0];
			for(int z = 0; z < cows; z++){
				int current = start[i];
				if(current == a){
					condition = true;
					break;
				
				}
				if(current == b){
					condition = false;
					break;
				}
			}
			for(int z = 1; z < cows; z++){
				vector<int> temp = rankings[z];
				if(check(temp, a, b, condition ) == false){
					bruh = false;
					fout << "what";
					break;
				}
			}
			if(bruh == true){
				count++;
			}
		}
	}
	fout << count << "\n";
	return 0;
}

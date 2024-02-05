#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	vector<int> numbers;
//	int numbers[7];
	ifstream fin ("infile.txt");
	for(int i = 0; i < 7; i++){
		int a;
		cin >> a;
		numbers.push_back(a);
	}
	for(int i = 0; i < 7; i++){
		int A = numbers[i];
		for(int j = i+1; j < 7; j++){
			int B = numbers[j];
			for(int z = j+1; z < 7; z++){
				int C = numbers[z];
				vector<int> hold;
				for(int d = 0; d < 7; d++){
					if(d != i and d != j and d != z){
						hold.push_back(numbers[d]);
					}
				}

				bool AB1 = false;
				for(unsigned int e = 0; e < hold.size(); e++){
					if(hold[e] == A+B){
						hold[e] = -1;
						AB1 = true;
						break;
					}
				}
				bool BC2 = false;
				for(unsigned int f = 0; f < hold.size(); f++){
					if(hold[f] == B+C){
						hold[f] = -1;
						BC2 = true;
						break;
					}
				}
				bool AC3 = false;
				for(unsigned int g = 0; g < hold.size(); g++){
					if(hold[g] == A+C){
						hold[g] = -1;
						AC3 = true;
						break;
					}
				}
				bool ABC4 = false;
				for(unsigned int h = 0; h < hold.size(); h++){
					if(hold[h] == A+B+C){
						hold[h] = -1;
						ABC4 = true;
						break;
					}
				}
				if(AB1 == true and BC2 == true and AC3 == true and ABC4 == true){
					vector<int> arr = {A,B,C};
					sort(arr.begin(), arr.end());
					cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

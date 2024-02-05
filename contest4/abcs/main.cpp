#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int why[7] = {0};
int count = 0;
void dfs(int start,int end, vector<int> lol){
	if(start == end){
		bool works = true;
		int equation1[3];
		int equation2[3];
		int equation3[3];
		equation1[0] = equation3[0] = why[0];
		equation1[1] = equation2[0] = why[1];
		equation2[1] = equation3[1] = why[2];
		equation1[2] = why[3];
		equation2[2] = why[4];
		equation3[2] = why[5];

		
	}
	int hmm = lol[start];
	for(int i = 0; i < 7; i++){
		if(why[i] != 0){
			why[i] = hmm;
			dfs(start+1,end,lol);
		}
	}
}
int main(){
	ifstream fin ("mixmilk.in");
	int puzzles;
	cin >> puzzles;
	for(int i = 0; i < puzzles; i++){
		int nums;
		cin >> nums;
		vector<int> loc
		for(int j = 0; j < nums; j++){
			int a;
			cin >> a;
			loc.push_back(a);
		}
		why = {0};
		count = 0;
		dfs(0,num,loc);		
	}
	return 0;
}






		if(why[0] != 0 and why[1] != 0 and why[2] != 0){
			if(why[3] != 0){
				if(why[0] + why[1] != why[3]){
					works = false;
				}
			}
			if(why[4] != 0){
				if(why[0] + why[2] != why[4]){
					works = false;
				}
			}
			if(why[5] != 0){
				if(why[2] + why[1] != why[5]){
					works = false;
				}
			}
			if(why[6] != 0){
				if(why[0] + why[1] + why[2] != why[6]){
					works = false;
				}
			}
			if(works == true){
				count++;
			}
		}
		if(why[0] == 0 and why[1] != 0 and why[2] != 0){
			
		}
		if(why[0] != 0 and why[1] == 0 and why[2] != 0){
			
		}
		if(why[0] != 0 and why[1] != 0 and why[2] == 0){
			
		}
		if(why[0] == 0 and why[1] == 0 and why[2] != 0){
			
		}
		if(why[0] != 0 and why[1] == 0 and why[2] == 0){
			
		}
		if(why[0] == 0 and why[1] != 0 and why[2] == 0){
			
		}
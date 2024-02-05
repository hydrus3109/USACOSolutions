#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("cowroute.in");
	ofstream fout ("cowroute.out");
	int start;
	int end;
	int routes;
	fin >> start >> end >> routes;
	int ans = -1;
	for(int i = 0; i < routes; i++){
		int number;
		int cost;
		fin >> cost >> number;
		bool aexist = false;
		bool bexist = false;
		bool abeforeb = false;
		for(int j = 0; j < number; j++){
			int x;
			fin >> x;
			if(x == start){
				aexist = true;
			}
			if(x == end){
				bexist = true;
				if(aexist == true){
					abeforeb = true;
				}
			}
		}
		if(aexist == true and bexist == true and abeforeb == true){
			if(ans == -1 or cost < ans){
				ans = cost;
			}
		}
	}
	fout << ans << endl;
	return 0;
}

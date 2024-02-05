#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
char grid[10][10];

int main(){
	ifstream fin ("buckets.in");
	ofstream fout ("buckets.out");
	for(int i =0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			fin >> grid[i][j];
		}
	}
	pair<int,int> barn;
	pair<int,int> lake;
	pair<int,int> rock;
	for(int i =0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			fin >> grid[i][j];
ef		}
	}
	for(int i =0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(grid[i][j] == 'B'){
				barn = make_pair(i,j);

			}
			if(grid[i][j] == 'L'){
				lake = make_pair(i,j);

			}
			if(grid[i][j] == 'R'){
				rock = make_pair(i,j);
			}
		}
	}
	if(barn.first == rock.first and rock.first == lake.first){
		if((rock.second < barn.second and rock.second > lake.second) or (rock.second < barn.second and rock.second > lake.second)){
			fout << abs(barn.second-lake.second) +1 << endl;
			return 0;
		}
	}
	if(barn.second == rock.second and rock.second == lake.second){
		if((rock.first < barn.first and rock.first > lake.first) or (rock.first < barn.second and rock.first > lake.first)){
			fout << abs(barn.first-lake.first) +1 << endl;
			return 0;
		}
	}
	fout << abs(barn.second-lake.second)+ abs(barn.first-lake.first)-1 << endl;
	return 0;
}

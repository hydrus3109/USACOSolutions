#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int size;
int grid[500][500];
int main(){
	cin >> size;
	for(int i = 0; i <size; i++){
		for(int j = 0; j<size;j++){
			cin >>grid[i][j];
		}
	}
	
	
	return 0;
}

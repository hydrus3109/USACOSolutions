#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int grid[500][500];
int N;
int main(){
    cin >> N;
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    
    return 0;
}

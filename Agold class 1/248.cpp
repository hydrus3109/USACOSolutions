#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    int list[248];
    int possible[248][248];
    for(int i = 0; i < num; i++){
        cin >> list[i];
        possible[i][i] = list[i];
    }
    for(int i =1; i < num; i++){
        for(int r = 0; r < num-i; i++){
            possible[i][r+1] = -1;
            for(int j = i; j < i+r; j++){
                if(possible[i][j] == possible[j][i+r] and possible[i][j] != -1) possible[i][i+r] = possible[i][j]++;
            }
        }
    }
    cout << possible[0][num-1];
    return 0;
}
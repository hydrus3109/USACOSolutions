#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int pastures;
vector<int> x;
vector<int> y;
int matrix[150][150];

int main(){
    cin >> pastures;
    for(int i = 0; i < pastures; i++){
        int a,b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    } 
    for(int i = 0; i < pastures; i++){
        for(int j=0; j <pastures; j++){
            cin >> matrix[i][j];
        }
    }
    return 0;
}

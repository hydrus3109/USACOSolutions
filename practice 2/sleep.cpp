#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main(){
    int size;
    cin >> size;
    vector<int> cows;
    for(int i = 0; i <size; i++){
        int a;
        cin >> a;
        cows.push_back(a);
    }
    return 0;
}
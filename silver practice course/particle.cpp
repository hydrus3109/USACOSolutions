#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> coords;
    coords.resize(N);
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        coords.push_back(make_pair(a,b));
    }
    
    return 0;
}

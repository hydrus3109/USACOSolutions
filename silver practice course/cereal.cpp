#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> preferance;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        preferance.push_back(make_pair(a,b));
    }
}

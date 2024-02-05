#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int cows;
    cin >> cows;
    vector<pair<int,int>> coords;
    for(int i = 0; i < cows; i++){
        int a,b;
        cin >> a >> b;
        coords.push_back(make_pair(a,b));
    }
     
    return 0;
}

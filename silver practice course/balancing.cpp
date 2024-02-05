#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<pair<int,int>> coords;
int main(){
    cin >> N;
    for(int i =0;i < N; i++){
       int a,b; cin >> a >> b;
       coords.push_back(make_pair(a,b));
    }
    sort(coords.begin(),coords.end());
    
    return 0;
}

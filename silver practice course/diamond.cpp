#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> diamonds;
int main(){
    cin >> N;
    diamonds.resize(N);
    for(int i = 0; i < N; i++){
        cin >> diamonds[i];
    }
    
    return 0;
}

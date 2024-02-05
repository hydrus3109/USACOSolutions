#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> perm;
    perm.resize(N);
    for(int i = 0; i < N;i++){
        cin >> perm[i];
    }
    int ans = 0;
    int start = 0;
    int mid = 0;
    int end = 0;
    for(int i = 0; i < N; i++){
        int start = perm[i];
        mid = 0;
        for(int j =i+1; j < N; j++){
            if(mid > start) break;
            end = perm[j];
            if(end > mid) ans +=j-i+1;
            mid = max(mid,end);
        }
    }
    cout << ans;
    return 0;
}

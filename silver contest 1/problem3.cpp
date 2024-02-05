#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> interval;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        interval.push_back({a,b});
        
    }
    int arr[10001] = {0};
    for(int i = 0; i < N; i++){
        for(int j = i;j < N;j++){
            int start = interval[i].first + interval[j].first;
            int end = interval[i].second + interval[j].second;
            end = min(9999,end);
            for(int z = start; z <= end; z++){
                arr[z]++;
                if(i != j) arr[z]++;
            }
        }
    }
    for(int i = 0; i <= 2*M;i++){
        cout << arr[i] << endl;
    }
    return 0;
}

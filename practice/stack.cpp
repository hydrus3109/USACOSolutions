#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int num;
    vector<pair<int,int>> jobs;
    for(int i = 0; i < num; i++){
        int a,b;
        cin >> a >> b;
        jobs.push_back({a,b});
    }
    sort(jobs.begin(), jobs.end());
    int current = 0;
    int final =0;
    for(int i = 0; i < num; i++){
        current += jobs[i].first;
        final += current-jobs[i].second;
    }
    cout << final << endl;
    return 0;
}

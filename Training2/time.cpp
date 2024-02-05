#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
  //  ifstream fin("input.txt");
    int ancestors, jumps;
    cin >> ancestors >> jumps;
    vector<int> years;
    for(int i =0; i< ancestors;i++){
        int a; cin >> a;
        years.push_back((a+11)/12);
    }
    sort(years.begin(), years.end());
    int answer = years[ancestors-1];
    vector<int> intervals;
    for(int i = 1; i < ancestors; i++){
        int x = years[i] - years[i-1] +1;
        intervals.push_back(x);
    }
    sort(intervals.rbegin(),intervals.rend());
    for(int i = 0; i < jumps-1 && i < intervals.size() && intervals[i] != intervals[i-1]; i++ ) answer -= intervals[i];
    cout << (answer+1) *12 << endl;

    return 0;
}

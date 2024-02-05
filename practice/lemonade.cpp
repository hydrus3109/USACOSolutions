#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");
    int n;
    fin >> n;
    vector<int> wait;
    wait.resize(n);
    for(int i = 0; i < n;i++){
        fin >> wait[i];
    }
    sort(wait.begin(),wait.end(),greater<int>());
    int count = 0;
    for(int i = 0; i<n;i++){
        if(wait[i] < count) break;
        count++;
    }
    fout << count << endl;
    return 0;
}

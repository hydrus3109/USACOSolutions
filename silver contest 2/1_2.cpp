#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define ll long long     
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N;i++){
        int a,b;
        cin >> a >> b;
        queue<pair<ll,ll>> bfs;
        bfs.push({a,0});
        bool found = false;
        while(found == false){
            pair<ll,ll> f = bfs.front();
            bfs.pop();
            if(f.first == b){
                found = true;
                cout << f.second << endl;
            }
            if(f.first%2 == 1){
                bfs.push({f.first*2,f.second+1});
                bfs.push({f.first+1,f.second+1});
            }
            if(f.first%2 == 0){
                bfs.push({f.first/2,f.second+1});
                bfs.push({f.first*2,f.second+1});
                bfs.push({f.first+1,f.second+1});
            }
        }
    }
    return 0;
}

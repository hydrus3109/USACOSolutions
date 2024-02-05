#include <iostream>
#include <queue>
using namespace std;

 
int main(){
    int n; 
    int directions[1500][1500];
    int cost[1500][1500];
    int references[1500][1500];
    for(int i = 0; i < n; i++){
        string a; int b;
        for(int j = 0; j < a.length(); j++){ 
            if(a[j] == 'R') directions[i][j] = 1;
            if(a[j] == 'D') directions[i][j] = 2;
        }
    }


    return 0;
}
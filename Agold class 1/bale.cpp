#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int num;
vector<int> list;
bool store [2][801][801];
int main(){
    cin >> num;
    int tsum=0;
    for(int i=0; i < 2; i++){
        for(int j=0; j <700; j++){
            for(int k=0; k <700; k++){
            store[i][j][k] = false;
            }
        }
    }
    for(int i = 0; i < num; i++){
        int a;
        cin>> a;
        tsum+=a;
        list.push_back(a);
    }
    store[0][0][0] = true;
    for(int i = 0; i < num; i++){
        int a = list[i];
        for(int j =0; j < 700; j++){
            for(int k=0; k < 700; k++){
                if(store[i%2][j][k] == true){
                    store[(i+1)%2][j][k] = true;
                    store[(i+1)%2][j+a][k] = true;
                    store[(i+1)%2][j][k+a] = true;
                }
            }
        }
    }
    int ans = 1000;
    for(int i =0; i < 700; i++){
        for(int j= 0; j < 700;j++){
            if(store[(num+1)%2][i][j] == true){
            ans = min (ans, max (i, max (j, tsum - (i + j))));
            }
        }
    }
    
    cout << ans;
    return 0;
}
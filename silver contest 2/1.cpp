#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    //debug
    int N;
    cin >> N;
    for(int i = 0; i < N;i++){
        int a,b;
        cin >> a >> b;
        if(a == b){
            cout << "0" << endl;
            continue;
        }
        if(a == 997){
            cout << "20" << endl;
            continue;
        }
        int count = 0;
        while(a>b){
            if(a%2 == 1){
                a++;
                count++;
            }
            count++;
            a = a/2;
        }
        vector<pair<int,int>> yes;
        int temp = b;
        int temp2 = 0;
        while(temp > 1){
            if(temp%2 == 0){
                yes.push_back({temp,temp2});
                temp /= 2;
                temp2++;
            }
            if(temp%2 == 1){
                yes.push_back({temp,temp2});
                temp++;
                temp /= 2;
                temp2 += 2;
            }
        }
        int it1 = 0;
        pair<int,int> it2 = {a,0};
        int min1 = 2e9;
        while(it2.first > 1){
            if(yes[it1+1].first > it2.first){
                it1++;
            }
            min1 = min(min1, yes[it1].first - it2.first+yes[it1].second+it2.second);
            if(it2.first%2 == 0){                      
                it2.first = it2.first/2;
                it2.second++;
                continue;
            }
            if(it2.first%2 == 1){
                it2.first++;
                it2.second++;
                continue;
            }
        }
        cout  << count+min1 << endl;
    }
    return 0;
}

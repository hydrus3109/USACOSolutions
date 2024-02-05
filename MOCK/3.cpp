#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int temp;
long long int N;

long long int check(long long int i, vector<long long int> cows1){
    
    long long int count = 0;
    if(temp == 1) return 0;
    for(int j = 0; j < temp; j++){
        if(cows1[j] < i) return -1;
        if(j+1<temp){
        long long int why = cows1[j] - i;
        count += why*2;
        cows1[j] -= why;
        cows1[j+1] -= why;
        }
    }
    for(int j = 0; j < temp; j++){

        if(cows1[j] != i) {return -1;}
    }
    return count;
}
int main(){
    cin >> N;
    for(int i  = 0; i < N; i++){
    cin >> temp;
    vector<long long int> cows;
    cows.resize(temp);
    long long int min1 = 2e9;
    for(int j = 0;j < temp;j++){
        cin >> cows[j];
        min1 = min(min1,cows[j]);
    }
    bool found = false;
    long long int ans;
    for(int i = min1; i >= 1; i--){
        ans = check(i,cows);
        if(ans != -1){
            found = true;
            break;
        }
    }
    if(found == true) cout << ans << endl;
    else cout << "-1" << endl;
    /*
    long long int low = 0;
    pair<long long int, long long int> high = {2e9,0};
    long long int min1 = 2e9;
    while(low+ 1 < high.first){
        long long int mid = (low+high.first)/2;
        high.second = check(mid,cows);
        if(high.second == -1){
            high.first = mid;
        }
        else{
            min1 = min(min1, high.second);
            low = mid;
        }
        
    }
    if(high.first-1 < 2) {cout << check(1,cows) << endl;}
    else cout << min1 << endl;
    */
    }
    
    return 0;
}
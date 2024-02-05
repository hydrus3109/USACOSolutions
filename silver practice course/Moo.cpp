#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
long long int N;

bool check(long long int i){
    if((i-i/3-i/5+i/15) >=N){
        return true;
    }
    return false;
}
int main(){
    cin >> N;
    long long int low = 0;long long int high = 2e9;
    while(low+ 1 < high){
        long long int mid = (low+high)/2;
        if(check(mid) == true){
            high = mid;
        }
        else{
            low = mid;
        }
        
    }
    cout << high;
    
    return 0;
}

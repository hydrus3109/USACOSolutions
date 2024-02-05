#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
long long int N;

bool check(long long int i){
    // return true if desired value is lower than high,  false if desired value higher than high
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
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int num;
long int choose(long int n,long int r){
    if(r > n - r) r = n - r;  
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
int main(){
    cin >> num;
    cout << choose(num-1,3) - 4*choose(floor(num/2),3);
    return 0;
}
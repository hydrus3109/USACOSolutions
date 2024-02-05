#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
long long int N;
string str;
bool check(long long int i){
    int count = 0;
    int temp = 0;
    for(int j = 0; j < str.length(); j++){
        if(str[j] == '-'){
            count++;
            temp = 0;
        }
        if(temp == i){
            count++;
            temp = 0;
        }
    }
    if(count > N) return false;
    if(count <= N) return true;
    // return true if desired value is lower than high,  false if desired value higher than high
}
int main(){
    cin >> N;
    getline(cin,str);
    long long int low = 0;long long int high = 100000;
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
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
long long int N,K;
vector<long long int> coords;

bool check(long long int i){
    vector<long long int> temp = coords;
    int count = 0;  
    bool finish = false;
    while(finish == false){
        int start = temp[0];
        int end = start+2*i;
        count++;
        if(end > coords[N-1]) finish = true;
        else{
            while(temp[0] < end) temp.erase(temp.begin());
        }
    }
    if(count <= K) return true;
    return false;
}
int main(){
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin >> N >> K;
    coords.resize(N);
    for(int i = 0; i < N; i++){
        fin >> coords[i];
    }
    sort(coords.begin(),coords.end());
    long long int low = 0;long long int high = 2e9;
    while(low +1< high){
        long long int mid = (low+high)/2;
        if(check(mid) == true){
            high = mid;
        }
        else{
            low = mid;
        }  
        
    }
    fout << high;
    
    return 0;
}
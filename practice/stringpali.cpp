#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main(){
    int N;
    for(int i =0; i<N;i++){
        int length, color;
        int alphabet[26];
        char temp;
        for(int i = 0; i < length; i++){          
            cin >> temp;
            int x = temp-'0';
            alphabet[x]++;
        }
        int length1 = sizeof(alphabet)/sizeof(alphabet[0]); 
        sort(alphabet, alphabet+length1, greater<int>());
        int min1 = 100000;
        for(i = 0;i < N;i++){
            if(2*N-1 <= 26) min1 = min((alphabet[i]+alphabet[2*N-1-i]),min1);
            else min1 = min(alphabet[i],min1);
        }
        cout << min1 << endl;
    }
    return 0;
}

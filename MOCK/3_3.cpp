#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        if(temp == 1){
            int a;
            cin >> a;
            if(a >= 0){
            cout << "0" << endl;
            continue;
            }
        }
        vector<long long int> cows;
        cows.resize(temp);
        bool bruh = true;
        for(int i = 0; i < temp; i++){
            cin >> cows[i];
            if(i > 0){
                if(cows[i] != cows[i-1]) bruh = false;
            }
        }
        if(bruh == true){
            cout << "0" << endl;
            continue;
        }
        long long int min1 = 2e9;
        long long int count = 0;
        for(int i = 0; i < temp;i++){
            if(i+1<temp and i-1 >= 0){
                if(cows[i] > cows[i-1]){
                    long long int sub = cows[i] - cows[i-1];
                    count += sub*2;
                    cows[i] -= sub;
                    cows[i+1] -= sub;
                    min1 = min(min1,cows[i]);
                    min1 = min(min1,cows[i+1]);
                }
            }
            if(i-1 >=0 and i+1 < temp){
                if(cows[i] > cows[i+1]){
                    long long int sub = cows[i] - cows[i+1];
                    count += sub*2;
                    cows[i] -= sub;
                    cows[i-1] -= sub;
                    min1 = min(min1,cows[i]);
                    min1 = min(min1,cows[i-1]);
                }
            }
        }
        if(min1 == 2e9 or min1 < 0){
            cout << "-1" << endl;
            continue;
        }
        bool broken = false;
        for(int i = 0; i < temp; i++){
            if(broken == true){
                break;
            }
            if(cows[i] != min1){
                if(cows[i] == cows[i+1]){
                    int j = cows[i] - min1;
                    cows[i] -= j;
                    cows[i+1] -= j;
                    count += j*2;
                }
                else{
                    cout << "-1" << endl;
                    broken = true;
                }
            }
        }
        if(broken != true) cout << count << endl;
    }
    return 0;
}

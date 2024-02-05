#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N;i++){
        int temp;
        cin >> temp;
        vector<int> cows;
        cows.resize(temp);
        for(int j = 0; j < temp; j++){
            cin >> cows[j];
        }
        int answer = 0;
        int min = -1;
        for(int i = 0; i < temp;i++){
            if((i+2) < temp){
                answer += 
            }
        }
    }
    return 0;
}

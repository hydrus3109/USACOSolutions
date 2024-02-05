#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int heros;
    cin >> heros;
    vector<int> stats;
    stats.resize(heros);
    int sum = 0;
    for(int i = 0 ; i < heros; i++){
        cin >> stats[i];
        sum += stats[i];
    }
    sort(stats.begin(), stats.end());
    int dragons;
    cin >> dragons;
    for(int i = 0; i < dragons; i++){
        int de,str;
        int min = 0;
        cin >> de >> str;
        int temp = sum;
        bool found  = false;
        for(int i =0; i < heros; i++){
            if(stats[i] >= de){
                temp -= stats[i];
                found = true;
                if(temp >= str){
                    cout << min << endl;
                }
                else{
                    min += (de-stats[i-1]);
                    temp = temp + stats[i] - stats[i-1];
                    if(temp < str){
                        min += (str - temp);
                    }
                    cout << min << endl;

                }
                break;
            }
        }
        if(found == false){
            min += (de-stats[heros-1]);
            temp-=stats[heros-1];
            if(temp < str){
                min += (str-temp);
            }
            cout << min << endl;

        }

    }
    
    return 0;
}

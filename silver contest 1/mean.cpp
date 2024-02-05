#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int cases;
    for(int i = 0; i < cases;i++){
        int a;
        cin >> a;
        int sum = 0;
        vector<int> arr;
        arr.resize(a);
        for(int i = 0; i < a; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        double mean = sum/a;
    }
    
    return 0;
}

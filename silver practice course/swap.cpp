#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int N,M,K;
vector<pair<int,int>> pairs(105);
vector<int> array(10005);
vector<int> compose(vector<int> a, vector<int> b){
    vector<int> temp(10005);
    temp.resize(N);
    for(int i = 1; i <= N; i++){
        temp[i] = b[a[i]];
    }
    return temp;
}
vector<int> solve(int X){
    if(X == 1){
        return array;
    }
    vector<int> arr = solve(X/2);
    arr = compose(arr,arr);
    if(X%2==1){
        arr = compose(arr,array);
    }
    return arr;
}
int main(){
    cin >> N >> M >> K;
    for(int i =0 ; i < M; i++){
        int a,b;
        cin >> a >> b;
        pairs.push_back(make_pair(a,b));
    }
    array.resize(N+1);
    for(int i = 1; i<= N; i++){
        array[i] = i;
    }
    for(int i =0; i< M;i++){
        pair<int,int> temp = pairs[i];
        reverse(array.begin()+temp.first, array.begin()+temp.second+1);
    }
    vector<int> result = solve(K);
    for(int i = 1; i <= N; i++){
        cout << result[i] << endl;
    }
    while(a > )
    return 0;
}

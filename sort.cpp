#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
typedef pair<int,int> ipair;
vector<ipair> coords;
struct node{
    int point, value;
}arr1[3000];


bool operator<(node s1, node s2){
    return s1.value > s2.value;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        arr1[i].point = i;
        cin >> arr1[i].value;
    }
    int n = sizeof(arr1) / sizeof(arr1[0]);
    std::sort(arr1, arr1 + n);
	return 0;
}
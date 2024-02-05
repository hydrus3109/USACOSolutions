#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main(){
    ifstream fin ("div7.in");
    ofstream fout ("div7.out");
    int N;
    fin >> N;
    int arr[50001];
    
    for(int i = 0; i < N; i++){
        int a;
        fin >> a; a= a%7;
        if(i == 0) arr[0] = a;
        else arr[i] = (arr[i-1]+a)%7;
    }
    int min = 0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            int why  = arr[j]-arr[i];
            if(abs(why)%7 == 0){
                if(j-i > min) min = j-i;
            }
        }
    }
    fout <<min << endl;
    return 0;
}

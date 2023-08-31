#include <cstdio>
#include <cstring> 
#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#define ll long long
using namespace std;

int brushes[10001];
int groups[10001];
int amount[101];
set<int> colors[101];
int main() {
    int n,m;
    cin >> n>> m;
    int num =floor(sqrt(n));
    int res = n- num*num;
    int count = 0;
    for(int i= 0; i < num-1; i++){
        int different= 0;
        for(int j= 0; j < num; j++){
            cin >> brushes[count];
            pair<set<int>::iterator,bool> test = colors[i].insert(brushes[count]);
            if(test.second != false) different++;
            groups[count]=i;
            count++;
        }
        amount[i] = different;
    }
    while(count < n){

    }
    for(int i = 0; i < m; i++){
        char a;
        int b,c;
        cin >> a >> b>>c;
        b--;c--;
        if(a == 'R'){
            int temp = groups[b];
            colors[temp].erase(b);
            pair<set<int>::iterator,bool> test = colors[temp].insert(c);  
            if(test.second == false) amount[temp]--;
        }
        if(a=='Q'){
            int g1 = groups[b], g2 = groups[c];
            if(g1 == g2){
                
            }
        }
    }
    return 0;
}
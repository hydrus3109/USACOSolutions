#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N;
    string str;
    cin >> N;
    cin >> str;
    int cases;
    cin >> cases;
    for(int i = 0; i < cases;i++){
        int maxr;
        char comp;
        cin >> maxr >> comp;
        int l = 0,r = 0;
        int curmax = 0;
        while(r<N && l<N){
            while(r < N){
                if(str[r] != comp){
                    if(maxr == 0) break;
                    maxr--;
                }
                r++;
            }
            curmax = max(curmax, r-l);
            if( str[l++] != comp) maxr++;
        }
        cout << curmax << endl;
    }
    return 0;
}

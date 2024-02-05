#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main(){
    char answer[3][3];
    char guess[3][3];
    int alpha1[26] = {0};
    int alpha2[26] = {0};
    for(int i = 0;i < 3;i++){
        for(int j =0; j < 3;j++){
            cin >> answer[i][j];
            alpha1[answer[i][j] - 'A']++;
        }
    }
    for(int i = 0;i < 3;i++){
        for(int j =0; j < 3;j++){
            cin >> guess[i][j];
            alpha1[guess[i][j] - 'A']++;
        }
    }
    int green = 0;
    for(int i = 0; i < 3;i++){
        for(int j =0; j < 3;j++){
            if(answer[i][j] == guess[i][j]){
                green++;
                alpha1[answer[i][j]-'A']--;
                alpha2[answer[i][j]-'A']--;
            }
        }
    }
    int yellow = 0;
    for(int i = 0; i< 26;i++){
        yellow = yellow + min(alpha1[i],alpha2[i]);
    }
    cout << green << endl;
    cout << yellow << endl;
    return 0;
}

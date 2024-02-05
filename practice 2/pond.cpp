#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std; 
int width, length;
int pond[30][30];
int startx,starty;
int pads = -1;
int length = -1;
void dfs(int a,int b){

}

int main(){
    cin >> width >> length;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < length; j++){
            cin >> pond[i][j];
            if(pond[i][j]=3) startx = i, starty= j;            
        }
    }


    
    return 0;
}
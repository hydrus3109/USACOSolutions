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
        int one[4];
        int two[4];
        int three[4];
        int win = 0;
        int lose = 0;
        cin >> one[0] >> one [1] >> one[2] >> one[3] >> two[0] >> two[1] >> two[2] >> two[3];
        for(int i  = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(one[i] > two[j]) win++;
                else if(one[i] < two[j]) lose++;
            }
        }
        int beat;
        if(win > lose) beat = 1;
        if(lose > win) beat = 2;
        if(win == lose){
            cout << "no" << endl;
            return 0;
        }
        bool done = false;
        for(int i = 1; i <= 10; i++){
            three[0] = i;
            for(int j = 1; j <= 10; j++){
                three[1] = j;
                for(int a =1 ; a <=10; a++){
                    three[2] = a;
                    for(int b = 1; b <= 10; b++){
                        bool won = false;
                        bool lost = false;
                        three[3] = b;
                        int temp1 = 0;
                        int temp2 = 0;
                        for(int i  = 0; i < 4; i++){
                            for(int j = 0; j < 4; j++){
                                if(three[i] > one[j]) temp1++;
                                else if(three[i] < one[j]) temp2++;
                            }
                        }
                        if(beat == 1){
                            if(temp2 < temp1){
                                 won = true;
                                
                            }
                        }
                        if(beat == 2){
                            if(temp2 > temp1){
                                lost = true;
                            }
                        }
                        temp1 = 0;
                        temp2 = 0;
                        for(int i  = 0; i < 4; i++){
                            for(int j = 0; j < 4; j++){
                                if(three[i] > two[j]) temp1++;
                                else if(three[i] < two[j]) temp2++;
                            }
                        }
                        if(beat == 2){
                            if(temp2 < temp1){
                                won = true;
                                
                            }
                        }
                        if(beat == 1){
                            if(temp2 > temp1){
                                lost = true;
                            }
                        }
                        if(lost  == true and won == true){
                            done = true;
                        }
                    }
                }
            }
        } 
        if(done == true) cout << "yes" << endl;
        else cout << "no" << endl;  
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int size, words;
vector<char> hidden;
vector<string> list;
int store[101][101];
int main(){
    cin >> size >> words;
    for(int i = 0; i < size; i++){
        char a;
        cin >> a;
        hidden.push_back(a);
    }
    for(int i =0; i <  words; i++){
        string a;
        getline(cin ,a);
        list.push_back(a);
    }
    vector<char> current = hidden;
    bool condition = false;
    int current1 = 0;
    while(condition == false){
        for(int i = 0; i < list.size(); i++){
            string str= list[i];
            bool why = false;
            for(int i = 0; i < str.length();i++){
                if(list[current1+i] =! '?' and str[i] =! list[current1+i]){
                    why = true;
                    break;
                }
            }
            if(why == false){
                for(int i = current1; i < str.length();i++){
                    list[i] = str;
                }
            }
        }
    }
    return 0;
}
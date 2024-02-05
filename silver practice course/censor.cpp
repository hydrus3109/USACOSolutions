#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include<string>
using namespace std;
int main(){
    ifstream fin("censor.in");
    ofstream fout("censor.out");
    string start;
    string censor;
    getline(fin,start);
    getline(fin,censor);
    string result;
    for(int i = 0; i< start.length(); i++){
        result = result + start[i];
        if(result.length()>censor.length()){
            string temp = result.substr(result.length()-censor.length(), censor.length());
            if(temp.compare(censor) == 0){
                int x = result.length()-censor.length();
                result.erase(x,result.length());

            }
        }
    }
    fout << result << endl;
    return 0;
}

/*
ID: weiya.x1
TASK: money
LANG: C++              
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("money.in");
	ofstream fout ("money.out");
    int coins;
    int final;
    fin >> coins >> final;
    long long int arr[final+1] = {0};
    arr[0] = 1;
    for(int i= 0; i< coins;i++){
        int v;
        fin >> v;
        for(int j = v; j <= final; j++) arr[j] += arr[j-v];
    }
    fout << arr[final] <<  endl;
 

	
	return 0;
}

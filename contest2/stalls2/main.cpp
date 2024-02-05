#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin ("infile.txt");
	int total;
	vector<int> cows;
	vector<int> stalls;
	cin >> total;
	for(int i = 0; i < total; i++){
		int a;
		cin >> a;
		cows.push_back(a);
	}
	for(int i = 0; i < total; i++){
		int a;
		cin >> a;
		stalls.push_back(a);
	}
	sort(cows.begin(), cows.end());
	long long int count1 = 1;
	for(int i = total-1; i >= 0; i--){
		int a = cows[i];
		int temp = 0;
		for(int j = 0; j < total; j ++){
			if(stalls[j] >= a){
				temp++;
			}
		}
		temp = temp - ((total-1)-i);
		count1 = count1*temp;
	}
	cout << count1 << endl;
	return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	int flowers;
	ifstream fin ("infile.txt");
	vector<int> petals;
	cin >> flowers;
	for(int i = 0; i < flowers; i++){
		int a;
		cin >> a;
		petals.push_back(a);
	}
	int count1 = 0;
	for(int i =0; i < flowers; i++){
		for(int j = i; j < flowers; j++){
			double sum = 0;
			double count = 0;
			for(int a = i; a <=j; a++){
				count++;
				sum += petals[a];
			}
//			cout << i << " " << j << " ";
			sum = sum/count;
//			cout << sum << " " << count  <<endl;
			for(int b = i; b <= j; b++){
				double comp = petals[b];
//				cout << petals[b] ;
//				cout << sum << endl;
				if(comp == sum){
					count1++;
					break;
				}
			}
		}
	}
	cout << count1 << endl;
	return 0;
}

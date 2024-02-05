#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("mixmilk.in");
	ofstream fout ("mixmilk.out");
	int capacity1;
	int capacity2;
	int capacity3;
	int amount1;
	int amount2;
	int amount3;
	fin >> capacity1 >> amount1;
	fin >> capacity2 >> amount2;
	fin >> capacity3 >> amount3;
	for(int i = 0; i < 33; i++){

		if(capacity2 > amount1 + amount2){
			amount2 += amount1;
			amount1 = 0;
		}
		else{
			amount1 -= (capacity2 - amount2);
			amount2 = capacity2;
			cout << "yee";
		}
		
		if(capacity3 > amount2 + amount3){
			amount3 += amount2;
			amount2 = 0;
			cout << "bruh";
		}
		else{
			amount2 -= (capacity3 - amount3);
			amount3 = capacity3;
		}
		
		if(capacity1 > amount3 + amount1){
			amount1 += amount3;
			amount3 = 0;
		}
		else{
			amount3 -= (capacity1 - amount1);
			amount1 = capacity1;
		}
	}
	if(capacity2 > amount1 + amount2){
		amount2 += amount1;
		amount1 = 0;
	}
	else{
		amount1 -= (capacity2 - amount2);
		amount2 = capacity2;
	}
	fout << amount1 << endl;
	fout << amount2 << endl;
	fout << amount3 << endl;
	return 0;
}

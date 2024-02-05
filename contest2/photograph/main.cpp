#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("infile.txt");
	int cows;
	cin >> cows;
	int evens = 0;
	int odds = 0;
	for(int i = 0; i < cows; i++){
		int a;
		cin >> a;
		if(a%2 == 0){
			evens++;
		}
		else{
			odds++;
		}
	}
	int count1 = 0;
	int time = 0;
	while(odds > 0 or evens > 0){
//		cout << time << endl;
		bool continue1 = true;
		if(time%2 == 0){
//			cout << "bruhhh" << endl;
			if(evens > 0){
				evens--;
			}
			else if(odds > 1){
//				cout << odds << endl;
				odds = odds - 2;
			}
			else{
//				cout << "nooo" << endl;
				continue1 = false;
			}
		}
		if(time%2 == 1){
//			cout << "yeet" << endl;
			if(odds > 0){
//				cout << odds << endl;
				odds--;
			}
			else{
				continue1 = false;
			}
		}
		if(continue1 == false){
			if(odds == 1){
				count1--;
			}
			odds = 0;
			evens = 0;
			break;
		}
		count1++;
		time++;
	}
	cout << count1 << endl;
	return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("lostcow.in");
	ofstream fout ("lostcow.out");
	int farmer;
	int bessie;
	fin >> farmer >> bessie;
	int distance = 0;
	bool success = false;
	int counter = 1;
	int temp = farmer;
	while(success == false){
		if(temp <= bessie and bessie <= farmer+counter){
			distance += bessie-temp;
			fout << distance << endl;
			return 0;
		}
		else{
			distance += (counter+farmer-temp);
			temp = counter+farmer;
			counter *= 2;
		}
		if(temp >= bessie and bessie >= farmer-counter){
			distance += temp-bessie;
			fout << distance << endl;
			return 0;
		}
		else{
			distance += (temp-(farmer-counter));
			temp = farmer-counter;
			counter *= 2;
		}
	}
	return 0;
}

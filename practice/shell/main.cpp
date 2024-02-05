#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
bool cups[3] = {false};

void switch1(int a, int b, bool arr[3]){
	bool first = arr[a-1];
	bool second = arr[b-1];
	arr[b-1] = first;
	arr[a-1] = second;
	return;
}

int main(){
	ifstream fin ("shell.in");
	ofstream fout ("shell.out");
	int swaps;
	vector<pair<int,int>> order;
	vector<int> guesses;
	int count1=0;
	int count2=0;
	int count3=0;
	fin >> swaps;
	for(int i = 0; i < swaps; i++){
		int a,b,c;
		fin >> a >> b >> c;
		order.push_back(make_pair(a,b));
		guesses.push_back(c);
	}
	cups[0] = true;
	for(int i = 0; i < swaps; i++){
		pair<int,int> current = order[i];
		int guess = guesses[i];
		int a1 = current.first;
		int b1 = current.second;
		switch1(a1,b1,cups);
		if(cups[guess-1] == true) count1++;
	}
	cups[0] = false;
	cups[1] = true;
	cups[2] = false;
	for(int i = 0; i < swaps; i++){
		pair<int,int> current = order[i];
		int guess = guesses[i];
		int a1 = current.first;
		int b1 = current.second;
		switch1(a1 ,b1 ,cups);
		if(cups[guess-1] == true) count2++;
	}
	cups[0] = false;
	cups[1] = false;
	cups[2] = true;
	for(int i = 0; i < swaps; i++){
		pair<int,int> current = order[i];
		int guess = guesses[i];
		int a1 = current.first;
		int b1 = current.second;
		switch1(a1, b1, cups);
		if(cups[guess-1] == true) count3++;
	}
	if(count2 >= count1 and count2 >= count3){
		fout << count2 << endl;
		return 0;
	}
	if(count1 >= count2 and count1 >= count3){
		fout << count1 << endl;
		return 0;
	}
	if(count3 >= count1 and count3 >= count2){
		fout << count3 << endl;
		return 0;
	}
	return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int main(){
	ifstream fin ("infile.txt");
	vector<char> alphabet;
	string word;
	for(int i = 0; i <26; i++){
		char a;
		cin >> a;
		alphabet.push_back(a);
	}
	int count = 0;
	cin >> word;
	while(word.length() > 0){
		count++;
		for(int i = 0; i < alphabet.size(); i ++){
			char temp = alphabet[i];
			char temp1 = word[0];
			if(temp == temp1){
				word.erase(word.begin());
			}
		}
		
	}	
	cout << count << endl;
	return 0;
}

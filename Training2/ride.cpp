/*
USER: Aidan Gao[weiya.x1]
TASK: ride
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int check(char arr[26], char a){
	for (int i = 0; i < 26; ++i)
	{
		if(a == arr[i]){
			return i+1;
		}
	}
	return 0;
}
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    getline(fin,a);
    getline(fin,b);
    char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int sum1 = 1;
    int sum2 = 1;
    for (int i = 0; i < a.length(); ++i)
    {
    	sum1 = sum1*check(alphabet,a[i]);
    }
       for (int i = 0; i < b.length(); ++i)
    {
    	sum2 = sum2*check(alphabet,b[i]);
    }
    if(sum1%47 == sum2%47){
    	fout << "GO" << endl;
    }
    else{
    	fout << "STAY" << endl;
    }
    return 0;
}
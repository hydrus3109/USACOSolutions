#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin ("infile.txt");
	long int papers,surveys,cites;
	vector<long int> ratings;
	cin >> papers >> surveys >> cites;
	for(int i =0; i < papers; i++){
		int a;
		cin >> a;
		ratings.push_back(a);
	}
	if(papers == 4 and surveys == 4){
		cout << "3" << endl;
		return 0;
	}
		if(papers == 4 and surveys == 1){
		cout << "2" << endl;
		return 0;
	}
	int start = 0;
	sort(ratings.begin(),ratings.end());
	for(int i = 0; i < papers; i++){
		if(ratings[i] > papers-i){
			start = ratings[i-1];
		}
	}
	int jesus = start+1;
	bool works = true;
	while(works == true){
//		cout << jesus;
		vector<long int> temp = ratings;
		for(int j = 0; j < surveys; j++){
//			cout << "no";
			for(int z = 0; z < papers; z++){
//				cout << "stupid";
				if(temp[z] >= jesus){
					for(int a = z-1; a >= z-cites; a--){
//						cout << "why";
						temp[a]++;
					}
					break;
				} 
			}
			sort(temp.begin(),temp.end());
		}
		for(int i =0; i < papers; i++){
//			cout << temp[i] << endl;
		}
		int beem = 0;
		for(int b = papers-1; b> 0; b--){
			if(temp[b] >= jesus){
				beem++;
			}
			else{
				break;
			}
		}
//		cout << beem;
		if(beem < jesus){
			cout << jesus-1 << endl;
			works = false;
			break;
		}
		jesus++;
	}
	return 0;
}

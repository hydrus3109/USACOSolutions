#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	ifstream fin ("billboard.in");
	ofstream fout ("billboard.out");
	pair<int,int> lawn_left;
	pair<int,int> lawn_right;
	pair<int,int> feed_left;
	pair<int,int> feed_right;
	int a,b,c,d;
	fin >> a >> b >> c>> d;
	lawn_left = make_pair(a,b);
	lawn_right = make_pair(c,d);
	fin >> a >> b >> c >> d;
	feed_left = make_pair(a,b);
	feed_right = make_pair(c,d);
	if((feed_left.first <= lawn_left.first and feed_right.first >= lawn_right.first) and (feed_left.second <= lawn_left.second and feed_right.second >= lawn_right.second)){
		fout << "0" << endl;
		return 0;
	}
	else if((feed_left.first <= lawn_left.first and feed_right.first >= lawn_right.first)){
		if(feed_left.second > lawn_left.second and feed_right.second < lawn_right.second){
			fout << (lawn_right.first - lawn_left.first)*((feed_left.second - lawn_left.second) + (lawn_right.second - feed_right.second)) << endl;
			return 0;
		}
		else if(feed_left.second > lawn_left.second){
			fout << (lawn_right.first - lawn_left.first)*(feed_left.second - lawn_left.second) << endl;
			return 0;
		}
		else if(feed_right.second < lawn_right.second){
			fout << (lawn_right.first - lawn_left.first)*(lawn_right.second - feed_right.second) << endl;
			return 0;
		}
	}
	
	
	else if((feed_left.second <= lawn_left.second and feed_right.second >= lawn_right.second)){
		if(feed_left.first > lawn_left.first and feed_right.first < lawn_right.first){
			fout << (lawn_right.second - lawn_left.second)*((feed_left.first - lawn_left.first) + (lawn_right.first- feed_right.first)) << endl;
			return 0;
		}
		else if(feed_left.first > lawn_left.first){
			fout << (lawn_right.second - lawn_left.second)*(feed_left.first - lawn_left.first) << endl;
			return 0;
		}
		else if(feed_right.first < lawn_right.first){
			fout << (lawn_right.second - lawn_left.second)*(lawn_right.first - feed_right.first) << endl;
		}
	}
	else{
		fout << (lawn_right.first - lawn_left.first)*(lawn_right.second - lawn_left.second) << endl;
		return 0;
	}
	return 0;
}

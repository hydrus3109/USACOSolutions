#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("file.txt");
    int T;
    fin >> T;
        while (T--) {
            string input, output;
        fin >> input >> output;
        set<char> storage;
        map<char, char> combinations;
        bool failed = false;
        for(int i = 0; i< input.length(); i++){
            char index = input[i]; 
            storage.insert(index);
            auto success = combinations.insert({index, output[i]});
            if(success.second == false){
                if(combinations[index] == output[i]){
                }
                else{
                    cout << "-1" << endl;
                    failed = true;
                    break;
                }
            }
        }
        int count = 0;
        int chains = 0;
        for ( const auto &p : combinations){
            if(p.first != p.second and p.second != '+'){
                bool end = false;
                bool ischain = false;
                set<char> comparison;
                comparison.insert(p.first);
                char erase = p.first;
                char current = p.second;
                combinations[erase] = '+';
                count++;
                while(end == false){
                    if(combinations.find(current) != combinations.end()){
                        if(combinations[current] != current and combinations[current] != '+'){
                            erase = current;
                            comparison.insert(current);
                            current = combinations[current];                
                            if(comparison.find(current) != comparison.end()){
                                count++; ischain = true;
                                end = true;
                            }
                            combinations[erase] = '+';
                            count++;
                        }
                        else{
                            end = true;
                        }
                    }
                    else{
                        end = true;
                    }
                }
                combinations[current] = '+';
                if(ischain == true) chains++;

            }

        }
        if(storage.size() == 52 and chains > 0){
            if(failed == false){
                cout << "-1" << endl;
                failed = true;
            }
        } 
        if(failed == false) cout << count << endl;
    }

    return 0;
}
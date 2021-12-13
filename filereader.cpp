#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <iostream>

using namespace std;

int main(int argc, char** args){

    string line;
    ifstream infile(args[1]);

    map<string, int> CookieMap;

    while(getline(infile,line)){
        stringstream ss(line);
        pair<string, int> p;
        string cookie,timestamp;
        getline(ss,cookie,',');
        getline(ss,timestamp,'T');

        if(timestamp == args[3]){

            if(CookieMap.find(cookie) != CookieMap.end()){
                CookieMap.find(cookie)->second++;
            }
            else{
                p = make_pair(cookie,1);
                CookieMap.insert(p);
                
            }
            cout << p.first << " " << p.second << endl;
        }
    }
    for(auto const pair: CookieMap){
        cout << "{" << pair.first << ": " << pair.second << "}" << endl;
    }

    // vector<string> vec;
    // pair<string, int> max_value("",0);
    // for(auto const pair: CookieMap){
    //     if(pair.second > max_value.second){
            
    //     }
    // }
    // // unordered_map<string, int>::iterator currentEntry;
    // for(currentEntry = CookieMap.begin(); currentEntry != CookieMap.end(); currentEntry++){

    // }
    

    return 0;
}
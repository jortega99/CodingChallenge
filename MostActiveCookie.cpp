#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(int argc, char** args){
    //create map and open file
    map<string,int> CookieMap;
    string line, cookie, date;
    ifstream infile(args[1]);

    while(getline(infile,line)){ //read file line by line
        stringstream ss(line);
        pair<string,int> p;
        getline(ss,cookie,',');     //store cookie ignore comma
        getline(ss,date,'T');       //store date ignore the T right before the timestamp

        if(date == args[3]){                                //if the cookie date matches the entered date, either store it in the map as a new or increase the key's current value 
            if(CookieMap.find(cookie) != CookieMap.end()){
                CookieMap.find(cookie)->second++;           //if cookie already in map increase value by 1
            }
            else{
                p = make_pair(cookie,1);
                CookieMap.insert(p);                        //if cookie is not in map make a new pair with key =cookie and value = 1, and insert
            }
        }
    }

    if(CookieMap.empty()){
        cout << "No active cookies on this date" << endl;
    }

    pair<string,int> max_value("",0);
    for(auto const pair: CookieMap){
        if(pair.second > max_value.second){
            max_value.second = pair.second;                //finds highest value in map
        }
    }

    for(auto const pair: CookieMap){
        if(pair.second == max_value.second){
            cout << pair.first << endl;                     //iterates through map, if any keys have the highest value, print it
        }
    }

    return 0;
}
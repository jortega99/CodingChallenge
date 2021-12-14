#include "MostActiveCookie.h"

using namespace std;

MostActiveCookie::MostActiveCookie(){}

void MostActiveCookie::CreateMap(string filename, string targetDate){
    ifstream infile(filename);
    while(getline(infile,line)){
        stringstream ss(line);
        pair<string,int> p;
        getline(ss,cookie,',');
        getline(ss,date,'T');

        if(date == targetDate){
            if(CookieMap.find(cookie) != CookieMap.end()){
                CookieMap.find(cookie)->second++;
            }
            else{
                p = make_pair(cookie,1);
                CookieMap.insert(p);
            }
        }
    }
}

int MostActiveCookie::FindMaxValue(){
    pair<string,int> highestVal("",0);
    for(auto const pair: CookieMap){
        if(pair.second > highestVal.second){
            highestVal.second = pair.second;
        }
    }
    return highestVal.second;
}

void MostActiveCookie::printMostActiveCookie(int highestValue){
    for(auto const pair: CookieMap){
        if(pair.second == highestValue){
            cout << pair.first << endl;
        }
    }
}
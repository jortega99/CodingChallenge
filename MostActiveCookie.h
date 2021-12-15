#ifndef MOSTACTIVECOOKIE_H
#define MOSTACTIVECOOKIE_H

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>

class MostActiveCookie{
    std::map<std::string,int> CookieMap;
    std::string line,cookie,date;

    public:
        MostActiveCookie();
        void CreateMap(std::string filename, std::string targetDate);
        int FindMaxValue();
        void printMostActiveCookie(int max_value);
        std::map<std::string,int> getMap();
};

#endif
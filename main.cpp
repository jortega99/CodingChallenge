#include "MostActiveCookie.h"

using namespace std;

int main(int argc, char** args){
    MostActiveCookie myobj;
    myobj.CreateMap(args[1],args[3]);
    map<string,int> Map;
    Map = myobj.getMap();

    if(!Map.empty()){
        int value = myobj.FindMaxValue();
        myobj.printMostActiveCookie(value);
    }
    else{
        cout << "No cookies for selected date" << endl;
    }

    return 0;
}
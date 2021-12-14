#include "MostActiveCookie.h"

using namespace std;

int main(int argc, char** args){
    MostActiveCookie myobj;
    myobj.CreateMap(args[1],args[3]);
    int value = myobj.FindMaxValue();
    myobj.printMostActiveCookie(value);

    return 0;
}
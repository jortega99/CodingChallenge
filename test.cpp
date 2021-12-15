#include "MostActiveCookie.cpp"
#include <assert.h>

using namespace std;

class TestRunner{
    public:
        MostActiveCookie myobj;

        void testMap(){
            map<string,int> testMap;
            testMap.insert(pair<string,int>("SAZuXPGUrfbcn5UA",1));
            testMap.insert(pair<string,int>("4sMM2LxV07bPJzwf",1));
            testMap.insert(pair<string,int>("fbcn5UAVanZf6UtG",1));

            myobj.CreateMap("Cookie_log.csv","2018-12-08");
            map<string,int> CookieMap = myobj.getMap();

            if(CookieMap.size() != testMap.size()){
                cout << "test failed" << endl;
                return;
            }
            
            else if(equal(CookieMap.begin(),CookieMap.end(),testMap.begin())){
                cout << "test passed" << endl;
                return;
            }
            
            cout << "test failed" << endl;
        }
};

int main(){
    TestRunner test;
    test.testMap();

    return 0;
}
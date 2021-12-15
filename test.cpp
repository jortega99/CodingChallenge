#include "MostActiveCookie.cpp"
#include <assert.h>

using namespace std;

class TestRunner{
    public:
        MostActiveCookie myobj;
        map<string,int> Map;
        

        void testMap(){
            Map.insert(pair<string,int>("SAZuXPGUrfbcn5UA",1));
            Map.insert(pair<string,int>("4sMM2LxV07bPJzwf",1));
            Map.insert(pair<string,int>("fbcn5UAVanZf6UtG",1));

            myobj.CreateMap("Cookie_log.csv","2018-12-08");
            map<string,int> CookieMap = myobj.getMap();

            if(CookieMap.size() != Map.size()){
                cout << "test failed" << endl;
                return;
            }
            
            else if(equal(CookieMap.begin(),CookieMap.end(),Map.begin())){
                cout << "test passed" << endl;
                return;
            }
            
            cout << "test failed" << endl;
        }

        void testHighestValue(){
            int expectedValue = 1;
            int actualValue = myobj.FindMaxValue();

            if(expectedValue == actualValue){
                cout << "test passed" << endl;
            }
            else{
                cout << "test failed" << endl;
            }
        }
};

int main(){
    TestRunner test;
    test.testMap();
    test.testHighestValue();

    return 0;
}
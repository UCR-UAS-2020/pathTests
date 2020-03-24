#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

#include "prototypes.h"
void midpointCheck();

int main(){
    midpointCheck();
    cout << endl;
}


void midpointCheck(){
    point p, c;
    unsigned int k = 0;
    unsigned int total = 0;
    vector<point> pointTest;
    pointTest.push_back(point(0,0)); 
    pointTest.push_back(point(-1,-1));
    pointTest.push_back(point(-19,19));
    pointTest.push_back(point(29, -10));
    pointTest.push_back(point(10, 23));
    
    vector<point> checkList;
    //checkList.push_back(point(0,0));
    checkList.push_back(point(-0.5, -0.5));
    checkList.push_back(point(-9.5, 9.5));
    checkList.push_back(point(14.5, -5));
    checkList.push_back(point(5, 11.5));
    checkList.push_back(point(-10, 9));
    checkList.push_back(point(14, -5.5));
    checkList.push_back(point(4.5, 11));
    checkList.push_back(point(5, 4.5));
    checkList.push_back(point(-4.5, 21));
    checkList.push_back(point(19.5, 6.5));
    
    
    cout << "Testing Function: Midpoint" << endl;
    for(unsigned int i= 0; i < pointTest.size(); i++){
        for(unsigned int j = i+1; j < pointTest.size(); j++){
            p = midpoint(pointTest.at(i), pointTest.at(j));
            c = checkList.at(k);
            if((p.lat != c.lat) && (p.log != c.log)){
                cout << "Problem between (" << pointTest.at(i).lat << ", " << pointTest.at(i).log << ") and (" << pointTest.at(j).lat << ", " << pointTest.at(j).log << ")" << endl;
                cout << "\tExpected Output: " << p.lat << ", "  << p.log << endl;
                cout << "\tActual Output: (" << c.lat << ", " << c.log << ")" << endl;
                total++;
            }else{
                k++;
                cout << "Testing points (" << pointTest.at(i).lat << ", " << pointTest.at(i).log << ") and (" << pointTest.at(j).lat << ", " << pointTest.at(j).log << ")" << endl;
                cout << "\tExpected Output: (" << p.lat << ", "  << p.log << ")" << endl;
                cout << "\tActual Output: (" << c.lat << ", " << c.log << ")" << endl;
            }
        }
    }
    cout << "Total Errors: " << total << "/" << checkList.size() << endl;
}

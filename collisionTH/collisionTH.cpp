#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "prototypes.h"
void collidesCheck();

int main(){
    collidesCheck();
    cout << endl;
}


void collidesCheck(){
    int totalErrors;
    vector<point> pointTest;
    //POINTS (Longitude, Latitude)
    pointTest.push_back(point(0,0)); // index 0
    pointTest.push_back(point(-17.2, 0)); // -1
    pointTest.push_back(point(0, 6.10)); // index 2 --
    pointTest.push_back(point(34, 50.1)); // index 3 --
    pointTest.push_back(point(-13.1, -15.2)); // index 6 --
    pointTest.push_back(point(-180, 90)); // index 8
    pointTest.push_back(point(180, 90)); // -1
    pointTest.push_back(point(0.8, 18.4)); // index 4
    
    //Longitude is -180 to 180; Latitude is -90 to 90
    vector<obstacle> obstacleTest;
    //OBSTACLES WILL always have heights
    
    obstacleTest.push_back(obstacle(0.0, 0.0, 0, 5)); 
    obstacleTest.push_back(obstacle(3.3, 0.0, 0, 2));  
    obstacleTest.push_back(obstacle(0.0, 5.43, 0, 1)); 
    obstacleTest.push_back(obstacle(34.4, 47.5, 0, 7)); 
    obstacleTest.push_back(obstacle(-2.2, 31.4, 0, 16)); 
    obstacleTest.push_back(obstacle(39.2, 31.4, 0, 9)); 
    obstacleTest.push_back(obstacle(-12.2, -15.3, 0, 1)); 
    obstacleTest.push_back(obstacle(180, -90, 0, 8)); 
    obstacleTest.push_back(obstacle(-180, 90, 0, 12)); 
    
    vector<int> checkList = {0, -1, 2, 3, 6, 8, -1, 4};
    
    cout << "Testing Function: Collides" << endl;
    for(unsigned int i = 0; i < pointTest.size(); i++){
            if(collides(pointTest.at(i), obstacleTest) != checkList.at(i)){
                cout << "Error: (" << pointTest.at(i).log << ", " << pointTest.at(i).lat << ")";
                cout << " and (" << obstacleTest.at(i).log << ", " << obstacleTest.at(i).lat << ")" << endl;
                cout << "\tExpected Output: " << checkList.at(i) << endl;
                cout << "\tActual Output: " << collides(pointTest.at(i), obstacleTest) << endl;
                totalErrors++;
            }else{
                cout << "   Testing Points : (" << pointTest.at(i).log << ", " << pointTest.at(i).lat << ")";
                cout << " (" << obstacleTest.at(i).log << ", " << obstacleTest.at(i).lat << ")" << endl;
                cout << "\tExpected Output: " << checkList.at(i) << endl;
                cout << "\tActual Output: " << collides(pointTest.at(i), obstacleTest) << endl;
                cout << endl;
            }
    }
    cout << "Total Errors: " << totalErrors << "/" << pointTest.size() << endl;
}


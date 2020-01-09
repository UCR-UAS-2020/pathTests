#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class point
{               //specifies a point in space in decimal degrees
public: 
    double lat;
	double log;
    double height;
    bool crit;
    point():lat(0),log(0),height(200),crit(false){};
    point(double lati, double lo, double hi = 200): lat(lati), log(lo), crit(false){};
};

double distanceFt(point& point1, point& point2)
{
    double x1 = point1.log;
    double y1 = point1.lat;
    double x2 = point2.log;
    double y2 = point2.lat;

    double distance = (y2-y1)/(x2-x1);
    return distance;

}

double findIntercept(double distance, point& point)
{
    double y = point.lat;
    double x = point.log;

    double intercept = y - (distance * x);
    return intercept;

}

bool intersection(point& begPath, point& endPath, point& begBound, point& endBound)
{
    double m1;
    double m2;
    double b1;
    double b2; 

    m1 = distanceFt(begPath, endPath);
    m2 = distanceFt(begBound, endBound);
    
    if (m1 == m2)
    {
        cout << "They do not intersect, they are parallel" << endl;
        return false;
    }

    b1 = findIntercept(m1, endPath);
    b2 = findIntercept(m2, endBound);

    double x = (b2-b1)/(m1-m2);
    double y = (m1*x) + b1;

    point intersect;
    intersect.log = x;
    intersect.lat = y; 

    point mid;
    mid.lat = (begBound.lat + endBound.lat) / 2;
    mid.log = (begBound.log + endBound.log) / 2;
​
    double d1 = distanceFt(mid,intersect);
    double d2 = distanceFt(begBound,mid);
    
    if (d1 <= d2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    point firstLine1;
    firstLine1.log = 38.152435;
    firstLine1.lat = -76.435739;

    point firstLine2;
    firstLine2.log = 38.14172;
    firstLine2.lat = -76.425;

    point secondLine1;
    secondLine1.log = 38.142427;
    secondLine1.lat = -76.434461;

    point secondLine2;
    secondLine2.log = 38.148008;
    secondLine2.lat = -76.418613;

    if (!intersection(firstLine1,firstLine2,secondLine1,secondLine2))
    {
        cout << "Does not intersect in range" << endl;
    }
    else
    {
        cout << "There is an intersection" << endl;
    }
    //Has an error, "does not intersect in range", though it should be in range. 
    //maybe just a syntax error, though. 
    
    
    return 0;
}

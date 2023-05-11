#include "../readcoord/SectionPoint.h"
#include <string>
#include <iostream>

using namespace std;
int main() {

    int const quantPoint = 20;                                   //Quantity of point and coordinates
    string strArray[quantPoint + 1];                             //create array string more by one
    Point points[quantPoint];                                    // create points

    cout << "Enter path to data of route:";
    string pathToFile; std::cin >> pathToFile;                  //Take path to *.csv file
    scanLineReading(pathToFile, strArray);

    for(int i = 1; i != quantPoint;i++) {
        cout << strArray[i] << endl;
    }


    return 0;
}
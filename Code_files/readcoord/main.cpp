#include <iostream>			//input, output
#include <string>           //string class
#include <fstream>
#include "SectionPoint.h"	// Header file with Point and Section classes

using namespace std;
int main() {

    int const quantity = 20;                                        //Quantity of point and coordinates
    string readingString[quantity + 1];                            //create array string more by one
    Point points[quantity];                                   // create points

    cout << "Enter absolute path to *.scv file for reading:";
    string readingFilePath; std::cin >> readingFilePath;                  //Take path to *.csv file

    scanLineReading(readingFilePath, readingString);                            //reading *.csv file and convert data to line( string)
    parsingLineToPoint(readingString, points, quantity); //parsing

    cout << "Enter path and name of file:";
    string creatingFilePath; cin >> creatingFilePath;
    Section sections[quantity - 1];

    //transfer point values to section
    for(int i = 0; i != quantity - 1; i++) sections[i].setPoints(points[i], points[i + 1]);

    //create file
    ofstream dataFile(creatingFilePath + ".csv");
    dataFile << "#," << "Distance," << "Angle Rot," << "Speed" << std::endl;

    //calculate angle rotate
    for (int i = 0; i != quantity - 2; i++)
        sections[i].setAngleFromNextSection(sections[i + 1]);

    //transfer data to file
    for (int i = 0; i != quantity - 1; i++)
        dataFile << i << "," << sections[i].distance << ","
        << sections[i].angleToRotation << "," << sections[i].speed << std::endl;
    cout << "Your file has been save!";

    return 0;
}
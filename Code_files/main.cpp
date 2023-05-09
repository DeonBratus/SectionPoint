#include <iostream>			//input, output
#include <string>           //string class
#include <fstream>
#include "SectionPoint.h"	// Header file with Point and Section classes

using namespace std;
int main() {

    int quantPoint = 101;                                        //Quantity of point and coordinates
    string strArray[quantPoint + 1];                            //create array string more by one
    Point points[quantPoint];                                   // create points

    cout << "Enter absolute path to *.scv file for reading:";
    string pathToFile; std::cin >> pathToFile;                  //Take path to *.csv file

    FileToLine(pathToFile,strArray);                            //reading *.csv file and convert data to line( string)
    parseLineToPoint(strArray, points,quantPoint); //parsing

    cout << "Enter path and name of file:";
    string pathToCreate; cin >> pathToCreate;
    Section sections[quantPoint-1];
    //transfer point values to section
    for(int i = 0; i !=quantPoint-1; i++) sections[i].setPoints(points[i], points[i + 1]);
    //create file
    ofstream dataFile(pathToCreate + ".csv");
    dataFile << "#," << "Distance," << "Angle Rot," << "Speed" << std::endl;
    //calculate angle rotate
    for (int i = 0; i != quantPoint - 2; i++)
        sections[i].angleNextSection(sections[i+1]);
    //transfer data to file
    for (int i = 0; i != quantPoint; i++)
        dataFile << i << "," << sections[i].distance << ","
        << sections[i].angleToRotation << "," << sections[i].speed << std::endl;
    cout << "Your file has been save!";
    return 0;
}
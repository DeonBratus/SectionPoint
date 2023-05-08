#include <iostream>			//input, output
#include <string>           //string class
#include "SectionPoint.h"	// Header file with Point and Section classes

int main() {
    int quantPoint = 21;                                        //Quantity of point and coordinates
    std::string strArray[quantPoint + 1];                       //create array string more by one
    Point points[quantPoint];                                   // create points

    std::string pathToFile; std::cin >> pathToFile;             //Take path to *.csv file
    FileToLine(pathToFile,strArray);                            //reading *.csv file and convert data to line( string)
    parseLineToPoint(strArray, points,quantPoint); //parsing

    return 0;
}
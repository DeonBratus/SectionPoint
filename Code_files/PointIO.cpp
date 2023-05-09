#include <fstream>
#include <iostream>
#include "SectionPoint.h"
using namespace std;
/*_______________________________________________________________________________________________________________
                                         Create and run files
_______________________________________________________________________________________________________________*/

// function of creating *.scv table with title. return ofstream class
// doesn't work
std::ofstream &createCSV(const std::string& pathAndName) {
    //create scv file
    std::ofstream dataCSV(pathAndName + ".csv");
    //Check of existing file
    if(dataCSV.is_open() == NULL) std::cout << "error" << std::endl;
    // Writing header
    dataCSV << "#," << "Distance," << "Angle Rot," << "Speed" << std::endl;
    //return file
    return  dataCSV;
}

// Run python script in path
std::string runPythonFile(std::string& filePath) {
    std::cout << "Enter path to open python file:";
    filePath = "python " + filePath;
    system(filePath.c_str()); // write to system command of running python script
    return filePath;
}
/*_______________________________________________________________________________________________________________
                            Work with read and convert received data
//_______________________________________________________________________________________________________________*/

// Read data file and convert data to string array
// assign path to *.csv and array of string
void FileToLine(const string& pathToFile,string strArray[]) {
    ifstream readingFile(pathToFile);                                   // open file
    if (!readingFile) {cerr << "Error! File not found!" << std::endl;}      // Check existing
    int numberLine = 0;
    while (std::getline(readingFile, strArray[numberLine]))       //read value and put to array of string
        numberLine++;
    readingFile.close();    //close file
    cout << "Reading and copying files has been completed!" <<endl;
}

// Parsing string format x,y to point X and Y coordinates
void parseLineToPoint(string str[], Point points[], int quantity)
{
    for(int i = 1; i!=quantity; i++) {

        size_t pos = str[i].find(',');                    // find separator ','
        string x_str = str[i].substr(0, pos);       // take substring from 0 position to ','
        *points[i - 1].X = stod(x_str);                 // convert string value to Point.X

        str[i].erase(0, pos + 1);                   // delete all before comma, and space symbol after comma
        pos = str[i].find(',');                          // find next separator ','
        string y_str = str[i].substr(0,pos);        // take substring from 0 position to ',' of new string
        *points[i - 1].Y = stod (y_str);                // convert string value to Point.Y

        cout<< "#" << i-1 <<"\tX: " << *points[i - 1].X << "\tY: " << *points[i - 1].Y << endl;
    }
    cout << "Conversion of coordinates to points has been completed!" << endl;
}

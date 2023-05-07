#include <iostream>			//input, output
#include <fstream>          //writing to file
#include "SectionPoint.h"	// Header file with Point and Section classes
#include <string>           //string class

using namespace std;

int main() {

    // Declaring and initializing with console reading of variables
    cout << "Enter coordinates: " << endl;
    int x0, y0, x1, y1, x2, y2;
    cout << "Enter coordinates of first point:";
    cin >> x0 >> y0;
    cout << "Enter coordinates of second point:";
    cin >> x1 >> y1;
    cout << "Enter coordinates of third point:";
    cin >> x2 >> y2;

    const short quantityPoints = 3;     // var quantity Points
    Point p[quantityPoints];            // Creating Points array and define values XY coordinates
    Section s[quantityPoints - 1];      // Creating Sections array one less than the number of points

    //transfer coordinates values to Points
    p[0].setValue(x0, y0);
    p[1].setValue(x1, y1);
    p[2].setValue(x2, y2);
    //transfer points to Section
    s[0].setPoints(p[0], p[1]);  // Assign points p[0]---p[1]
    s[1].setPoints(p[1], p[2]);  // Assign points p[1]---p[2]
    // Set rotation angle with next section
    s[0].angleNextSection(s[1]);
/*_____________________________________________________________________________
                            Writing to file code
 _____________________________________________________________________________*/
    string pathToMakedFile; // string and name of *.scv file
    cout<<"Enter path of file" << endl << "Path: ";
    cin >> pathToMakedFile;

    ofstream dataFile = createCSV(pathToMakedFile); //create and write title of *.scv file

    int numString = 0; // Number string values
    float totalDistance = 0;

    // Writing values to *.csv file, like a table, ',' is separator
    for (Section & i : s) {
        dataFile << numString++ << "," << i.distance << "," << i.angleToRotation << "," << i.speed << std::endl;
        totalDistance+=(float)i.distance;
    }
    // total information
    cout << "Writing complete!" << std::endl;
    cout << "Total distance " << totalDistance <<endl;

    int StopValue;
    cin >> StopValue;

    return 0;
}
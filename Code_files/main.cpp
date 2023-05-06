#include <iostream>			//input, output
#include <fstream>
#include "SectionPoint.h"	// Header file with Point and Section classes
#include <string>

using namespace std;
int main() {

    const short quantityPoints = 3;

    Point p[quantityPoints];        // Creating Points array and define values XY coordinates
    Section s[quantityPoints - 1];  // Creating Sections array one less than the number of points

    // Declaring and initializing with console reading of variables
    cout << "Write your coordinates: " << endl;
    int x0, y0, x1, y1, x2, y2;
    cout << "Zero point:";
    cin >> x0 >> y0;
    cout << "1st point:";
    cin >> x1 >> y1;
    cout << "2nd point:";
    cin >> x2 >> y2;

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
    string pathToMakedFile;
    cout<<"Set path to save file" << endl << "Path: ";
    cin >> pathToMakedFile;

    //Making file *.csv
    ofstream dataFile(pathToMakedFile+".csv");
    if(dataFile.is_open() == NULL) cout <<"error"<<endl;
    // Writing header
    dataFile <<"#," << "Distance," << "Angle Rot," <<  "Speed" << std::endl;

    int numString = 0; // Number string values
    float totalDistance = 0;

    // Writing values to *.csv file, like a table, ',' is separator
    for (Section & i : s) {
        i.speed = 0.5f;
        dataFile << numString++ << "," << i.distance << "," << i.angleToRotation << "," << i.speed << std::endl;
        totalDistance+=(float)i.distance;
    }

    cout << "Writing complete!" << std::endl;
    cout << "Initial Point " << "x:" << *p[0].X << " y:" << *p[0].Y << endl;
    cout << "Final Point " << "x:" << *p[quantityPoints-1].X << " y:" << *p[quantityPoints-1].Y << std::endl;
    cout << "Total distance " << totalDistance <<endl;

    int StopValue;
    cin >> StopValue;
    return 0;
}
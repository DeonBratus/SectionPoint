#include <iostream>			//input, output
#include <fstream>
#include "SectionPoint.h"	// Header file with Point and Section classes

int main() {

    const short quantityPoints = 3;

    Point p[quantityPoints];        // Creating Points array and define values XY coordinates
    Section s[quantityPoints - 1];  // Creating Sections array one less than the number of points

    // Declaring and initializing with console reading of variables
    int x0, y0, x1, y1, x2, y2;
    std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

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

    //Making file *.csv
    std::ofstream dataFile("data.csv");

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

    std::cout << "Writing complete!" << std::endl;
    std::cout << "Total distance " << totalDistance << std::endl;
    std::cout << "Initial Point " << "x:" << *p[0].X << " y:" << *p[0].Y << std::endl;
    std::cout << "Final Point " << "x:" << *p[quantityPoints-1].X << " y:" << *p[quantityPoints-1].Y << std::endl;
    return 0;
}
#include <iostream>			//Library of input and output
#include "SectionPoint.h"	// Header file with Point and Section classes

int main() {

    const short quantityPoints = 3;

    // Creating Points array and define values XY coordinates
    Point p[quantityPoints];

    // Creating Sections array one less than the number of points
    Section s[quantityPoints - 1];

    // declaring and initializing with console reading of variables
    int x0, y0, x1, y1, x2, y2;
    std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

    //Initialization of angle with Next Section
    p[0].setValue(x0, y0);
    p[1].setValue(x1, y1);
    p[2].setValue(x2, y2);

    s[0].setPoints(p[0], p[1]);  // Assign points p[0]---p[1]
    s[1].setPoints(p[1], p[2]);  // Assign points p[1]---p[2]

    s[0].angleNextSection(s[1]);
    //Output values disatance and rotation angle
    std::cout << "Distance\t" << s[0].distance << std::endl << "Rotate angle\t" << s[0].angleToRotation << std::endl;

    return 0;
}
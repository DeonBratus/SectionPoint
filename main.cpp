#include <iostream>			//Library of input and output
#include "SectionPoint.h"	// Header file with Point and Section classes

int main() {
    const short quantyPoints = 3;
    // Creating Points array and define values XY coordinates
    Point p[quantyPoints];
    p[0].setValue(0, 0);		// X = 0, Y = 0
    p[1].setValue(2, 2);		// X = 2, Y = 2
    p[2].setValue(7, 5);		// X = 7, X = 5

    // Creating Sections array one less than the number of points
    Section s[quantyPoints - 1];
    s[0].setPoints(p[0], p[1]);  // Assign points p[0]---p[1]
    s[1].setPoints(p[1], p[2]);  // Assign points p[1]---p[2]

    //Initialization of angle with Next Section
    s[0].angleNextSection(s[1]);

    //Output values disatance and rotation angle
    std::cout << "Distance\t" << s[0].distance << std::endl << "Rotate angle\t" << s[0].angleToRotation;

    return 0;
}
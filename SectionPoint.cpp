#include <iostream>
#include "SectionPoint.h"

using namespace std;

/*____________________________________________________________________________________________________________
	Methods and parameter of point class. Point includies two parameters, it's X and Y coordinates			  
______________________________________________________________________________________________________________*/
	void Point::setValue(double x, double y) {	// Setting values x,y to field's values of class 
		this->X = new double(x);
		this->Y = new double(y);
	}

	void Point::ConsolePrintValues() {			// Useful methods of printing values X and Y to console
		std::cout << "X = " << *this->X << "\tY = " << *this->Y << std::endl;
	}
	// Coordinate of point
	double* X; 
	double* Y;

/*______________________________________________________________________________________________________________
	Methods and parameters of Section class. 
	Section includies two Point object, computing distances and angles
	Rotation angle must be calculated out of the class, and last section doesn't have it
________________________________________________________________________________________________________________*/

	float Section::anglePrevSection(Section previousSection) {			// Method calculating angle to Rotation with previous section angle
		angleToRotation = previousSection.angle - this->angle;
		return angleToRotation;
	}

	float Section::angleNextSection(Section nextSection) {				// Method calculating angle to Rotation with next section angle
		angleToRotation = nextSection.angle - this->angle;
		return angleToRotation;
	}

	void Section::setPoints(Point init, Point fin) {					// Method for setting point values, X and Y. And setting values Distance and Angle
		AngleAndDistanceComputing(init, fin);
		p0.X = init.X;
		p0.Y = init.Y;
		p1.Y = fin.Y;
		p1.X = fin.X;
	}
	void Section::AngleAndDistanceComputing(Point init, Point fin) {	//Calculating tangens, angels and distance with coordinates X and Y of two Points objects
		this->tg = (*fin.Y - *init.Y) / (*fin.X - *init.X);
		angle = atan(tg) * 57.29577;
		this->distance = sqrt(pow((*init.X - *fin.X), 2) + pow((*init.Y - *fin.Y), 2));
	}

	// Public 
	double distance;		// Distance from Point to Point
	double angleToRotation; // Angle of Rotation, delta angeles
	double angle;			// angle by X axis
	float speed;			// speed of movement of section

	// Private
	Point p0;				// Initial point
	Point p1;				// Final point
	float tg;				// tangens of angle
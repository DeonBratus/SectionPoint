/*
* Header file of "Section" and "Point" classes
* 
* Point consits of two coordinates - X and Y
* 
* Section consist of two Points and has some parameters
* 
* This is Distance of section, angle by axis X, 
* angle to rotion(delta of two Section), and speed on a Section 
*/
#ifndef SECTION_POINTS
#define SECTION_POINTS
class Point {
public:
	Point(double x = 0, double y = 0)
		: X(new double(x)), Y(new double(y)){}

	void setValue(double x, double y);// Setting values x,y to field's values of class 

	void ConsolePrintValues(); // Useful methods of printing values X and Y to console

	// Coordinate of point
	double* X;
	double* Y;
	
};
class Section {

public:

	Section() // Default constructor with zeros values
		: p0(Point(0, 0)), p1(Point(0, 0)), tg(0), angle(0), distance(0) 
	{}

	Section(Point initialPoint, Point finalPoint = Point(0, 0)) // Constructor with two Point objects as arguments 
		: p0(initialPoint), p1(finalPoint)
	{ AngleAndDistanceComputing(initialPoint, finalPoint); }


	float anglePrevSection(Section previousSection);			// Method calculating angle to Rotation with previous section angle

	float angleNextSection(Section nextSection);				// Method calculating angle to Rotation with next section angle

	void setPoints(Point init, Point fin);						// Method for setting point values, X and Y. And setting values Distance and Angle


	double distance;		// Distance from Point to Point
	double angleToRotation; // Angle of Rotation, delta angeles
	double angle;			// angle by X axis
	float speed;			// speed of movement of section

private:

	void AngleAndDistanceComputing(Point init, Point fin);		//Calculating tangens, angels and distance with coordinates X and Y of two Points objects

	int numberPoint;
	Point p0;
	Point p1;
	float tg;

};
#endif // SECTION_POINTS

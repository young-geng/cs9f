#ifndef POSITIONS_H
#define POSITIONS_H

#include <iostream>


class Position {
public:
	// Initialize a position.  It consists of a radius expressed in meters
	// and an angle expressed in radians.
	Position ();                // r = 1, angle = 0.
	Position (float r);         // angle = 0.
	Position (float r, float thetaInRadians);

	// Reinitialize this position.
	void SetAbsolutePosition (float r, float thetaInRadians);

	// Change this position, incrementing the radius by rChange
	// and incrementing the angle by thetaChange (expressed in radians).
	// One of the two arguments must be 0.
	// Negative radius values represent movement toward the 
	// statue. Positive distance changes represent 
	// counterclockwise motion; negative values are clockwise.
	void IncrementPosition (float rChange, float thetaChange);

	void IncrementPosition2 (float rChange, float angularDisplacement);

	// Compare two positions.
	bool operator== (Position coords);

	// Print this position.
	void Print ();
	friend std::ostream& operator<< (std::ostream &out, const Position &pos);

	// Return true if someone at this position can see someone 
	// or something at the argument position (i.e. the statue 
	// does not block one's view), and return false otherwise.
	// The argument position must be at the statue.
	bool Sees (Position pos);

	// Return true if this position is at the base of the statue,
	// i.e. its radius is 1, and return false otherwise.
	bool IsAtStatue ();

	// Return true if this position is between the first argument
	// position and the second.  Precondition: the difference 
	// between the first and second argument positions is less 
	// than pi radians, and the radii of all the positions 
	// are the same.
	bool IsBetween (Position old, Position current);

private:
	float myRadius;
	float myAngleInRadians;
	void Normalize();
	float NormalizeAngle(float angle);
};


std::ostream& operator<< (std::ostream &out, const Position &pos);


#endif


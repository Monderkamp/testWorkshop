#include "LineSegment.hpp"
#include <iostream>

LineSegment::LineSegment(Vector3D R_, double PHI_,double L_) {
	u.x = cos(PHI_);
	u.y = sin(PHI_);
	u.z = 0.;
	L = L_;

	change_position(R_);

}


void LineSegment::change_position(Vector3D R_) {
	r = R_;

	plusEnd.x = r.x + 0.5*L*u.x;
	plusEnd.y = r.y + 0.5*L*u.y;
	plusEnd.z = r.z + 0.5*L*u.z;

	minusEnd.x = r.x - 0.5*L*u.x;
	minusEnd.y = r.y - 0.5*L*u.y;
	minusEnd.z = r.z - 0.5*L*u.z;

}

double LineSegment::positionDistance(LineSegment& otherLineSegment_) {
	Vector3D dist = otherLineSegment_.r - this->r;
	return dist.norm();
}

bool LineSegment::intersect(LineSegment& otherLineSegment_) {

	return ((plusEnd-minusEnd).cross(otherLineSegment_.minusEnd - minusEnd).dot((plusEnd-minusEnd).cross(otherLineSegment_.plusEnd - minusEnd)) < 0.) 
	&& ((otherLineSegment_.plusEnd-otherLineSegment_.minusEnd).cross(minusEnd-otherLineSegment_.minusEnd).dot((otherLineSegment_.plusEnd-otherLineSegment_.minusEnd).cross(plusEnd-otherLineSegment_.minusEnd)) < 0.);
}
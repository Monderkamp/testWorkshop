#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <array>
#include <cmath>

class Vector3D {
	public:
		double x, y, z;
		
		Vector3D() : x(0.), y(0.), z(0.) {}
		Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
		~Vector3D() {}


		// Assignment operator
    	Vector3D& operator=(const Vector3D& other) {
        // Self-assignment detection
        if (this == &other)
            return *this;

        // Copy data
        x = other.x;
        y = other.y;
        z = other.z;

        // Return the existing object so we can chain this operator
        return *this;
    	}

		bool operator==(const Vector3D& other) const {
				return x == other.x && y == other.y && z == other.z;
			}


		// Vector subtraction
		Vector3D operator-(const Vector3D& p) const {
			return Vector3D(x - p.x, y - p.y, z - p.z);
		}

		// Vector addition
		Vector3D operator+(const Vector3D& p) const {
			return Vector3D(x + p.x, y + p.y, z + p.z);
		}

		// Dot product
		double dot(const Vector3D& p) const {
			return x * p.x + y * p.y + z * p.z;
		}

		// Scalar multiplication
		Vector3D operator*(double scalar) const {
			return Vector3D(x * scalar, y * scalar, z * scalar);
		}


		// Cross product
		Vector3D cross(const Vector3D& p) const {
			return Vector3D(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
		}

		// Squared magnitude of vector
		double norm2() const {
			return x * x + y * y + z * z;
		}

		// Magnitude of vector
		double norm() const {
			return sqrt(norm2());
		}
};


class LineSegment
	{
		public:
		
		//constructors, destructors
		LineSegment();

		LineSegment(Vector3D R_, double PHI_,double L_);
		~LineSegment(){};

		void change_position(Vector3D R_); 

		double positionDistance(LineSegment& otherLineSegment_);
		bool overlap(LineSegment& otherLineSegment_);

		private:
		double L;
		Vector3D r ,u , plusEnd, minusEnd;
	};
	
#endif

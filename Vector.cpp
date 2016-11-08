#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#pragma warning(disable:4996)
using namespace std;
const double PI = 2.0 * acos(0.0);
struct Vector{
	double x, y;
	explicit Vector(double x_ = 0, double y_ = 0) :x(x_), y(y_){}

	bool operator == (Vector& rhs){
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (Vector& rhs){
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	Vector operator + (Vector& rhs){
		return Vector(x + rhs.x, y + rhs.y);
	}
	Vector operator - (Vector& rhs){
		return Vector(x - rhs.x, y - rhs.y);
	}
	Vector operator * (double rhs){
		return Vector(x*rhs, y*rhs);
	}
	double norm() const{ return hypot(x, y); }
	Vector normalize(){
		return Vector(x / norm(), y / norm());
	}
	double polor() const{
		return fmod(atan2(y, x) + 2 * PI, PI);
	}
	double dot(Vector& rhs){
		return x*rhs.x + y*rhs.y;
	}
	double cross(Vector& rhs){
		return x*rhs.y - y*rhs.x;
	}
	Vector project(Vector& rhs){
		Vector r = rhs.normalize();
		return r*r.dot(*this);
	}
};

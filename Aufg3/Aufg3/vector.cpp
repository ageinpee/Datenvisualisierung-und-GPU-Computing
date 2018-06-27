#include "vector.h"
#include <math.h>

Vector gen_vector(double xpos, double ypos, double xres, double yres);

VectorField::VectorField(double xres, double yres) {
	this->xres = xres;
	this->yres = yres;
}

Vector VectorField::vector_at(double xpos, double ypos) const {
	auto v = gen_vector(xpos, ypos, this->xres, this->yres);
	return v;
}

Vector VectorField::vector_at(Vector pos) const {
	return this->vector_at(pos.x, pos.y);
}

Vector::Vector(double x, double y) {
	this->x = x;
	this->y = y;
}

double Vector::abs() const {
	return sqrt(this->x * this->x + this->y * this->y);
}

Vector Vector::with_len(double len) const {
	return this->normalize() * len;
}

Vector Vector::normalize() const {
	return Vector(this->x / this->abs(), this->y / this->abs());
}

Vector Vector::operator+(const Vector& rhs) const {
	return Vector(this->x + rhs.x, this->y + rhs.y);
}

Vector Vector::operator*(double factor) const {
	return Vector(this->x * factor, this->y * factor);
}

Vector Vector::operator/(double divisor) const {
	return Vector(this->x / divisor, this->y / divisor);
}

Vector Vector::operator-(const Vector& rhs) const {
	return Vector(this->x - rhs.x, this->y - rhs.y);
}

Vector gen_vector(double xpos, double ypos, double xres, double yres) {
	Vector v1 = Vector(-(ypos - (0.25*yres)), xpos - (0.2 * xres));
	Vector v2 = Vector(ypos - (0.625 * yres), -(xpos - (0.7*xres)));
	Vector vf = (v1 / pow(v1.abs(), 2.0)) + (v2 / pow(v2.abs(), 2.0));
	return vf / vf.abs();
}
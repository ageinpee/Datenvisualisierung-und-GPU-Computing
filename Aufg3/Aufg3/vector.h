#pragma once
#ifndef VECTOR_H
#define VECTOR_H

class Vector {
	public:
		double x;
		double y;

		Vector(double x, double y);
		double abs() const;
		Vector with_len(double len) const;
		Vector normalize() const;
		Vector operator+(const Vector& rhs) const;
		Vector operator-(const Vector& rhs) const;
		Vector operator*(double fac) const;
		Vector operator/(double div) const;
		Vector gen_vector(double xpos, double ypos, double xres, double yres);
};

class VectorField {
	private:
		double xres;
		double yres;

	public:
		VectorField(double xres, double yres);
		Vector vector_at(double x, double y) const;
		Vector vector_at(Vector pos) const;
};

#endif

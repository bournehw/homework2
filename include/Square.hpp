#ifndef SQUARE_H
#define SQUARE_H
#include "cinder/gl/gl.h"
#include "Shape.hpp"
#include "homework2App.hpp"

using namespace ci;
using namespace std;

class Square : public Shape {
	public:
		/**
		 *Constructor for Square class.
		 */
		Square(int cornerX, int CornerY, int size, Color8u color);
		/**
		 *Copy Constructor for Square class
		 */
		Square(Square* s);
		/**
		 *Draws the square which calls it on the surface in pixels
		 */
		virtual void draw(uint8_t* pixels);
		/**
		 *Draws the square which calls it on the surface in pixels with
		 *a border of the given color
		 */
		virtual void draw(uint8_t* pixels, Color8u borderColor);
		/**
		 *Returns true if the given coordinates are inside the square
		 *which calls it
		 */
		virtual bool isInside(int x, int y);
};
#endif
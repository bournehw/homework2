#ifndef SHAPE_H
#define SHAPE_H
#include "cinder/gl/gl.h"

using namespace ci;
using namespace std;

class Shape{
	public:
		/**
		 *Constructor for Shape class.
		 */
		Shape(int x, int y, int size, Color8u color);

		/**
		 *Copy Constructor for Shape class
		 */
		Shape(Shape* s);

		/**
		 *Draws the shape which calls it on the surface in pixels
		 */
		virtual void draw(uint8_t* pixels);

		/**
		 *Draws the shape which calls it on the surface in pixels with
		 *a border of the given color
		 */
		virtual void draw(uint8_t* pixels, Color8u borderColor);
		/**
		 *Returns true if the given coordinates are inside the shape
		 *which calls it
		 */
		virtual bool isInside(int x, int y);
		/**
		 *Sets the Shape's coordinates to be the given coordinates.
		 */
		void move(int x, int y);

		Color8u color_;
		int size_, x_, y_;
};
#endif
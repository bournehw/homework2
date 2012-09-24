#ifndef SHAPE_H
#define SHAPE_H
#include "cinder/gl/gl.h"

using namespace ci;
using namespace std;

class Shape{
	public:
		Shape(int x, int y, int size, Color8u color);
		Shape(Shape* s);
		virtual void draw(uint8_t* pixels);
		virtual void draw(uint8_t* pixels, Color8u borderColor);
		virtual bool isInside(int x, int y);
		void move(int x, int y);

		Color8u color_;
		int size_, x_, y_;

	private:
};
#endif
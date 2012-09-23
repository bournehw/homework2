#ifndef SQUARE_H
#define SQUARE_H
#include "cinder/gl/gl.h"
#include "Shape.hpp"
#include "homework2App.hpp"

using namespace ci;
using namespace std;

class Square : public Shape {
	public:
		Square(int cornerX, int CornerY, int size, Color8u color);
		Square(Square* s);
		virtual void draw(uint8_t* pixels);
		virtual void draw(uint8_t* pixels, Color8u borderColor);
		virtual bool isInside(int x, int y);
};
#endif
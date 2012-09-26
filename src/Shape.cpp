#include "Shape.hpp"

/**
*Constructor for Shape class.
*/
Shape::Shape(int x, int y, int size, Color8u color){
	size_ = size;
	color_ = color;
	x_ = x;
	y_ = y;
}

/**
*Copy Constructor for Shape class
*/
Shape::Shape(Shape* s){
	size_ = s->size_;
	color_ = s->color_;
	x_ = s->x_;
	y_ = s->y_;
}

/**
*Draws the shape which calls it on the surface in pixels
*/
void Shape::draw(uint8_t* pixels){
}

/**
*Draws the shape which calls it on the surface in pixels with
*a border of the given color
*/
void Shape::draw(uint8_t* pixels, Color8u borderColor){
}

/**
*Returns true if the given coordinates are inside the shape
*which calls it
*/
bool Shape::isInside(int x, int y){
	return false;
}

/**
*Sets the Shape's coordinates to be the given coordinates.
*/
void Shape::move(int x,int y){
	x_ = x;
	y_ = y;
}
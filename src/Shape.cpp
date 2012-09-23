#include "Shape.hpp"

Shape::Shape(int x, int y, int size, Color8u color){
	size_ = size;
	color_ = color;
	x_ = x;
	y_ = y;
}

Shape::Shape(Shape* s){
	size_ = s->size_;
	color_ = s->color_;
	x_ = s->x_;
	y_ = s->y_;
}



void Shape::draw(uint8_t* pixels){
}

void Shape::draw(uint8_t* pixels, Color8u borderColor){
}

bool Shape::isInside(int x, int y){
	return false;
}
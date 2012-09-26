#include "Square.hpp"

/**
*Constructor for Square class.
*/
Square::Square(int cornerX, int cornerY, int size, Color8u color)
:Shape(cornerX,cornerY,size,color){
}

/**
*Copy Constructor for Square class
*/
Square::Square(Square* s):Shape(s){
}

/**
*Draws the square which calls it on the surface in pixels
*/
void Square::draw(uint8_t* pixels){	
	if(size_<=0) return;

	for(int y=y_;y<=y_+size_; y++){
		for(int x=x_; x<=x_+size_; x++){
			if(y < 0 || x < 0 || x >= APP_WIDTH || y >= APP_HEIGHT) continue;
			pixels[3*(x + y*TEXTURE_SIZE)] = color_.r;
			pixels[3*(x + y*TEXTURE_SIZE)+1] = color_.g;
			pixels[3*(x + y*TEXTURE_SIZE)+2] = color_.b;
		}
	}
}

/**
*Draws the square which calls it on the surface in pixels with
*a border of the given color
*/
void Square::draw(uint8_t* pixels, Color8u borderColor){
	if(size_<=0) return;

	for(int y=y_;y<=y_+size_; y++){
		for(int x=x_; x<=x_+size_; x++){
			if(y < 0 || x < 0 || x >= APP_WIDTH || y >= APP_HEIGHT) continue;

			if(y>=y_ && y<y_+2 || y<=y_+size_ && y>y_+size_-2
				|| x>=x_ && x<x_+2 || x<=x_+size_ && x>x_+size_-2){
				pixels[3*(x + y*TEXTURE_SIZE)] = borderColor.r;
				pixels[3*(x + y*TEXTURE_SIZE)+1] = borderColor.g;
				pixels[3*(x + y*TEXTURE_SIZE)+2] = borderColor.b;
			}else{
				pixels[3*(x + y*TEXTURE_SIZE)] = color_.r;
				pixels[3*(x + y*TEXTURE_SIZE)+1] = color_.g;
				pixels[3*(x + y*TEXTURE_SIZE)+2] = color_.b;
			}
		}
	}
}

/**
*Returns true if the given coordinates are inside the square
*which calls it
*/
bool Square::isInside(int x, int y){
	return (y>y_ && y<y_+size_ && x>x_ && x<x_+size_);
}
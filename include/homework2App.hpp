#ifndef HOMEWORK2APP_H
#define HOMEWORK2APP_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Text.h"
#include <algorithm>
#include "ListNode.hpp"
#include "Shape.hpp"
#include "Square.hpp"


#define APP_HEIGHT 600
#define APP_WIDTH 800
#define TEXTURE_SIZE 1024
#define NUM_SHAPES 30

using namespace ci;
using namespace ci::app;
using namespace std;

class homework2App : public AppBasic {
public:
	void setup();
	void mouseDown(MouseEvent event);	
	void mouseDrag(MouseEvent event);
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	void generateShapes();

private:
	Surface* surface_;
	ListNode* headNode_;
	ListNode* selectedNode_;
	bool helpDisplayFlag_;
	Shape* prevShape_;
	uint8_t clearSurface_[3*TEXTURE_SIZE*TEXTURE_SIZE];
};
#endif
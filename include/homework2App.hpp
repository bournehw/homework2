/**
* @file homework2App.hpp
* CSE 274 - Fall 2012
*
* @author Harrison Bourne
* @date 2012-09-23
*
* @note This project satisfies goals A (linked-list), 
* C (re-order items with mouse), D (items can be moved with mouse),
* E (reverse the order of the list by pressin r), F (move a whole 
* range of items), I (make objects contain other objects (drag one 
* objec to another wile holding shift))
* 
*/

#ifndef HOMEWORK2APP_H
#define HOMEWORK2APP_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/Text.h"
#include <algorithm>
/**
 *Linked-list class
 *
 *This satisfies the "linked-list" requirement, goal A
 */
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
	/**
	 *This function contains the code which allows items to be
	 *reordered. Clicking (left click) on an item brings it to
	 *the front of the linked-list.
	 *
	 *This satisfies the "item re-ordering" requirement, goal C
	 */
	void mouseDown(MouseEvent event);
	/**
	 *This function contains the code which allows items to be 
	 *grouped (contain each other) and considered one item. 
	 *Releasing an item you are dragging over another item (while
	 *holding shift) makes the first item the second item's child.
	 *This means that the first item can no longer be interacted with
	 *and that moving or reordering the second item will cause the
	 *same to happen to the first item. Any number of items can be 
	 *made children of an item, but if you make an item with a child 
	 *a child that items child will disappear.
	 *
	 *This satisfies the "move range of items" requirement, goal F
	 *and the "objects can contain objects" requirement, goal I
	 */
	void mouseUp(MouseEvent event);
	/**
	 *This function contains the code which allows items to be 
	 *dragged arround the screen by clicking and dragging the item 
	 *with the left mouse button.
	 *
	 *This satisfies the "move items" requirement, goal D
	 */
	void mouseDrag(MouseEvent event);
	/**
	 *This function contains the code which reverses the order of the 
	 *entire linked-list when the user presses the R key (without 
	 *Caps Lock or Shift keys pressed).
	 *
	 *This satisfies the "reverse the order" requirement, goal E
	 */
	void keyDown(KeyEvent event);
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
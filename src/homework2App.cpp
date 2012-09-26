#include "homework2App.hpp"

void homework2App::setup()
{
	surface_ = new Surface(TEXTURE_SIZE,TEXTURE_SIZE,false);
	uint8_t* pixels  = (*surface_).getData();
	memcpy(clearSurface_,pixels,3*TEXTURE_SIZE*TEXTURE_SIZE);

	generateShapes();
}

void homework2App::prepareSettings(Settings* settings){
	(*settings).setWindowSize(APP_WIDTH,APP_HEIGHT);
	(*settings).setResizable(false);
}

/**
*This function contians the code which allows items to be
*reordered. Clicking (left click) on an item brings it to
*the front of the linked-list.
*
*This satisfies the "item re-ordering" requirment, goal C
*/
void homework2App::mouseDown(MouseEvent event){
	bool isOnShape = false;

	if(event.isLeftDown()){
		ListNode* currentNode = headNode_;
		do{
			if(currentNode->shape_->isInside(event.getX(),event.getY())){
				selectedNode_ = currentNode;
				selectedNode_ = selectedNode_->removeNode();
				headNode_->previous_->addAfter(selectedNode_);
				isOnShape = true;
				break;
			}
			currentNode = currentNode->previous_;
		}while(currentNode!=headNode_);

		if(!isOnShape)
			selectedNode_ = NULL;
	}
}

/**
*This function contains the code which allows items to be 
*grouped (contain each other) and considered one item. 
*Releasing an item you are dragging over another item (while
*holding shift) makes the first item the second items child.
*This means that the first item can nolonger be iteracted with
*and that moving or reordering the second item will cause the
*same to happen to the first item. Any number of items can be 
*made children of an item but if you make an item with a child 
*a child that items child will disapear.
*
*This satisfies the "move range of items" requirement, goal F
*and the "ojects can contain objects" requirement, goal I
*/
void homework2App::mouseUp(MouseEvent event){
	if(event.isShiftDown()&&event.isLeft()&&selectedNode_!=NULL){
		ListNode* currentNode = headNode_;

		do{
			if(currentNode->shape_->
				isInside(selectedNode_->shape_->x_,
				selectedNode_->shape_->y_))
			{
				selectedNode_ = selectedNode_->removeNode();
				currentNode->addChild(selectedNode_);
				selectedNode_ = NULL;
				break;
			}
			currentNode = currentNode->next_;
		}while(currentNode!=headNode_);
	}
}

/**
*This function contains the code which allows items to be 
*dragged arround the screen by clicking and dragging the item 
*with the left mouse button.
*
*This satisfies the "move items" requirement, goal D
*/
void homework2App::mouseDrag(MouseEvent event){
	int mouseX = event.getX();
	int mouseY = event.getY();
	if(event.isLeftDown()&&selectedNode_!=NULL){
		if(selectedNode_->childrenHead_!=NULL){
			ListNode* currentChild = selectedNode_->childrenHead_;
			int diffX = mouseX-selectedNode_->shape_->x_;
			int diffY = mouseY-selectedNode_->shape_->y_;
			int childX, childY;
			do{
				childX = currentChild->shape_->x_;
				childY = currentChild->shape_->y_;
				currentChild->shape_->move(childX+diffX,childY+diffY);
				currentChild = currentChild->next_;
			}while(currentChild!=selectedNode_->childrenHead_);
		}
		selectedNode_->shape_->move(mouseX,mouseY);
	}
}

/** This function contains the doe which reverses the order of the 
*entire linked-list when the user presses the R key (without 
*Caps Lock or Shift keys pressed).
*
*This satisfies the "reverse the order" requirement, goal E
*/
void homework2App::keyDown(KeyEvent event){
	if(event.getChar()=='r'){
		headNode_->reverseNodeOrder(headNode_);
	}
}
	
void homework2App::generateShapes(){
	ListNode* currentNode;
	Color8u color;
	Shape* s;

	srand(time(NULL));
	color =  Color8u(rand()%255,rand()%255,rand()%255);
	s = new Square(100,100,rand()%100,color);
	headNode_ = new ListNode(s);
	currentNode = headNode_;
	
	for(int iShape=0; iShape<NUM_SHAPES; ++iShape){
		color =  Color8u(255*rand(),255*rand(),255*rand());
		s = new Square(rand()%780,rand()%580,rand()%100+20,color);
		currentNode->addAfter(new ListNode(s));
		currentNode = currentNode->next_;
	}
}

void homework2App::update(){
	uint8_t* pixles = surface_->getData();
	memcpy(pixles,clearSurface_,3*TEXTURE_SIZE*TEXTURE_SIZE);

	ListNode* currentNode = headNode_;

	do{
		if(currentNode->childrenHead_!=NULL){
			ListNode* currentChild = currentNode->childrenHead_;
			do{
				currentChild->shape_->draw(pixles);
				currentChild = currentChild->next_;
			}while(currentChild!=currentNode->childrenHead_);
		}

		currentNode->shape_->draw(pixles);
		currentNode = currentNode->next_;
	}while(currentNode!=headNode_);
}

void homework2App::draw()
{
	gl::draw(*surface_);	
}

CINDER_APP_BASIC( homework2App, RendererGl )

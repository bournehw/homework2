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

	uint8_t* pixels = surface_->getData();
	memcpy(pixels,clearSurface_,3*TEXTURE_SIZE*TEXTURE_SIZE);

	ListNode* currentNode = headNode_;

	do{
		if(currentNode->childrenHead_!=NULL){
			ListNode* currentChild = currentNode->childrenHead_;
			do{
				currentChild->shape_->draw(pixels);
				currentChild = currentChild->next_;
			}while(currentChild!=currentNode->childrenHead_);
		}

		currentNode->shape_->draw(pixels);
		currentNode = currentNode->next_;
	}while(currentNode!=headNode_);
}

void homework2App::draw()
{
	gl::draw(*surface_);	
}

CINDER_APP_BASIC( homework2App, RendererGl )

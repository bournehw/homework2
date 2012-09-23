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

void homework2App::mouseDown(MouseEvent event)
{
	if(event.isLeftDown()){
		ListNode* currentNode = headNode_;
		do{
			if(currentNode->shape_->isInside(event.getX(),event.getY())){
				selectedNode_ = currentNode;
				break;
			}else
				selectedNode_ = 0;
			currentNode = currentNode->next_;
		}while(currentNode!=headNode_);
	}
}

void homework2App::mouseDrag(MouseEvent event){
	int mouseX = event.getX();
	int mouseY = event.getY();
	if(event.isLeftDown()&&selectedNode_!=0){
		selectedNode_->shape_->x_ = mouseX;
		selectedNode_->shape_->y_ = mouseY;
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
		
		if(currentNode==selectedNode_){
			currentNode->shape_->draw(pixles, Color8u(255,255,255));
		}else
			currentNode->shape_->draw(pixles);

		currentNode = currentNode->next_;
	}while(currentNode!=headNode_);
}

void homework2App::draw()
{
	gl::clear(Color(1.0f,1.0f,1.0f));
	gl::draw(*surface_);	
}

CINDER_APP_BASIC( homework2App, RendererGl )

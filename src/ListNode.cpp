#include "ListNode.hpp"

/**
*ListNode constructor
*/
ListNode::ListNode(Shape* shape){
	shape_ = shape;
	next_ = this;
	previous_ = this;
	childrenHead_ = NULL;
}

/**
*Adds a node to the linked list after the node that 
*calls the function.
*/
void ListNode::addAfter(ListNode* node2Add){
	node2Add->next_ = next_;
	node2Add->previous_ = this;
	next_->previous_ = node2Add;
	next_ = node2Add;
}

/**
*Removes the calling node and returns a pointer to it
*/
ListNode* ListNode::removeNode(){
	next_->previous_ = previous_;
	previous_->next_ = next_;
	previous_ = this;
	next_ = this;
	return this;
}

/**
*reverses the order of all the nodes in the liked list
*/
void ListNode::reverseNodeOrder(ListNode* headNode){
	ListNode* currentNode = headNode;
	ListNode* temp;
	do{
		temp = currentNode->previous_;
		currentNode->previous_ = currentNode->next_;
		currentNode->next_ = temp;
		currentNode = currentNode->previous_;
	}while(currentNode!=headNode);
}

/**
*Adds a node to the children linked list of the caling node
*/
void ListNode::addChild(ListNode* child){
	if(childrenHead_==NULL){
		childrenHead_ = child;
		childrenHead_->next_ = childrenHead_;
		childrenHead_->previous_ = childrenHead_;
	}else
		childrenHead_->previous_->addAfter(child);
}

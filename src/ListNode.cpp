#include "ListNode.hpp"

ListNode::ListNode(Shape* shape){
	shape_ = shape;
	next_ = this;
	previous_ = this;
	childrenHead_ = NULL;
}

void ListNode::addAfter(ListNode* node2Add){
	node2Add->next_ = next_;
	node2Add->previous_ = this;
	next_->previous_ = node2Add;
	next_ = node2Add;
}

ListNode* ListNode::removeNode(){
	next_->previous_ = previous_;
	previous_->next_ = next_;
	previous_ = this;
	next_ = this;
	return this;
}

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

void ListNode::addChild(ListNode* child){
	if(childrenHead_== NULL){
		childrenHead_ = child;
		childrenHead_->next_ = childrenHead_;
		childrenHead_->previous_ = childrenHead_;
	}else
		childrenHead_->previous_->addAfter(child);
}

#include "ListNode.hpp"

ListNode::ListNode(Shape* shape){
	shape_ = shape;
	next_ = this;
	previous_ = this;
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
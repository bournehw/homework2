#ifndef LISTNODE_H
#define LISTNODE_H
#include "Shape.hpp"
//#include "Square.hpp"

class ListNode{
	public:
		ListNode(Shape* shape);
		ListNode* next_;
		ListNode* previous_;
		Shape* shape_;

		void addAfter(ListNode* node2Add);
		ListNode* removeNode();
};
#endif
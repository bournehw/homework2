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
		ListNode* childrenHead_;

		void addAfter(ListNode* node2Add);
		ListNode* removeNode();
		void reverseNodeOrder(ListNode* headNode);
		void addChild(ListNode* child);
		void removeChild(ListNode* child);
};
#endif
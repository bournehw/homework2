#ifndef LISTNODE_H
#define LISTNODE_H
#include "Shape.hpp"

class ListNode{
public:
	/**
	 *ListNode constructor
	 */
	ListNode(Shape* shape);

	ListNode* next_;
	ListNode* previous_;
	Shape* shape_;
	ListNode* childrenHead_;
	/**
	 *Adds a node to the linked list after the node that 
	 *calls the function.
	 */
	void addAfter(ListNode* node2Add);
	/**
	 *Removes the calling node and returns a pointer to it
	 */
	ListNode* removeNode();
	/**
	 *Reverses the order of all the nodes in the linked list
	 */
	void reverseNodeOrder(ListNode* headNode);
	/**
	 *Adds a node to the children linked list of the calling node
	 */
	void addChild(ListNode* child);
};
#endif
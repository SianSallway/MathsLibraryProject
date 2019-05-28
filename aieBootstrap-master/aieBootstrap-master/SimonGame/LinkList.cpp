#include "LinkList.h"
#include <iostream>

using namespace std;

//returns if the list is empty or not 
bool LinkList::isEmpty() const
{
	return headNode == nullptr;
}

//return the first element by value, assert if no elements 
ListNode* LinkList::First()
{
	return headNode;
}

//return the last element by value, assert if no elements 
ListNode* LinkList::Last()
{
	return tailNode;
}

//adding a node to the start of the list 
void LinkList::PushFront(int value)
{
	ListNode* currentNode = new ListNode(value);
	currentNode->SetNext(headNode);
	headNode = currentNode;

	// was list emoty check?
	if (tailNode == nullptr)
		tailNode = headNode;

	cout << "a value has been added to the front of the list Head Node: " << headNode->GetValue() << endl;
}

//adding a node to the end of the list
void LinkList::PushBack(int value)
{
	ListNode* currentNode = new ListNode(value);
	currentNode->SetNext(nullptr);

	if (tailNode != nullptr)
	{
		tailNode->SetNext(currentNode);
	}

	tailNode = currentNode;

	// was list empty check?
	if (headNode == nullptr)
	{
		headNode = tailNode;

		cout << "a value has been added to the front of the list Head Node: " << headNode->GetValue() << endl;
	}


	cout << "a value has been added to the end of the list Tail Node: " << tailNode->GetValue() << endl;
}

LinkList::LinkList()
{
}


LinkList::~LinkList()
{
}


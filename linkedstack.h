#ifndef LINKED_STACK
#define LINKED_STACK

#include "linkedinterface.h"
#include "node.h"

template<class ItemType>
class LinkedStack : public LinkedInterface<ItemType> {
private:
    Node<ItemType>* topPtr;

public:
    LinkedStack();
    LinkedStack(const LinkedStack<ItemType>& astack);

    ~LinkedStack();

    bool push(const ItemType& newItem);
    bool pop();
    ItemType peek() const;
    bool isEmpty() const;

};

#include "linkedstack.cpp"
#endif

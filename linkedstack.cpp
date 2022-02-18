#include <string>
#include <cassert>

#include "linkedstack.h"
#include "node.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {
}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {

    // Point to nodes in original chain
    Node<ItemType>* origChainPtr = aStack.topPtr;

    if (origChainPtr == nullptr) {
        topPtr = nullptr; // Original stack is empty
    } else {
        // Copy first node
        topPtr = new Node<ItemType>();
        topPtr->setItem(origChainPtr->getItem());
        // Point to first node in new chain
        Node<ItemType>* newChainPtr = topPtr;
        // Advance original-chain pointer
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr) {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();
            // Create a new node containing next item
            Node<ItemType>* newNodePtr = new
            Node<ItemType>(nextItem);
            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    while (!isEmpty()) {
        pop();
    }
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    bool result = false;
    if (!isEmpty()) {
        // Stack is not empty; delete top
        Node<ItemType>* nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();
        // Return deleted node to system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    assert(!isEmpty()); // Enforce precondition @ debugging
    // Stack is not empty; return top
    return topPtr->getItem();
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    return topPtr == nullptr;
}

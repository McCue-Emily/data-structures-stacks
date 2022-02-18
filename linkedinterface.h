#ifndef LINKED_INTERFACE
#define LINKED_INTERFACE

using namespace std;

template<class ItemType>
class LinkedInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const ItemType& newEntry) = 0;
    virtual bool pop() = 0;
    virtual ItemType peek() const = 0;
    virtual ~LinkedInterface() { }

};

#endif

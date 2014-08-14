#include "DoublyLinkedList.h"
#include <stdexcept>
// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};
// copy constructor
DoublyLinkedList::DoublyLinkedList(DoublyLinkedList& dll)                   // This function takes O(n) time
{                                                                           // This is because you must iterate through a list of n elements
  // Initialize the list                                                    // And copy all its elements over to a new list
  header=0;
  trailer=0;
  header.next = &trailer; trailer.prev = &header;
  // Copy from dll
  /* Complete this function */
  DListNode *node = dll.header.next;

  while (node != &dll.trailer) {                                            // This while loop performs n iterations -> O(n) time
      insertLast(node->getElem());                                          // Elements from another list are inserted to the new list -> O(1) time
      node = node->next;                                                    // Element from other list gets its next element -> O(1) time
  } 
  
}
// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(DoublyLinkedList& dll)        // This function takes O(n) time
{                                                                           // This is because you must iterate through a list of n elements from a temp list
  // Delete the whole list                                                  // And copy all its elements over to a new list
  /* Complete this function */
    header=0;
    trailer=0;
    header.next = &trailer; trailer.prev = &header;
    
    DoublyLinkedList temporary(dll);                                        // Temporary list obj created here -> O(1) time
    DListNode *node = temporary.header.next;
    while (node != &temporary.trailer) {                                    // This while loop performs n iterations -> O(n) time
        insertLast(node->getElem());                                        // Elements from temp list are inserted to the new list -> O(1) time
        node = node->next;                                                  // Element from temp list gets its next element -> O(1) time
    }
    return *this;
}
// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{ 
  DListNode *newNode = new DListNode(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}
// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}
// remove the first object of the list
int DoublyLinkedList::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}
// remove the last object of the list
int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}
// destructor
DoublyLinkedList::~DoublyLinkedList()
{
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
// return the first object
int DoublyLinkedList::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->obj;
}
// return the last object
int DoublyLinkedList::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->obj;
}
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll) {
  DListNode *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    current = current->getNext(); //iterate
  }
  return count;
}
// output operator
ostream& operator<<(ostream& out, DoublyLinkedList& dll) {      // The running time of this is O(n)
                                                                // This is because you must traverse the entire list of n elements
  /* Complete this function */
    DListNode *node = dll.getFirst();
    //DListNode *ptr = dll.getAfterLast();
    while (node->getElem() != dll.getAfterLast()->getElem()) {  // A while loop is implemented with a "iterator node" -> O(n) time
        out << node->getElem() << " ";                          // Each node returns its data -> O(1) time
        node = node->getNext();                                 // Each node also retrieves its next node -> O(1) time
    }
  return out;
}

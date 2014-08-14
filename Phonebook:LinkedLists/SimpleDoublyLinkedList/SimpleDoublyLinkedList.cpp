#include <iostream>
using namespace std;

// list node
struct Node {
  int data; // each node holds an integer data
  Node* previous; // pointer to the previous node
  Node* next; // pointer to the next node
  Node(int d=0, Node* prv=NULL, Node* nxt=NULL) : data(d), previous(prv), next(nxt) {}
  Node* get_previous() const { return previous; }
  Node* get_next() const { return next; }
  Node* insert_before(int d); // insert the int before this node
                                // return a pointer to the inserted node
  Node* insert_after(int d); // insert the int after this node
                               // return a pointer to the inserted node
  void delete_before(); // delete the node before this node
  void delete_after(); // delete the node after this node
};

int ct = 0;

// insert the int before this node
// return a pointer to the inserted node
Node* Node::insert_before(int d) {                  // The running time of this function is O(1)
                                                    // During element insertion pointers are re-assigned
  /* Complete this function */
    Node* p = new Node(d);
    previous->next = p;
    p->previous = previous;
    previous = p;
    p->next = this;
    return p;
}
// insert the int after this node
// return a pointer to the inserted node
Node* Node::insert_after(int d) {                   // The running time of this function is O(1)
                                                    // During element insertion pointers are re-assigned
  /* Complete this function */             
    Node* p = new Node(d);
    p->next = next;
    next->previous = p;
    next = p;
    p->previous = this;
    
    return p;
}
// delete the node before this node
void Node::delete_before()                          // The running time of this function is O(1)
{                                                   // Pointers are re-assigned and node is deleted
                                            
  /* Complete this function */
    Node* p = previous;
    p->previous->next = this;
    this->previous = p->previous;

    delete p;
}
// delete the node after this node
void Node::delete_after()                           // The running time of this function is O(1)
{                                                   // Pointers are re-assigned and node is deleted
  
  /* Complete this function */
    Node* p = next;
    p->next->previous = this;
    this->next = p->next;
    
    delete p;
  
}

// Display the doubly linked list
void display_list(Node* header, Node* trailer) {    // The running time of this function is O(n)
  Node* p=header->get_next();                       // Where n is the # of nodes
  //Node* p=header;                                 
  while (p!=trailer) {                              // A while loop is implemented with a "iterator node"
    cout << p->data << ", ";                        // To traverse the list. Each pointer returns its data 
    p=p->get_next();                                // Which takes O(1) time as well as retrieving the next node
  }
  //cout << p->data << ", ";
  cout << endl;
}

// Test program
int main() {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  Node *header = new Node(-1);
  Node *trailer = new Node(-2);
  trailer->previous = header;
  header->next = trailer;
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    trailer->insert_before(i);
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;

  // Insert 10 nodes at front with value 100,90,80,..,10
  cout << "Insert 10 nodes at front with value 100,90,80,..,10" << endl;
  for (int i=10;i<=100;i+=10) {
    header->insert_after(i);
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    trailer->delete_before();
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    header->delete_after();
  }
  cout << "list: ";
  display_list(header,trailer);
  
  return 0;
  
}
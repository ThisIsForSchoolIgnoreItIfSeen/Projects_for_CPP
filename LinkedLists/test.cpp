#include "node.h"

int main() {
  node* head = new node(new student("ab","cd",123,3.3));
  node* a = new node(new student("ef","gh",123,3.3));
  node* b = new node(new student("ij","kl",123,3.3));
  node* c = new node(new student("mn","op",123,3.3));
  head->setNext(a);
  head->setNext(b);
  head->setNext(c);
  head->printAll();
  head->getCertain(2)->getStudent()->display();
  delete head->getCertain(2);
  delete head;
  
  return 0;
}

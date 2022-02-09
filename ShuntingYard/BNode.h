#ifndef BNODE_H
#define BNODE_H

template <class T>
class BNode {
 public:
  //these two are too simple, literally just give you the pointers to the corresponding values
  T getValue();
  BNode<T>* getLeft();
  BNode<T>* getRight();
  //appends a BNode<T> to end of linked list
  void setRight(BNode<T>* n);
  void setLeft(BNode<T>* n);
  //initilizes Nodes with corresponding values
  BNode();
  BNode(T v);
  //destroys value
  ~BNode();
 private:
  T val;
  BNode<T>* left;
  BNode<T>* right;
};

#endif

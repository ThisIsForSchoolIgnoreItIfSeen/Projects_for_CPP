#ifndef BNODE_H
#define BNODE_H

template <class T>
class BNode {
 public:
  //these two are too simple, literally just give you the pointers to the corresponding values
  T getValue();
  BNode<T>* getLeft();
  BNode<T>* getRight();
  //sets right and left nodes
  void setRight(BNode<T>* n);
  void setLeft(BNode<T>* n);
  //adds a bnode to the tree;
  void searchAdd(T n);
  void searchAdd(BNode<T>* n);
  void printr(int sp);
  //initilizes Nodes with corresponding values, cant initilize with left or right
  BNode();
  BNode(T v);
 private:
  T val;
  BNode<T>* left;
  BNode<T>* right;
};

#endif

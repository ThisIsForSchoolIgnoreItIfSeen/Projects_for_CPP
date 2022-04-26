#ifndef BNODE_H
#define BNODE_H

enum colour {
  red,
  black
};

template <class T>
class BNode {
 public:
  colour color;
  T getValue();
  BNode<T>* getLeft();
  BNode<T>* getRight();
  BNode<T>* getParent();
  void setRight(BNode<T>* n);
  void setLeft(BNode<T>* n);
  void setParent(BNode<T>* n);
  void setVal(T n);
  void searchAdd(T n);
  void searchAdd(BNode<T>* n);
  void balance();
  void printr(int sp);
  BNode();
  BNode(T v);
  BNode(T v, colour c);
 private:
  T val;
  BNode<T>* parent;
  BNode<T>* left;
  BNode<T>* right;
};

#endif

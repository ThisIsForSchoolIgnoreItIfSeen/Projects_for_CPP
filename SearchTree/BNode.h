#ifndef BNODE_H
#define BNODE_H

template <class T>
class BNode {
 public:
  T getValue();
  BNode<T>* getLeft();
  BNode<T>* getRight();
  void setRight(BNode<T>* n);
  void setLeft(BNode<T>* n);
  void setVal(T n);
  void searchAdd(T n);
  void searchAdd(BNode<T>* n);
  void printr(int sp);
  BNode();
  BNode(T v);
 private:
  T val;
  BNode<T>* left;
  BNode<T>* right;
};

#endif

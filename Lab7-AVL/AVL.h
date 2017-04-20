#pragma once
#include "AVLInterface.h"
#include "Node.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

class AVL : public AVLInterface {

protected:
  Node* rootNode;
  bool NodeWasAdded = false;
public:
	AVL();
	~AVL();
	NodeInterface* getRootNode() const;
  bool RecursiveAdd(int data, Node*& pntr);
	bool add(int data);
  void ReplaceParent(Node*& oldNode, Node*& newNode);
  bool RecursiveRemove(int data, Node*& pntr);
	bool remove(int data);
	bool RecursiveClear(Node*& pntr);
	void clear();
  void rotate_right(Node*& local_root);
  void rotate_left(Node*& local_root);
  void balance(Node*& local_root);
  int treeHeight(Node*& pntr);
  void balanceAll(Node*& pntr);
};

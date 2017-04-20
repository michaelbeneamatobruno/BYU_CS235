#pragma once
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface {

protected:
  Node* rootNode;
  bool NodeWasAdded = false;
public:
	BST();
	~BST();

  // bool IsDuplicate(int data, Node* pntr);

	NodeInterface * getRootNode() const;

  bool RecursiveAdd(int data, Node*& pntr);

	bool add(int data);

  void ReplaceParent(Node*& oldNode, Node*& newNode);

  bool RecursiveRemove(int data, Node*& pntr);

	bool remove(int data);

	bool RecursiveClear(Node*& pntr);
  
	void clear();
};

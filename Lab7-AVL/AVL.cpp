 #include "AVL.h"

using namespace std;

AVL::AVL() {
  rootNode = NULL;
}
AVL::~AVL() {
  clear();
}
NodeInterface* AVL::getRootNode() const {
  return rootNode;
}
bool AVL::add(int data) {
  return RecursiveAdd(data, rootNode);
}
bool AVL::RecursiveAdd(int data, Node*& pntr) {
  if (pntr == NULL) {
    pntr = new Node(data);
    return true;
  }
  else {
    bool nodeWasAdded = false;
    if (data == pntr->getData()) {
      return false;
    }
    else if (data > pntr->getData()) {
      nodeWasAdded = RecursiveAdd(data, pntr->getRight());
    }
    else if (data < pntr->getData()) {
      nodeWasAdded = RecursiveAdd(data, pntr->getLeft());
    }
    balance(pntr);
    return nodeWasAdded;
  }
  return false;
}
void AVL::ReplaceParent(Node*& oldNode, Node*& newNode) {
  if (newNode->getRight() != NULL) {
    ReplaceParent(oldNode, newNode->getRight());
  }
  else {
    oldNode->setData(newNode->getData());
    oldNode = newNode;
    newNode = newNode->getLeft();
  }
}
bool AVL::RecursiveRemove(int data, Node*& pntr) {
  if (pntr == NULL) {
    return false;
  }
  else {
    bool nodeWasRemoved = false;
    if (data == pntr->getData()) {
      Node* temp = pntr;
      if (pntr->getLeft() == NULL) {
        pntr = pntr->getRight();
      }
      else if (pntr->getRight() == NULL) {
        pntr = pntr->getLeft();
      }
      else {
        ReplaceParent(temp, temp->getLeft());
      }
      delete temp;
      temp = nullptr;
      balanceAll(pntr);
      return true;
    }
    else if (data > pntr->getData()) {
      nodeWasRemoved = RecursiveRemove(data, pntr->getRight());
    }
    else if (data < pntr->getData()) {
      nodeWasRemoved = RecursiveRemove(data, pntr->getLeft());
    }
    balance(pntr);
    return nodeWasRemoved;
  }
}
bool AVL::remove(int data) {
  return RecursiveRemove(data, rootNode);
}
void AVL::clear() {
  while (rootNode != NULL) {
    remove(rootNode->getData());
  }
}
void AVL::rotate_right(Node*& local_root) {
  Node* temp = local_root->getLeft();
  local_root->getLeft() = temp->getRight();
  temp->getRight() = local_root;
  local_root = temp;
}
void AVL::rotate_left(Node*& local_root) {
  Node* temp = local_root->getRight();
  local_root->getRight() = temp->getLeft();
  temp->getLeft() = local_root;
  local_root = temp;
}
void AVL::balance(Node*& pntr) {
  if (pntr == nullptr) {
    return;
  }
  else if (treeHeight(pntr) == 1) {
    cout << "already balanced" << endl;
    return;
  }
  int balanceHeight = treeHeight(pntr->getRight()) - treeHeight(pntr->getLeft());
  if (balanceHeight < -1) {
    if (treeHeight(pntr->getLeft()->getRight()) - treeHeight(pntr->getLeft()->getLeft()) > 0) {
      rotate_left(pntr->getLeft());
    }
    cout << "unbalanced left" << endl;
    rotate_right(pntr);
  }
  else if (balanceHeight > 1) {
    if (treeHeight(pntr->getRight()->getRight()) - treeHeight(pntr->getRight()->getLeft()) < 0) {
      rotate_right(pntr->getRight());
    }
    cout << "unbalanced right" << endl;
    rotate_left(pntr);
  }
}
int AVL::treeHeight(Node*& pntr) {
  if (pntr == nullptr) {
    return 0;
  }
  else if (pntr->getRight() == nullptr && pntr->getLeft() == nullptr) {
    pntr->setHeight(1);
    cout << pntr->getHeight() << endl;
    return pntr->getHeight();
  }
  else if (pntr->getRight() == nullptr) {
    pntr->setHeight(treeHeight(pntr->getLeft()) + 1);
    cout << pntr->getHeight() << endl;
    return pntr->getHeight();
  }
  else if (pntr->getLeft() == nullptr) {
    pntr->setHeight(treeHeight(pntr->getRight()) + 1);
    cout << pntr->getHeight() << endl;
    return pntr->getHeight();
  }
  else {
    pntr->setHeight(max(treeHeight(pntr->getRight()), treeHeight(pntr->getLeft())) + 1);
    cout << pntr->getHeight();
    return pntr->getHeight();
  }
}
void AVL::balanceAll(Node*& pntr) {
  if (pntr == nullptr) {
    return;
  }
  else {
    if (pntr->getLeft() != nullptr) {
      balanceAll(pntr->getLeft());
    }
    if (pntr->getRight() != nullptr) {
      balanceAll(pntr->getRight());
    }
    balance(pntr);
  }
}

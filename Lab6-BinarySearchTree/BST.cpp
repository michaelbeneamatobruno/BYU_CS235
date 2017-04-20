 #include "BST.h"

using namespace std;

BST::BST()
{
  rootNode = NULL;
}
BST::~BST()
{
  clear();
}

// bool BST::IsDuplicate(int data, NodeInterface* pntr)
// {
//   if (data == pntr->getData()) {
//     return true;
//   }
//   else {
//     if (data > pntr->getData()) {
//         if (pntr->getRightChild() == NULL) {
//           return false;
//         }
//         pntr = pntr->getRightChild();
//         if (IsDuplicate(data, pntr)) {
//           return true;
//         }
//     }
//     else if (data < pntr->getData()) {
//       if (pntr->getLeftChild() == NULL) {
//         return false;
//       }
//       pntr = pntr->getLeftChild();
//       if (IsDuplicate(data, pntr)) {
//         return true;
//       }
//     }
//   }
//
//
//
// }

NodeInterface* BST::getRootNode() const
{
  return rootNode;
}

bool BST::add(int data)
{
  return RecursiveAdd(data, rootNode);
}

bool BST::RecursiveAdd(int data, Node*& pntr)
{
  if (pntr == NULL) {
    pntr = new Node(data);
    return true;
  }
  else {
    if (data > pntr->getData()) {
        if (RecursiveAdd(data, pntr->getRight())) {
          return true;
        }
    }
    else if (data < pntr->getData()) {
      if (RecursiveAdd(data, pntr->getLeft())) {
        return true;
      }
    }
    else {
      return false;
    }
  }
  return false;
}

void BST::ReplaceParent(Node*& oldNode, Node*& newNode)
{
  if (newNode->getRight() != NULL) {
    ReplaceParent(oldNode, newNode->getRight());
  }
  else {
    oldNode->setData(newNode->getData());
    oldNode = newNode;
    newNode = newNode->getLeft();
  }
}

bool BST::RecursiveRemove(int data, Node*& pntr)
{
  if (pntr == NULL) {
    return false;
  }
  else {
    if (data > pntr->getData()) {
      return RecursiveRemove(data, pntr->getRight());
    }
    else if (data < pntr->getData()) {
      return RecursiveRemove(data, pntr->getLeft());
    }
    else {
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
      return true;
    }
  }
}

bool BST::remove(int data)
{
  return RecursiveRemove(data, rootNode);
}

// bool BST::RecursiveClear(Node*& pntr)
// {
//   if (pntr == NULL) {
//     return true;
//   }
//   else {
//     if (pntr->getRight() != NULL) {
//       return RecursiveClear(pntr->getRight());
//     }
//     if (pntr->getLeft() != NULL) {
//       return RecursiveClear(pntr->getLeft());
//     }
//     // delete pntr;
//     // pntr = NULL;
//     // return true;
//   }
//   return false;
// }

void BST::clear()
{
  while (rootNode != NULL) {
    remove(rootNode->getData());
  }
}

#include "Node.h"

using namespace std;


Node::Node(int value)
{
 data = value;
 leftChild = NULL;
 rightChild = NULL;
}
Node::~Node(){}

int Node::getData() const
{
 return data;
}

void Node::setData(int newData)
{
  data = newData;
}

NodeInterface* Node::getLeftChild() const
{
 return leftChild;
}

Node*& Node::getLeft()
{
  return leftChild;
}

NodeInterface* Node::getRightChild() const
{
 return rightChild;
}

Node*& Node::getRight()
{
  return rightChild;
}

void Node::setLeftChild(Node* ptr)
{
 leftChild = ptr;
}

void Node::setRightChild(Node* ptr)
{
 rightChild = ptr;
}

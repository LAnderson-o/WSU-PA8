#include "Node.hpp"

Node::Node(std::string newData) {
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node() {
	mpLeft = nullptr;
	mpRight = nullptr;
}

void Node::setData(std::string newData) {
	mData = newData;
}

void Node::setLeft(Node* newNode) {
	mpLeft = newNode;
}

void Node::setRight(Node* newNode) {
	mpRight = newNode;
}

std::string Node::getData() {
	return mData;
}

Node*& Node::getLeft() {
	return mpLeft;
}

Node*& Node::getRight() {
	return mpRight;
}
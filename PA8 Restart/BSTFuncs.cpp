#include "BST.hpp"
BST::BST() {
	mpRoot = nullptr;//new TransactionNode();
}

BST::~BST() {
	destroyTree(mpRoot);
}

void BST::destroyTree(Node* pTree) {
	if (pTree != nullptr) {
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

void BST::insert(TransactionNode newNode) {
	insert(newNode, mpRoot);
}

void BST::insert(TransactionNode newNode, Node*& pTree) {
	if (pTree == nullptr) {
		pTree = new TransactionNode(newNode.getUnits(), newNode.getData());//((TransactionNode*)pTree)->setData(newNode.getUnits(), newNode.getData());
	} else {
		if (((TransactionNode *)pTree)->getUnits() > newNode.getUnits()) { //go left
			if (pTree->getLeft() == nullptr) {
				pTree->setLeft(new TransactionNode(newNode.getUnits(), newNode.getData()));
			} else {
				insert(newNode, pTree->getLeft());
			}
		}
		if (((TransactionNode *)pTree)->getUnits() < newNode.getUnits()) { //go right
			if (pTree->getRight() == nullptr) {
				pTree->setRight(new TransactionNode(newNode.getUnits(), newNode.getData()));
			} else {
				insert(newNode, pTree->getRight());
			}
		}
	}
}
void BST::inOrderTraversal() {
	inOrderTraversal(mpRoot);
}

void BST::inOrderTraversal(Node* pTree) {
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeft());
		pTree->printData();
		inOrderTraversal(pTree->getRight());
	}
}

Node* BST::getRoot() {
	return mpRoot;
}